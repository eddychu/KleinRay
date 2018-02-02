
#include "Core/Image.h"
#include "Core/Camera.h"
#include "Core/Scene.h"
#include "Geometries/Sphere.h"
#include "Core/Renderer.h"
#include "Geometries/Plane.h"
#include "Core/Material.h"
#include <Lights/PointLight.h>
void BasicSceneTest() {
    Material red(glm::vec3(1.0f, 0.0f, 0.0f));
    Material green(glm::vec3(0.0f, 1.0f, 0.0f));
    Material blue(glm::vec3(0.0f, 0.0f, 1.0f));
    Material white(glm::vec3(1.0f, 1.0f, 1.0f));

    Scene scene;


    Sphere sphere1(glm::vec3(0.0f, 0.0f, 0.0f), 1.0f);
    Node node1(&sphere1, &red);
    scene.nodes.push_back(&node1);

    Sphere sphere2(glm::vec3(1.5, -0.5, 1.0), 0.5f);
    Node node2(&sphere2, &green);
    scene.nodes.push_back(&node2);

    Sphere sphere3(glm::vec3(-1.5, -0.5, 1.0), 0.5f);
    Node node3(&sphere3, &blue);
    scene.nodes.push_back(&node3);

    Plane plane(glm::vec3(0, 1, 0), -1.0);
    Node node4(&plane, &white);
    scene.nodes.push_back(&node4);

    PointLight light(glm::vec3(0, 2, 3), glm::vec3(10.0f, 10.0f, 10.0f));
    scene.lights.push_back(&light);

    Renderer renderer(800, 600, 1, 1);
    Camera camera(
            glm::vec3(0, 0, 6.0),
            glm::vec3(0, 0, 0.0),
            glm::vec3(0, 1, 0),
            glm::radians(60.0f)
            );
    renderer.render(scene, camera, "basic.png");
}



int main() {
    BasicSceneTest();
    return 0;
}
