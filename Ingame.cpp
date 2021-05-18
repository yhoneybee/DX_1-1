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
}

void Ingame::Render()
{
}

void Ingame::Release()
{
}
