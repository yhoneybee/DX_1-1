#pragma once
#include "Scene.h"
class CreditScene :
    public Scene
{
public:
    Button* back;

    // Scene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

