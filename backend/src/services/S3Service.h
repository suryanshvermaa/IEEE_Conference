#include<aws/s3/S3Client.h>
#include<aws/s3/model/GetObjectRequest.h>
#include<aws/s3/model/GetObjectResult.h>

std::string getSignedUrl(const std::string& key);