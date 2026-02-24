cmake_minimum_required(VERSION 3.15)
project(IEEE_Conference_Backend VERSION 1.0.0)

find_package(Drogon REQUIRED)

add_executable(IEEE_Conference_Backend
    ./src/config/database.cc 
    ./src/controllers/health.cc
    ./src/main.cc)

target_link_libraries(IEEE_Conference_Backend Drogon::Drogon)