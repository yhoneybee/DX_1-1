#pragma once
#include "Scene.h"
class ChangeScene :
    public Scene
{
public:
    // Scene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

