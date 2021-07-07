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
	SOUND->volume = -1500;
	SOUND->Add("BGM", L"BGM")->Play(true);

	CAM->pos = CENTER;
	CAM->scale = { 1,1,1 };

	OBJ->Add(new Mouse, "Mouse");

	OBJ->Add(new Enemy(5 + type), "boss")->pos = CENTER;

	switch (type)
	{
	case 1:
		Player::coloring_per = 0;
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
		for (size_t i = 0; i < enemy_count; i++)
		{
			Enemy* enemy = new Enemy(UTILL->INT(3, 5));
			OBJ->Add(enemy, "enemy")->pos = { (float)UTILL->INT(0, WINX), (float)UTILL->INT(0, WINY) };
			enemys.emplace_back(enemy);
		}
	case 3:
		Player::coloring_per = 0;
		for (size_t i = 0; i < enemy_count * 2; i++)
		{
			Enemy* enemy = new Enemy(UTILL->INT(1, 5));
			OBJ->Add(enemy, "enemy")->pos = { (float)UTILL->INT(0, WINX), (float)UTILL->INT(0, WINY) };
			enemys.emplace_back(enemy);
		}
		break;
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
