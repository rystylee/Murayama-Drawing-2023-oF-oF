#pragma once

#include <vector>
#include <memory>

#include "scenes/BaseScene.h"

class SceneManager
{
public:
    SceneManager()
        : _index(0)
    {}
    
    void init()
    {
        for (auto& Scene : _scenes)
        {
            Scene->init();
        }
        _scenes[0]->start();
    }
    
    void update()
    {
        _scenes[_index]->update();
    }
    
    void renderScene(const glm::vec2& p, const float w, const float h)
    {
        _scenes[_index]->renderScene(p, w, h);
    }
    
    void renderGui()
    {
        _scenes[_index]->renderGui();
    }
    
    //void keyPressed(int key)
    //{
    //    _scenes[_index]->keyPressed(key);
    //}

    void changeScene(const int index)
    {
        if (index > _scenes.size() - 1)
            return;

        stop();
        _index = index;
        start();
    }

    template<typename T>
    void addScene(const glm::vec2& resolution)
    {
        _scenes.emplace_back(std::make_unique<T>(resolution));
    }

    const int getSceneIndex() const { return _index; }

private:
    void start()
    {
        _scenes[_index]->start();
    }
    
    void stop()
    {
        _scenes[_index]->stop();
    }

    std::vector<std::unique_ptr<BaseScene>> _scenes;
    int _index;

};
