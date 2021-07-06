#pragma once
#include "Scene.h"
class ChangeScene :
    public Scene
{
public:
    ChangeScene(const string& scene_name)
        :go_scene_name(scene_name) {}

    string go_scene_name;

    // Scene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

