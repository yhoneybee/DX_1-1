#pragma once
#pragma once
#include "Obj.h"
class Player :
    public Obj
{
public:
    Texture* img;
    Texture* bg;
    Texture* bg_lower;
    Timer* during;
    Anim* idle;
    Obj* boss;
    V2 start;
    V2 temp_pos;
    V2 dir;

    enum class KeyState
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
    };

    KeyState key;

    static int cell[CELLSIZE_X][CELLSIZE_Y];
    static float coloring_per;

    D3DXCOLOR bg_color[CELLSIZE_X][CELLSIZE_Y];

    int total_cell = CELLSIZE_X * CELLSIZE_Y;
    int coloring_cells = 0;
    int temp = 0;
    int spin_force = 0;
    int def = 0;

    float rot;

    float time = 100;

    bool draw_mode = false;
    bool no_damage = false;

    bool drawing = false;

    void SetUp();

    void DrawLine();

    // 0 normal, 1 filled, 2 cancel
    void DrawArea(int draw_flag = 0);

    // 0 OK, 1 T == C, 2 CELL != T, 3 OUT OF RANGE, 4 BOSS
    int FloodFill(V2 pos, int target, int change);
    void AutoFill();
    void AddItem();
    void NoDamage();
    bool Near(KeyState dir, int target);
    int  Current();

    //void little_sleep(milliseconds us);
    //void Flash(V2 v2);

    Gun* gun;

    int Nums(int num, int index);

    int title_a;

    // Obj을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void Enter(Col* p) override;
    virtual void Stay(Col* p) override;
    virtual void Exit(Col* p) override;
};