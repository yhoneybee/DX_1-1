#pragma once
#include "Scene.h"
class End :
    public Scene
{
public:
    End(int type);

    Texture* bg;
    ScrollMap* map;

    Button* next;
    Button* restart;
    Button* title;

    bool play_anim;
    int type;

    // Scene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

