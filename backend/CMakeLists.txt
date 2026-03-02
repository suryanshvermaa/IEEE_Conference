cmake_minimum_required(VERSION 3.15)
project(IEEE_Conference_Backend VERSION 1.0.0)

find_package(Drogon REQUIRED)
find_package(AWSSDK CONFIG REQUIRED)
find_package(jwt-cpp REQUIRED)
find_package(libxcrypt REQUIRED)

add_executable(IEEE_Conference_Backend
    # config
    ./src/config/database.cc 

    # controllers
    ./src/controllers/health.cc
    ./src/controllers/api_v1_users.cc
    ./src/controllers/api_v1_notifications.cc

    # # models
    ./src/models/Users.cc
    ./src/models/Notifications.cc

    # filters
    ./src/filters/CorsFilter.cc
    ./src/filters/AuthFilter.cc

    # services
    ./src/services/S3Service.cc

    # utils
    ./src/utils/token.cc

    # repositories
    ./src/repositories/user.repository.cc
    ./src/repositories/notification.repository.cc

    # main
    ./src/main.cc)

add_executable(createAdmin
./src/utils/token.cc
./scripts/createAdmin.cc)

target_link_libraries(createAdmin PRIVATE
    jwt-cpp::jwt-cpp
    Drogon::Drogon
    libxcrypt::libxcrypt
)

target_link_libraries(IEEE_Conference_Backend PRIVATE
    Drogon::Drogon
    AWS::aws-sdk-cpp-s3
    AWS::aws-sdk-cpp-core
    jwt-cpp::jwt-cpp
    libxcrypt::libxcrypt
)