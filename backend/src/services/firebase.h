#pragma once

#include <string>
#include <optional>
#include <unordered_map>
#include <mutex>
#include <chrono>

struct FirebaseData {
    std::string uid;
    std::string email;
    std::string provider;
};

class Firebase {
public:
    static Firebase& getInstance();

    std::optional<FirebaseData>
    decodeAndVerifyFirebaseToken(const std::string& token);

private:
    Firebase() = default;

    void refreshKeys();
    std::string getPublicKey(const std::string& kid);

    std::unordered_map<std::string, std::string> keys;
    std::chrono::system_clock::time_point expiry;
    std::mutex mtx;
};