#pragma once
#include "Obj.h"
class MiniMap :
    public Obj
{
public:
    MiniMap();

    Obj* player;
    Obj* target;

    Texture* minimap;
    Texture* minimap_bg;

    D3DXCOLOR* minimap_color;

    // Obj��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void Enter(Col* p) override;
    virtual void Stay(Col* p) override;
    virtual void Exit(Col* p) override;
};

