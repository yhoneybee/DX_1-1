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
			Enemy* enemy = new Enemy(RANDOM->INT(1, 2));
			OBJ->Add(enemy, "enemy")->pos = { (float)RANDOM->INT(0, WINX), (float)RANDOM->INT(0, WINY) };
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
		switch (type)
		{
		case 1:
			OBJ->Find("boss")->hp = 0;
			break;
		case 2:
			OBJ->Find("boss")->hp = 0;
			break;
		}
	}
}

void Ingame::Render()
{
}

void Ingame::Release()
{
}
