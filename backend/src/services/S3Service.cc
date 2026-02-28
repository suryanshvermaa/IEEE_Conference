#include "../config/aws_config.h"
#include "S3Service.h"

#include <stdexcept>

static std::string requireBucket()
{
    const auto storage = AwsConfig::load();
    if (storage.bucket.empty())
    {
        throw std::runtime_error(
            "S3_BUCKET is not set (or .env was not loaded before S3Service was used)"
        );
    }
    return storage.bucket;
}

/**
 * @details Generates a pre-signed URL for the specified S3 object key. The URL is valid for 1 hour (3600 seconds).
 */
std::string getSignedUrl(const std::string& key){
    const auto bucket = requireBucket();
    Aws::S3::S3Client client(
        AwsConfig::credentials(),
        AwsConfig::clientConfig(),
        Aws::Client::AWSAuthV4Signer::PayloadSigningPolicy::Never,
        false
    );
    return client.GeneratePresignedUrl(bucket, key, Aws::Http::HttpMethod::HTTP_GET, 3600);
}

/**
 * @details Generates a pre-signed URL for uploading an object to the specified S3 bucket with the given key. The URL is valid for 1 hour (3600 seconds).
 */
std::string putObjectSignedUrl(const std::string& key){
    const auto bucket = requireBucket();
    Aws::S3::S3Client client(
        AwsConfig::credentials(),
        AwsConfig::clientConfig(),
        Aws::Client::AWSAuthV4Signer::PayloadSigningPolicy::Never,
        false
    );
    return client.GeneratePresignedUrl(bucket, key, Aws::Http::HttpMethod::HTTP_PUT, 3600);
}

/**
 * @details Deletes the specified object from the S3 bucket.
 */
bool deleteObject(const std::string& key){
    const auto bucket = requireBucket();
    Aws::S3::Model::DeleteObjectRequest request;
    Aws::S3::S3Client client(
        AwsConfig::credentials(),
        AwsConfig::clientConfig(),
        Aws::Client::AWSAuthV4Signer::PayloadSigningPolicy::Never,
        false
    );
    request.SetBucket(bucket);
    request.SetKey(key);

    auto outcome = client.DeleteObject(request);
    if (!outcome.IsSuccess()) {
        throw std::runtime_error("Failed to delete object: " + outcome.GetError().GetMessage());
    }

    return true;
}