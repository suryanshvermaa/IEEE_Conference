#include "api_v1_users.h"
#include <json/json.h>
#include "../utils/token.hpp"
#include "../utils/response.hpp"
#include "../utils/AppError.hpp"
#include "../repositories/user.repository.hpp"

using namespace api::v1;

void users::login(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback){
    try
    {
        auto reqBody=req->getJsonObject();
        if(!reqBody || !reqBody->isMember("email") || !reqBody->isMember("password"))
            throw AppError("Email and password are required", k400BadRequest);
        const std::string email=(*reqBody)["email"].asString();
        const std::string password=(*reqBody)["password"].asString();
        user u=UserRepository::getUserByEmail(email);
        if(u.id == 0)
            throw AppError("User not found", k404NotFound);
        
        if(!Auth::comparePassword(password,u.passwordHash))
            throw AppError("Invalid password", k400BadRequest);

        Json::Value response;
        response["token"] = Auth::createToken(u.id,u.role);
        response["user_id"] = u.id;
        response["name"] = u.name;
        response["email"] = u.email;
        callback(Response::success(k200OK,"Login successful",response));
    }
    catch(const AppError& e)
    {
        LOG_ERROR << e.what();
        callback(Response::error(e.statusCode, e.what()));
    }
    catch(const std::exception& e)
    {
        LOG_ERROR << e.what();
        callback(Response::error(k400BadRequest, "Invalid request"));
    }   
}

void users::signup(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback){
    try
    {
        auto reqBody=req->getJsonObject();
        if(!reqBody || !reqBody->isMember("name") || !reqBody->isMember("email") || !reqBody->isMember("password"))
            throw AppError("Name, email and password are required", k400BadRequest);
        const std::string name=(*reqBody)["name"].asString();
        const std::string email=(*reqBody)["email"].asString();
        const std::string password=(*reqBody)["password"].asString();
        if(UserRepository::getUserByEmail(email).id != 0)
            throw AppError("Email already in use", k400BadRequest);
        
        user u;
        u.name=name;
        u.email=email;
        u.passwordHash=Auth::getHashPassword(password);
        u.role="user";
        int userId=UserRepository::createUser(u);
        if(userId==0)
            throw AppError("Failed to create user", k500InternalServerError);
        
        Json::Value response;
        response["token"] = Auth::createToken(userId,u.role);
        response["user_id"] = userId;
        response["name"] = name;
        response["email"] = email;
        callback(Response::success(k201Created,"Signup successful",response));
    }
    catch(const AppError& e)
    {
        LOG_ERROR << e.what();
        callback(Response::error(e.statusCode, e.what()));
    }
    catch(const std::exception& e)
    {
        LOG_ERROR << e.what();
        callback(Response::error(k400BadRequest, "Invalid request"));
    }   
}

void users::getUsers(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback){
    try
    {
        auto query=req->getParameters();
        int page=1;
        int limit=10;
        if(query.find("page")!=query.end())
            page=std::stoi(query["page"]);
        if(query.find("limit")!=query.end())
            limit=std::stoi(query["limit"]);
        if(limit>=20||limit<=0)
            throw AppError("Limit must be between 1 and 20", k400BadRequest);
        
        std::vector<user> users=UserRepository::getUsers(page,limit);
        Json::Value response(Json::arrayValue);
        for(const auto& u:users){
            Json::Value userJson;
            userJson["id"]=u.id;
            userJson["name"]=u.name;
            userJson["email"]=u.email;
            userJson["role"]=u.role;
            response.append(userJson);
        }
        callback(Response::success(k200OK,"Users retrieved successfully",response));
    }
    catch(const AppError& e)
    {
        LOG_ERROR << e.what();
        callback(Response::error(e.statusCode, e.what()));
    }
    catch(const std::exception& e)
    {
        LOG_ERROR << e.what();
        callback(Response::error(k400BadRequest, "Invalid request"));
    }   
}

void users::getUser(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback){
    try
    {
        auto query=req->getParameters();
        if(query.find("id")==query.end())
            throw AppError("User ID is required", k400BadRequest);
        int id=std::stoi(query["id"]);
        user u=UserRepository::getUser(id);
        if(u.id == 0)
            throw AppError("User not found", k404NotFound);
        
        Json::Value response;
        response["id"]=u.id;
        response["name"]=u.name;
        response["email"]=u.email;
        response["role"]=u.role;
        callback(Response::success(k200OK,"User retrieved successfully",response));
    }
    catch(const AppError& e)
    {
        LOG_ERROR << e.what();
        callback(Response::error(e.statusCode, e.what()));
    }
    catch(const std::exception& e)
    {
        LOG_ERROR << e.what();
        callback(Response::error(k400BadRequest, "Invalid request"));
    }   
}

void users::updateUser(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback){
    try
    {
        auto id=req->getParameter("id");
        if(id.empty())
            throw AppError("User ID is required", k400BadRequest);
        int userId=std::stoi(id);
        auto reqBody=req->getJsonObject();
        if(reqBody==nullptr)
            throw AppError("Invalid request body", k400BadRequest);
        
        user u;
        u.id=userId;
        if(reqBody->isMember("name"))
            u.name=(*reqBody)["name"].asString();
        if(reqBody->isMember("email"))
            u.email=(*reqBody)["email"].asString();
        if(reqBody->isMember("password"))
            u.passwordHash=Auth::getHashPassword((*reqBody)["password"].asString());
        if(reqBody->isMember("role"))
            u.role=(*reqBody)["role"].asString();
        
        if(!UserRepository::updateUser(userId,u))
            throw AppError("Failed to update user", k500InternalServerError);
        
        callback(Response::success(k200OK,"User updated successfully"));
    }
    catch(const AppError& e)
    {
        LOG_ERROR << e.what();
        callback(Response::error(e.statusCode, e.what()));
    }
    catch(const std::exception& e)
    {
        LOG_ERROR << e.what();
        callback(Response::error(k400BadRequest, "Invalid request"));
    }    
}


void users::deleteUserByAdmin(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int id){
    try
    {
        if(!UserRepository::deleteUser(id))
            throw AppError("User not found or already deleted", k404NotFound);
        
        callback(Response::success(k200OK,"User deleted successfully"));
    }
    catch(const AppError& e)
    {
        LOG_ERROR << e.what();
        callback(Response::error(e.statusCode, e.what()));
    }
    catch(const std::exception& e)
    {
        LOG_ERROR << e.what();
        callback(Response::error(k400BadRequest, "Invalid request"));
    }    
}
