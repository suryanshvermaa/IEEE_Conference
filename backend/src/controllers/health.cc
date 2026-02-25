#include "health.h"
#include"../utils/response.hpp"
#include<json/json.h>
#include"../services/S3Service.h"

void health::healthController(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback){
    try
    {
        Json::Value res;
        const std::string key="Resume.pdf";
        res["url"]=getSignedUrl(key);
        callback(Response::success(k200OK,"heathy",res));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        callback(Response::error(k400BadRequest,e.what()));
    }
    
}