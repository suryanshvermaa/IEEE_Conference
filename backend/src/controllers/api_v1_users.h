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
    // METHOD_ADD(users::your_method_name, "/{1}/{2}/list", Get); // path is /api/v1/users/{arg1}/{arg2}/list
    // ADD_METHOD_TO(users::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list

    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    void login(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;
};
}
}
