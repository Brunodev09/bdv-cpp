#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "EntityManager.h"
#include <glm/glm.hpp>

class Transform : public Component {
public:
    glm::vec2 position;
    glm::vec2 velocity;
    int width;
    int height;
    int scale;

    Transform(int pX, int pY, int vX, int vY, int w, int h, int s) {
        position = glm::vec2(pX, pY);
        velocity = glm::vec2(vX, vY);
        width = w;
        height = h;
        scale = s;
    }

    void Init() override {

    }

    void Update(float deltaTime) override {
        position.x += velocity.x * deltaTime;
        position.y += velocity.y * deltaTime;
    }

};


#endif