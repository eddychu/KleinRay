
#include <Core/Image.h>
#include <Core/Camera.h>
#include <Core/Scene.h>
#include <Geometries/Sphere.h>
#include <Core/Renderer.h>
#include <Geometries/Plane.h>
#include <Core/Mesh.h>
#include <Integrators/PathIntegrator.h>
#include <Integrators/Whitted.h>
void BasicSceneTest()
{
    Lambertian red(glm::vec3(1.0f, 0.0f, 0.0f));
    Lambertian green(glm::vec3(0.0f, 1.0f, 0.0f));
    Lambertian blue(glm::vec3(0.0f, 0.0f, 1.0f));
    Lambertian white(glm::vec3(1.0f, 1.0f, 1.0f));



    Scene scene;

    Sphere sphere1(glm::vec3(0.0f, 0.0f, 0.0f), 1.0f);
    Node node1(&sphere1, &red);
    scene.nodes.push_back(&node1);
//
    Sphere sphere2(glm::vec3(1.5, -0.5f, 1.0), 0.5f);
    Node node2(&sphere2, &green);
    scene.nodes.push_back(&node2);
//
    Sphere sphere3(glm::vec3(-1.5, -0.5f, 1.0), 0.5f);
    Node node3(&sphere3, &blue);
    scene.nodes.push_back(&node3);
//
    Plane plane(glm::vec3(0, 1, 0), -1.0);
    Node node4(&plane, &white);
    scene.nodes.push_back(&node4);

    PointLight light(glm::vec3(0, 2, 1), glm::vec3(1, 1, 1));
    scene.lights.push_back(&light);

//    PointLight light2(glm::vec3(-2, 0, 1), glm::vec3(1, 1, 1));
//    scene.lights.push_back(&light2);

    Renderer renderer(800, 600, 32, 1);
    Camera camera(
        glm::vec3(0, 0, 6.0),
        glm::vec3(0, 0, 0.0),
        glm::vec3(0, 1, 0),
        glm::radians(60.0f));

    WhittedIntegrator integrator;

    renderer.render(scene, camera, &integrator, "basic.png");
}


//void cornellScene() {
//    Camera camera(
//            glm::vec3(278, 273, -800),
//            glm::vec3(278, 273, 0),
//            glm::vec3(0, 1, 0),
//            glm::radians(40.0f));
//
//    Renderer renderer(800, 600, 32, 64);
//    PathIntegrator integrator;
//
//    Lambertian red(glm::vec3(0.65f, 0.05f, 0.05f));
//    Lambertian white(glm::vec3(0.73f, 0.73f, 0.73f));
//    Lambertian green(glm::vec3(0.12f, 0.45f, 0.15f));
//    Emissive light(glm::vec3(15.0f, 15.0f, 15.0f));
//
//    // red wall
//    Mesh wall1;
//    wall1.vertices = {
//            {552.8f, 0.0f, 0.0f},
//            {549.6f, 0.0f, 559.2f},
//            {556.0f, 548.8f, 559.2f},
//            {556.0f, 548.8f, 0.0f}
//    };
//    wall1.indices = {
//           0, 1, 2, 2, 3, 0
//    };
//
//    Node redWall(&wall1, &red);
//
//    // green wall
//    Mesh wall2;
//    wall2.vertices = {
//            {0.0f, 0.0f, 559.2f},
//            {0.0,   0.0,   0.0},
//            {0.0f, 548.8f, 0.0f},
//            {0.0f, 548.8f, 559.2f}
//    };
//    wall2.indices = {
//            0, 1, 2, 2, 3, 0
//    };
//
//    Node greenWall(&wall2, &green);
//
//    // floor
//    Mesh floor;
//    floor.vertices = {
//            {552.8f, 0.0f, 0.0f},
//            {0.0f, 0.0f, 0.0f},
//            {0.0f, 0.0f, 559.2f},
//            {549.6f, 0.0f, 559.2f}
//    };
//    floor.indices = {
//            0, 1, 2, 2, 3, 0
//    };
//    Node floorNode(&floor, &white);
//
//    Mesh ceiling;
//    ceiling.vertices = {
//            {556.0f, 548.8f, 0.0f},
//            {556.0f, 548.8f, 559.2f},
//            {0.0f, 548.8f, 559.2f},
//            {0.0f, 548.8f, 0.0f}
//    };
//    ceiling.indices = {
//            0, 1, 2, 2, 3, 0
//    };
//
//    Node ceilingNode(&ceiling, &white);
//
//    // back wall
//    Mesh backWall;
//    backWall.vertices = {
//            {549.6f, 0.0f, 559.2f},
//            {0.0f, 0.0f, 559.2f},
//            {0.0f, 548.8f, 559.2f},
//            {556.0f, 548.8f, 559.2f}
//    };
//    backWall.indices = {
//            0, 1, 2, 2, 3, 0
//    };
//
//    Node backWallNode(&backWall, &white);
//
//    // light
//    Mesh lightMesh;
//    lightMesh.vertices = {
//            {343.0f, 548.7f, 227.0f},
//            {343.0f, 548.7f, 332.0f},
//            {213.0f, 548.7f, 332.0f},
//            {213.0f, 548.7f, 227.0f}
//    };
//    lightMesh.indices = {
//            0, 1, 2, 2, 3, 0
//    };
//    Node lightNode(&lightMesh, &light);
//
//
//
//    Scene scene;
//    scene.nodes.push_back(&redWall);
//    scene.nodes.push_back(&greenWall);
//    scene.nodes.push_back(&floorNode);
//    scene.nodes.push_back(&ceilingNode);
//    scene.nodes.push_back(&backWallNode);
//    scene.nodes.push_back(&lightNode);
//
//    renderer.render(scene, camera, &integrator, "cornell.png");
//}

int main()
{
    BasicSceneTest();
    // cornellScene();
    return 0;
}
