#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace api
{
namespace v1
{
class auth : public drogon::HttpController<auth>
{
  public:
    METHOD_LIST_BEGIN
    METHOD_ADD(auth::login, "/login", Post); // path -> /api/v1/auth/login
    METHOD_ADD(auth::signup, "/signup", Post); // path -> /api/v1/auth/signup
    METHOD_ADD(auth::firebaseLogin, "/firebase/login", Post); // path -> /api/v1/auth/firebase/login
    METHOD_ADD(auth::firebaseSignup, "/firebase/signup", Post); // path -> /api/v1/auth/firebase/signup

    METHOD_LIST_END
    void login(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void signup(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void firebaseLogin(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
    void firebaseSignup(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
};
}
}
