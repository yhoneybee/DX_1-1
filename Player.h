#pragma once
#include "Obj.h"
class Player :
    public Obj
{
public:
    Texture* img;
    Texture* bg;
    Timer* during;
    Obj* boss;
    V2 start;
    V2 last;

    enum class KeyState
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
    };

    KeyState key;

    static int cell[CELLSIZE][CELLSIZE];
    static float coloring_per;

    int total_cell = pow(CELLSIZE, 2);
    int coloring_cells = 0;
    int temp = 0;
    int spin_force = 0;
    int def = 0;

    float rot;

    bool draw_mode = false;
    bool no_damage = false;

    void SetUp();
    void DrawLine();
    // 0 normal, 1 filled, 2 cancel
    void DrawArea(int draw_flag = 0);
    bool FloodFill(V2 pos, int target, int change);
    void AutoFill();
    void AddItem();
    void NoDamage();
    bool Near(KeyState dir, int target);
    int  Current();

    // Obj을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void Enter(Col* p) override;
    virtual void Stay(Col* p) override;
    virtual void Exit(Col* p) override;
};

