/**
 *
 *  AuthFilter.cc
 *
 */

#include "AuthFilter.h"
#include "../utils/token.hpp"

using namespace drogon;

void AuthFilter::doFilter(const HttpRequestPtr &req,
                         FilterCallback &&fcb,
                         FilterChainCallback &&fccb)
{
    auto bearerToken=req->getHeader("Authorization");
    std::string tokenPrefix="Bearer ";
    const std::string token=bearerToken.substr(tokenPrefix.size());
    data decodedData=Auth::decodeAndverifyToken(token);

    if (decodedData.userId>0)
    {
        req->setParameter("userId",std::to_string(decodedData.userId));
        req->setParameter("role",decodedData.role);
        fccb();
        return;
    }
    //Check failed
    auto res = drogon::HttpResponse::newHttpResponse();
    res->setStatusCode(k500InternalServerError);
    fcb(res);
}
