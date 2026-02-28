#include "api_v1_users.h"
#include <json/json.h>
#include "../utils/token.hpp"
#include "../utils/response.hpp"
#include "../utils/AppError.hpp"
#include "../repositories/user.repository.hpp"

using namespace api::v1;

/**
 * @details login route /api/v1/users/login
 */
void users::login(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback){
    try
    {
        auto reqBody=req->getJsonObject();
        if(!reqBody || !reqBody->isMember("email") || !reqBody->isMember("password"))
            throw AppError("Email and password are required", k400BadRequest);
        const std::string email=(*reqBody)["email"].asString();
        const std::string password=(*reqBody)["password"].asString();
        const std::string hashedPassword=Auth::getHashPassword(password);
        user u;
        u.name=email;
        u.email=email;
        u.passwordHash=hashedPassword;
        u.role="admin";
        int id=UserRepository::createUser(u);
        Json::Value response;
        auto token=Auth::createToken(id,u.role);
        response["token"] = token;
        response["user_id"] = id;
        callback(Response::success(k200OK,"Login successful",response));
    }
    catch(const AppError& e)
    {
        callback(Response::error(e.statusCode, e.what()));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        callback(Response::error(k400BadRequest, "Invalid request"));
    }
    
}