#pragma once
#include "Obj.h"
class ChangeEffect :
    public Obj
{
public:
    ChangeEffect(const string& scene_name)
        :go_scene_name(scene_name) {}

    string go_scene_name;

    // Obj을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void Enter(Col* p) override;
    virtual void Stay(Col* p) override;
    virtual void Exit(Col* p) override;
};

