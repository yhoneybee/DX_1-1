#include "DXUT.h"
#include "Enemy.h"

Enemy::Enemy(int type)
	:type(type)
{
}

void Enemy::Rush()
{
	during->Start();
	char str[256];
	sprintf(str, "enemy%d_red", type);
	img = IMG->Add(str);
}

void Enemy::Shot(int shots)
{
	int angle = 360 / shots;
	for (int i = 0; i < 360; i += angle)
		OBJ->Add(new Bullet(1, { cos(D3DXToRadian(i)), sin(D3DXToRadian(i)) }), "Bullet")->pos = pos;
}

void Enemy::Init()
{
	dir = RANDOM->Vec2(pos);
	char str[256];
	sprintf(str, "enemy%d", type);
	img = IMG->Add(str);
	cool = 0;
	speed = 0;
	size = ONE;
	spin_force = 0;
	main_col = new Col(this, EATK);

	switch (type)
	{
	case 1:
		cool = 5;
		speed = speeds[2];
		break;
	case 2:
		speed = speeds[1];
		break;
	case 3:
		speed = speeds[3];
		break;
	case 4:
		cool = 3;
		speed = speeds[3];
		break;
	case 5:
		speed = speeds[4];
		break;
	case 6:
		speed = speeds[0];
		break;
	case 7:
		cool = 10;
		speed = speeds[2];
		break;
	case 8:
		cool = 3;
		speed = speeds[2];
		break;
	}

	timer = TIME->Create(cool);
	timer->Start();
	during = TIME->Create(3);
}

void Enemy::Update()
{
	for (int i = 0; i < speed; i++)
	{
		pos += dir;

		if (pos.x < L)
			RANDOM->Reflex(&dir, V2(-1, 0));
		if (pos.x > R)
			RANDOM->Reflex(&dir, V2(1, 0));
		if (pos.y < T)
			RANDOM->Reflex(&dir, V2(0, -1));
		if (pos.y > B)
			RANDOM->Reflex(&dir, V2(0, 1));

		if (Player::cell[int(pos.x) + 1][int(pos.y)] == 2)
			RANDOM->Reflex(&dir, V2(1, 0));
		if (Player::cell[int(pos.x) - 1][int(pos.y)] == 2)
			RANDOM->Reflex(&dir, V2(-1, 0));
		if (Player::cell[int(pos.x)][int(pos.y) + 1] == 2)
			RANDOM->Reflex(&dir, V2(0, 1));
		if (Player::cell[int(pos.x)][int(pos.y) - 1] == 2)
			RANDOM->Reflex(&dir, V2(0, -1));
	}

	int range = 7;

	switch (type)
	{
	case 1:
	case 4:
		break;
	case 7:
		range = 110;
		if (timer->IsStop())
		{
			Rush();
			timer->Start();
		}
		if (during->IsStop())
		{
			char str[256];
			sprintf(str, "enemy%d", type);
			img = IMG->Add(str);
		}
		else
		{
			pos += dir * 10;
			fxs.emplace_back(new Effect(img, pos, 0, 3));
		}
		break;
	case 8:
		range = 110;
		if (timer->IsStop())
		{
			Shot(36);
			timer->Start();
		}
		break;
	}

	main_col->Set(pos, 16 * size.x, 16 * size.y);

	POINT c = { trunc(pos.x) - gap.x, trunc(pos.y) - gap.y };

	if (Player::cell[c.x][c.y] == 3)
		if (type < 7)
		{
			flag = true;
			return;
		}

	//for (int y = -range; y <= range; y++)
	//	for (int x = -range; x <= range; x++)
	//		if (Player::cell[c.x + x >= CELLSIZE_X ? CELLSIZE_X - 1 : c.x + x][c.y + y >= CELLSIZE_Y ? CELLSIZE_Y - 1 : c.y + y] == 2)
	//			dir = RANDOM->Vec2(pos);
}

void Enemy::Render()
{
	main_col->Draw();
	for (auto& i : fxs)
		i->Render();
	img->Render(pos, ZERO, ONE, atan2(dir.x, -dir.y), 0);
}

void Enemy::Release()
{
	SAFE_DELETE(main_col);
	for (auto& i : fxs)
		SAFE_DELETE(i);
	fxs.clear();
}

void Enemy::Enter(Col* p)
{
}

void Enemy::Stay(Col* p)
{
}

void Enemy::Exit(Col* p)
{
}
