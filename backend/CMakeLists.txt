cmake_minimum_required(VERSION 3.15)
project(IEEE_Conference_Backend VERSION 1.0.0)

find_package(Drogon REQUIRED)

add_executable(IEEE_Conference_Backend
    # config
    ./src/config/database.cc 

    # controllers
    ./src/controllers/health.cc

    # models
    ./src/models/Users.cc

    # filters
    ./src/filters/CorsFilter.cc
    ./src/filters/AuthFilter.cc

    # main
    ./src/main.cc)

target_link_libraries(IEEE_Conference_Backend Drogon::Drogon)