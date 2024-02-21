#pragma once

#include "ofMain.h"

class Quad
{
public:
    Quad()
    {
        _mesh.addVertex(glm::vec3(-0.5, 0.5, 0.0)); // left top
        _mesh.addVertex(glm::vec3(0.5, 0.5, 0.0)); // right top
        _mesh.addVertex(glm::vec3(-0.5, -0.5, 0.0)); // left bottom
        _mesh.addVertex(glm::vec3(0.5, -0.5, 0.0)); // right bottom

        _mesh.addTexCoord(glm::vec2(0.0, 1.0));
        _mesh.addTexCoord(glm::vec2(1.0, 1.0));
        _mesh.addTexCoord(glm::vec2(0.0, 0.0));
        _mesh.addTexCoord(glm::vec2(1.0, 0.0));

        _mesh.addIndex(0);
        _mesh.addIndex(1);
        _mesh.addIndex(2);
        _mesh.addIndex(1);
        _mesh.addIndex(3);
        _mesh.addIndex(2);
    }

    void render(const glm::vec3& pos, const glm::vec3& scale)
    {
        ofPushMatrix();
        {
            ofTranslate(pos);
            ofScale(scale);
            _mesh.draw();
        }
        ofPopMatrix();
    }

    void render(const glm::vec2& pos, const glm::vec2& scale)
    {
        ofPushMatrix();
        {
            ofTranslate(pos + scale * 0.5);
            ofScale(scale.x, scale.y, 1.0);
            _mesh.draw();
        }
        ofPopMatrix();
    }

    void render(const glm::vec3& pos, const float w, const float h)
    {
        render(pos, glm::vec2(w, h));
    }

    void render(const glm::vec2& pos, const float w, const float h)
    {
        render(pos, glm::vec2(w, h));
    }

    void renderCenter(const glm::vec2& pos, const glm::vec2& scale)
    {
        ofPushMatrix();
        {
            ofTranslate(pos);
            ofScale(scale.x, scale.y, 1.0);
            _mesh.draw();
        }
        ofPopMatrix();
    }

    void renderCenter(const glm::vec2& pos, const float w, const float h)
    {
        renderCenter(pos, glm::vec2(w, h));
    }

private:
    ofVboMesh _mesh;

};
