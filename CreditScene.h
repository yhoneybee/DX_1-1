#pragma once
#include "Scene.h"
class CreditScene :
    public Scene
{
public:
    Button* back;

    // Scene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

