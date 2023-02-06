cmake_minimum_required(VERSION 3.24)
project(KleinRay)

set(CMAKE_CXX_STANDARD 20)

add_executable(KleinRay main.cpp Source/Core/Image.cpp Source/Core/Image.h Source/Core/Camera.cpp Source/Core/Camera.h Source/Core/Transform.cpp Source/Core/Transform.h Source/Core/Ray.h Source/Core/Mesh.cpp Source/Core/Mesh.h Source/Core/Scene.cpp Source/Core/Scene.h Source/Core/Hittable.h Source/Geometries/Sphere.cpp Source/Geometries/Sphere.h Source/Core/Renderer.cpp Source/Core/Renderer.h Source/Geometries/Plane.cpp Source/Geometries/Plane.h Source/Core/Material.h Source/Core/Node.cpp Source/Core/Node.h  Source/Core/Sampling.h Source/Core/Integrator.h Source/Integrators/PathIntegrator.cpp Source/Integrators/PathIntegrator.h Source/Core/Light.cpp Source/Core/Light.h Source/Integrators/Whitted.cpp Source/Integrators/Whitted.h)


find_package(glm CONFIG REQUIRED)
target_link_libraries(KleinRay PRIVATE glm::glm)


find_path(STB_INCLUDE_DIRS "stb_c_lexer.h")
target_include_directories(KleinRay  PRIVATE ${STB_INCLUDE_DIRS})

find_path(TINYGLTF_INCLUDE_DIRS "tiny_gltf.h")
target_include_directories(KleinRay PRIVATE ${TINYGLTF_INCLUDE_DIRS})

target_include_directories(KleinRay PRIVATE Source)