#include "DXUT.h"
#include "Ingame.h"

extern int score;

Ingame::Ingame(int type)
	:bg(), map(), type(type)
{
}

void Ingame::Init()
{
	OBJ->Add(new Mouse, "Mouse");

	map = new ScrollMap(IMG->Add("Bg", "Bg"));

	switch (type)
	{
	case 1:
		Player::coloring_per = 0;
		OBJ->Add(new Enemy(7), "boss")->pos = CENTER;
		score = 0;
		break;
	case 2:
		Player::coloring_per = 0;
		OBJ->Add(new Enemy(8), "boss")->pos = CENTER;
	}
	OBJ->Add(new Player, "player")->pos = { CENTER.x,float(B) };

	for (size_t i = 0; i < enemy_count; i++)
		OBJ->Add(new Enemy(RANDOM->INT(type * 3 - 2, type * 3)), "Enemy")->pos = { float(RANDOM->INT(L + 1, R - 1)),float(RANDOM->INT(T + 1,B - 1)) };
}

void Ingame::Update()
{
	if (Player::coloring_per >= 80)
	{
		switch (type)
		{
		case 1:
			SCENE->Set("stage2");
			break;
		case 2:
			SCENE->Set("clear");
			break;
		}
	}

	if (map)
		map->Update(500);
}

void Ingame::Render()
{
	if (map)
		map->Render();
	bg->Render();
}

void Ingame::Release()
{
	SAFE_DELETE(map);
}
