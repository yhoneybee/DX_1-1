#pragma once
#include "Obj.h"
class Enemy :
    public Obj
{
public:
    Enemy(int type);

    Obj* player;
    vector<Effect*> fxs;
    Texture* img;
    Timer* timer;
    Timer* during;
    Anim* death = nullptr;
    V2 size;
    V2 dir;

    int add_pos = 100;
    bool add = true;
    float cool;
    int type;
    int spin_force;
    bool isAnim = false;

    void Rush();
    void CircleShot(int shots);
    void CrossShot();

    // Obj을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void Enter(Col* p) override;
    virtual void Stay(Col* p) override;
    virtual void Exit(Col* p) override;
};

