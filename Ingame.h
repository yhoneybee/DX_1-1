#pragma once
#include "Scene.h"
class Ingame :
    public Scene
{
public:
    Ingame(int type);

    Texture* bg;

    Texture* img;

    ScrollMap* map;

    int type;
    int enemy_count = 30;

    // Scene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

