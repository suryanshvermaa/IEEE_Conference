/**
 *
 *  CorsFilter.cc
 *
 */

#include "CorsFilter.h"

using namespace drogon;

void CorsFilter::doFilter(const HttpRequestPtr &req,
                         FilterCallback &&fcb,
                         FilterChainCallback &&fccb)
{   
    if (req->method() == Options) {
        std::cout << "CORS preflight OPTIONS request caught" << std::endl;
        auto resp = HttpResponse::newHttpResponse();
        resp->addHeader("Access-Control-Allow-Origin", "*");
        resp->addHeader("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
        resp->addHeader("Access-Control-Allow-Headers", "*");
        resp->addHeader("Access-Control-Max-Age", "86400");
        resp->setStatusCode(k200OK);
        fcb(resp);
        return;
    }
    req->attributes()->insert("CorsMatched", true); // optional debugging
    fccb();
}
