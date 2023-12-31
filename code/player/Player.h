#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "models/Model.h"

enum Direction {
    Forward,
    Back,
    Left,
    Right
};

class Player: public Model {
public:

    static Player *getInstance(const char *model_path, int SCR_WIDTH, int SCR_HEIGHT, unsigned int depthMap);
    static void DestroyInstance();

    void render(Shader *shader, glm::vec3 lightPos, bool renderShadow = true);

    void setView(glm::mat4 _view);
    void setModel(glm::mat4 _model);
    void setProjection(glm::mat4 _projection);

    Direction dir;

    glm::vec3 position;

private:
    Player(const char *model_path, int SCR_WIDTH, int SCR_HEIGHT, unsigned int depthMap);
     
    static Player *m_player;

    glm::mat4 projection, view, model;

    unsigned int depthMap;
};

