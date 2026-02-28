#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace api
{
namespace v1
{
class users : public drogon::HttpController<users>
{
  public:
    METHOD_LIST_BEGIN
    
    METHOD_ADD(users::login, "/login", Post); // path -> /api/v1/users/login
    METHOD_ADD(users::signup, "/signup", Post); // path -> /api/v1/users/signup
    METHOD_ADD(users::getUsers, "", Get); // path -> /api/v1/users/users?page={page}&limit={limit}
    METHOD_ADD(users::getUser, "/profile", Get); // path -> /api/v1/users?id={id}
    METHOD_ADD(users::updateUser, "", Put,"AuthFilter"); // path -> /api/v1/users/{id}
    METHOD_ADD(users::deleteUserByAdmin, "/{id}", Delete,"AuthFilter"); // path -> /api/v1/users/{id} -> for admin use only

    METHOD_LIST_END
    void login(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void signup(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void getUsers(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void getUser(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void updateUser(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void deleteUserByAdmin(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int id);
};
}
}
