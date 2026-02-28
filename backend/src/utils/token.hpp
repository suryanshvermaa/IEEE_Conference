#pragma once

#include<iostream>

struct data{
    int userId;
    std::string role;
};
namespace Auth {
    std::string createToken(const int userId,const std::string &role);
    data decodeAndverifyToken(const std::string &token);
}