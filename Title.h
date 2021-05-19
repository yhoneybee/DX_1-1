#pragma once
#include "Scene.h"

class Title :
    public Scene
{
public:
    Title(int type);

    Texture* bg;

    Texture* bolt;
    float bolt_rot;
    V2 bolt_pos;
    V2 bolt_end_pos;

    Timer* delay_up;
    bool up;

    bool is_pos_end = false;

    Texture* title;
    V2 title_pos;
    V2 title_end_pos;

    vector<Texture*> anim;
    Timer* delay;
    int index = 0;

    Button* start;
    Button* option;
    Button* exit;

    int type;

    // Scene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};
