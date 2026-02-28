#include"./user.repository.hpp"
#include"../models/Users.h"
#include"../config/database.h"

using namespace drogon_model::ieee_conference_db;
using namespace drogon::orm;

int UserRepository::createUser(const user& u){
    try
    {
        Users user;
        user.setUsername(u.name);
        user.setEmail(u.email);
        user.setPasswordHash(u.passwordHash);
        user.setRole(u.role);
        Mapper<Users> mapper(Database::getClient());
        mapper.insert(user);
        return user.getValueOfId();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
}

std::vector<user> UserRepository::getUsers(int page,int limit){
    try
    {
        std::vector<user> users;
        Mapper<Users> mapper(Database::getClient());
        auto dbUsers=mapper.limit(limit).offset((page-1)*limit).findAll();
        for(const auto& dbUser:dbUsers){
            user u;
            u.id=dbUser.getValueOfId();
            u.name=dbUser.getValueOfUsername();
            u.email=dbUser.getValueOfEmail();
            u.passwordHash=dbUser.getValueOfPasswordHash();
            u.role=dbUser.getValueOfRole();
            users.push_back(u);
        }
        return users;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return {};
    }
}

user UserRepository::getUser(int id){
    try
    {
        Mapper<Users> mapper(Database::getClient());
        auto dbUser=mapper.findByPrimaryKey(id);
        user u;
        u.id=dbUser.getValueOfId();
        u.name=dbUser.getValueOfUsername();
        u.email=dbUser.getValueOfEmail();
        u.passwordHash=dbUser.getValueOfPasswordHash();
        u.role=dbUser.getValueOfRole();
        return u;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return {};
    }
}

bool UserRepository::updateUser(int id,const user& u){
    try
    {
        Mapper<Users> mapper(Database::getClient());
        auto dbUser=mapper.findByPrimaryKey(id);
        dbUser.setUsername(u.name);
        dbUser.setEmail(u.email);
        dbUser.setPasswordHash(u.passwordHash);
        dbUser.setRole(u.role);
        mapper.update(dbUser);
        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

bool UserRepository::deleteUser(int id){
    try
    {
        Mapper<Users> mapper(Database::getClient());
        mapper.deleteByPrimaryKey(id);
        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}