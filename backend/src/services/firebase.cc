#include <jwt-cpp/traits/open-source-parsers-jsoncpp/defaults.h>
#include "firebase.h"
#include <drogon/drogon.h>

using namespace drogon;

Firebase& Firebase::getInstance() {
    static Firebase instance;
    return instance;
}

//////////////////////////////////////////////////////////
// 🔑 PUBLIC KEY FETCH + CACHE
//////////////////////////////////////////////////////////

void Firebase::refreshKeys() {
    auto client = HttpClient::newHttpClient(
        "https://www.googleapis.com");

    auto req = HttpRequest::newHttpRequest();
    req->setPath("/robot/v1/metadata/x509/securetoken@system.gserviceaccount.com");

    auto result = client->sendRequest(req);

    if (result.first != ReqResult::Ok) {
        LOG_ERROR << "Failed to fetch Firebase keys";
        return;
    }

    auto json = result.second->getJsonObject();
    if (!json) return;

    keys.clear();

    for (const auto& key : json->getMemberNames()) {
        keys[key] = (*json)[key].asString();
    }

    expiry = std::chrono::system_clock::now()
             + std::chrono::hours(1);

    LOG_INFO << "Firebase public keys refreshed";
}

std::string Firebase::getPublicKey(const std::string& kid) {
    std::lock_guard<std::mutex> lock(mtx);

    if (std::chrono::system_clock::now() > expiry) {
        refreshKeys();
    }

    if (keys.find(kid) == keys.end()) {
        refreshKeys();
    }

    return keys[kid];
}

//////////////////////////////////////////////////////////
// 🔎 VERIFY FIREBASE TOKEN (USING YOUR STYLE)
//////////////////////////////////////////////////////////

std::optional<FirebaseData>
Firebase::decodeAndVerifyFirebaseToken(const std::string& token)
{
    try {
        const std::string projectId = std::getenv("FIREBASE_PROJECT_ID");

        auto decodedToken = jwt::decode(token);

        const std::string kid =
            decodedToken.get_header_claim("kid").as_string();

        std::string publicKey = getPublicKey(kid);

        if (publicKey.empty())
            return std::nullopt;

        auto verifier = jwt::verify()
            .with_issuer("https://securetoken.google.com/" + projectId)
            .with_audience(projectId)
            .allow_algorithm(jwt::algorithm::rs256(
                publicKey, "", "", ""
            ));

        verifier.verify(decodedToken);

        FirebaseData data;

        data.uid =
            decodedToken.get_payload_claim("user_id").as_string();

        data.email =
            decodedToken.get_payload_claim("email").as_string();

        auto firebaseClaim =
            decodedToken.get_payload_claim("firebase").to_json();

        data.provider =
            firebaseClaim["sign_in_provider"].asString();

        return data;
    }
    catch (const std::exception& e) {
        LOG_ERROR << "Firebase verification failed: "
                  << e.what();
        return std::nullopt;
    }
}