#pragma once
#include "Scene.h"
class Title :
    public Scene
{
public:
    Title(int type);

    Texture* bg;

    vector<Texture*> anim;
    Timer* delay;
    int index = 0;

    Button* start;
    Button* credit;
    Button* end;

    Window* win_credit;
    ScrollMap* map;

    int type;

    // Scene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

