#include "health.h"
#include"../utils/response.hpp"
#include<json/json.h>

void health::healthController(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) const{
    try
    {
        callback(Response::success(k200OK,"heathy"));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        callback(Response::error(k400BadRequest,e.what()));
    }
    
}