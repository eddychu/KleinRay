cmake_minimum_required(VERSION 3.24)
project(KleinRay)

set(CMAKE_CXX_STANDARD 20)

add_executable(KleinRay main.cpp Image.cpp Image.h Camera.cpp Camera.h Transform.cpp Transform.h Ray.h)


find_package(glm CONFIG REQUIRED)
target_link_libraries(KleinRay PRIVATE glm::glm)


find_path(STB_INCLUDE_DIRS "stb_c_lexer.h")
target_include_directories(KleinRay  PRIVATE ${STB_INCLUDE_DIRS})