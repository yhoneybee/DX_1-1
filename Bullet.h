#pragma once
#include "Obj.h"
class Bullet :
    public Obj
{
public:
    Bullet(BulletCase gc, V2 dir, bool eatk = false);

    Texture* img;
    vector<Effect*> fxs;
    Timer* delay;
    V2 dir;

    BulletCase gc;
    float speed;
    float rot;

    bool eatk;

    // Obj을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void Enter(Col* p) override;
    virtual void Stay(Col* p) override;
    virtual void Exit(Col* p) override;
};

