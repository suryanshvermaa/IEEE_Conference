#include<drogon/HttpAppFramework.h>
#include"./utils/dotenv.hpp"
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
    app().addListener("0.0.0.0",port);
    std::cout<<"server is listening on port:"<<port<<std::endl;
    app().run();
    return 0;
}