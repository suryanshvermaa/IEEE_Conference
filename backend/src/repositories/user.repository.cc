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