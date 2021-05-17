#pragma once
#include "Obj.h"
class Enemy :
    public Obj
{
public:
    Enemy(int type);

    vector<Effect*> fxs;
    Texture* img;
    Timer* timer;
    Timer* during;
    V2 size;
    V2 dir;

    float cool;
    int type;
    int spin_force;

    vector<float> speeds = vector<float>
    {
        0.5f,
        0.75f,
        1,
        1.25f,
        1.5f,
    };

    void Rush();
    void Shot(int shots);

    // Obj��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void Enter(Col* p) override;
    virtual void Stay(Col* p) override;
    virtual void Exit(Col* p) override;
};

