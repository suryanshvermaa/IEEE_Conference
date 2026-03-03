/**
 *
 *  AdminFilter.cc
 * @details Assumed it will come after AuthFilter
 *
 */

#include "AdminFilter.h"
#include"../utils/response.hpp"

using namespace drogon;

void AdminFilter::doFilter(const HttpRequestPtr &req,
                         FilterCallback &&fcb,
                         FilterChainCallback &&fccb)
{
    auto role=req->getParameter("role");
    if(role=="admin"){
        fccb();
        return;
    }
    auto res = drogon::HttpResponse::newHttpResponse();
    res->setStatusCode(k500InternalServerError);
    fcb(Response::error(k401Unauthorized,"Unauthorized: Invalid token for admin"));
}
