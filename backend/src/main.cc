#include<drogon/HttpAppFramework.h>
#include"./utils/dotenv.hpp"
#include"./config/database.h"
using namespace drogon;

int main(){
    Dotenv::load();
    const char* portEnv=std::getenv("PORT");
    app().loadConfigFile("./config/config.json");
    int port=3000;
    if (portEnv && *portEnv)
    {
        try
        {
            port = std::stoi(std::string(portEnv));
        }
        catch (const std::exception &e)
        {
            std::cerr << "Invalid PORT='" << portEnv << "' (" << e.what() << "); using " << port << "\n";
        }
    }
    else
    {
        std::cerr << "PORT not set (or .env missing); using " << port << "\n";
    }
    auto threads = std::thread::hardware_concurrency();
    app().setThreadNum(threads);
    app().addListener("0.0.0.0",port);
    LOG_INFO << "=================================";
    LOG_INFO << "Starting Drogon Server";
    LOG_INFO << "Threads: " << threads;
    LOG_INFO << "Port: "<<port;
    LOG_INFO << "=================================";
    app().registerBeginningAdvice([]() {
        if (Database::isHealthy())
        {
            LOG_INFO << "Database connected successfully";
        }
        else
        {
            LOG_ERROR << "Database connection failed";
        }
    });
    app().run();
    return 0;
}