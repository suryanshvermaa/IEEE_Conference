#include<jwt-cpp/traits/open-source-parsers-jsoncpp/defaults.h>
#include"./token.hpp"


std::string Auth::createToken(const int userId,const std::string &role){
    std::string token=jwt::create()
    .set_issuer("suryansh")
    .set_type("JWS")
    .set_expires_at(std::chrono::system_clock::now()+std::chrono::hours{24})
    .set_payload_claim("userId",jwt::claim(std::to_string(userId)))
    .set_payload_claim("role",jwt::claim(role))
    .sign(jwt::algorithm::hs256{std::getenv("JWT_SECRET")});

    return token;
}

data Auth::decodeAndverifyToken(const std::string &token){
    try
    {
        auto decodedToken=jwt::decode(token);
        auto verifier = jwt::verify()
        .with_issuer("suryansh")
        .with_type("JWS")
        .allow_algorithm(jwt::algorithm::hs256{std::getenv("JWT_SECRET")});

        verifier.verify(decodedToken);
        const std::string role=decodedToken.get_payload_claim("role").as_string();
        const std::string userId=decodedToken.get_payload_claim("userId").as_string();
        return {std::stoi(userId),role};
    }
    catch(const std::exception& e)
    {
        return {0,""};
    }
}