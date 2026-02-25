#include "../config/aws_config.h"
#include "S3Service.h"

auto storage = AwsConfig::load();

std::string bucket = storage.bucket;

/**
 * @details Generates a pre-signed URL for the specified S3 object key. The URL is valid for 1 hour (3600 seconds).
 */
std::string getSignedUrl(const std::string& key){
    Aws::S3::Model::GetObjectRequest request;
    Aws::S3::S3Client client(
    AwsConfig::credentials(),
    AwsConfig::clientConfig(),
    Aws::Client::AWSAuthV4Signer::PayloadSigningPolicy::Never,
    false
    );
    request.SetBucket(bucket);
    request.SetKey(key);

    auto outcome = client.GetObject(request);
    if (!outcome.IsSuccess()) {
        throw std::runtime_error("Failed to get signed URL: " + outcome.GetError().GetMessage());
    }

    return client.GeneratePresignedUrl(bucket, key, Aws::Http::HttpMethod::HTTP_GET, 3600);
}