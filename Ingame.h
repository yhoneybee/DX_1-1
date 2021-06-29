#pragma once
#include "Scene.h"

class Enemy;

class Ingame :
    public Scene
{
public:
    Ingame(int type);

    Texture* img;

    ScrollMap* map;

    static list<Enemy*> enemys;

    int type;
    int enemy_count = 7;

    // Scene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

