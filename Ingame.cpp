#include "DXUT.h"
#include "Ingame.h"

extern int score;

list<Enemy*> Ingame::enemys;

Ingame::Ingame(int type)
	:map(), type(type)
{
}

void Ingame::Init()
{
	CAM->pos = CENTER;
	CAM->scale = { 1,1,1 };

	OBJ->Add(new Mouse, "Mouse");

	switch (type)
	{
	case 1:
		Player::coloring_per = 0;
		OBJ->Add(new Enemy(7), "boss")->pos = CENTER;
		score = 0;
		for (size_t i = 0; i < enemy_count; i++)
		{
			Enemy* enemy = new Enemy(UTILL->INT(1, 2));
			OBJ->Add(enemy, "enemy")->pos = { (float)UTILL->INT(0, WINX), (float)UTILL->INT(0, WINY) };
			enemys.emplace_back(enemy);
		}
		break;
	case 2:
		Player::coloring_per = 0;
		enemys.clear();
		OBJ->Add(new Enemy(8), "boss")->pos = CENTER;
	}
	OBJ->Add(new Player, "player")->pos = { CENTER.x,float(B) };
}

void Ingame::Update()
{
	if (Player::coloring_per >= 80)
	{
		OBJ->Find("boss")->hp = 0;
	}
}

void Ingame::Render()
{
	IMG->Add("Deep_BG")->Render(CENTER, ZERO, ONE * 1.7);
}

void Ingame::Release()
{
}
