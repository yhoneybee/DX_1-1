


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

void Enemy::CircleShot(float angle, int shots)
{
	float value = angle / shots;
	float look = D3DXToDegree(atan2f(dir.x, -dir.y));
	for (float i = look - (angle / 2) - 90; i <= look + (angle / 2) - 90; i += value)
	{
		OBJ->Add(new Bullet(BulletCase::SHURIKEN, { cos(D3DXToRadian(i)), sin(D3DXToRadian(i)) }, true), "Bullet")->pos = pos;
		//OBJ->Add(new Bullet(BulletCase::CRICLE, { cos(D3DXToRadian(i)), sin(D3DXToRadian(i)) }, true), "Bullet")->pos = pos;
		//OBJ->Add(new Bullet(BulletCase::HURRICANE, { cos(D3DXToRadian(i)), sin(D3DXToRadian(i)) }, true), "Bullet")->pos = pos;
		OBJ->Add(new Bullet(BulletCase::CROSS, { cos(D3DXToRadian(i)), sin(D3DXToRadian(i)) }, true), "Bullet")->pos = pos;
	}
}

void Enemy::Init()
{
	hp = 500;
	player = OBJ->Find("player");
	dir = UTILL->Vec2(pos);
	char str[256];
	sprintf(str, "enemy%d", type);
	img = IMG->Add(str);
	cool = 0;
	speed = 0;
	size = ONE;
	spin_force = 0;
	main_col = new Col(this, EATK);

	speed = 1;

	switch (type)
	{
	case 1:
		cool = 5;
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		cool = 3;
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		cool = 10;
		break;
	case 8:
		cool = 5;
		break;
	}

	death = ANIM->Add("Boss_explosion", "Boss_Ex", "");
	timer = TIME->Create(cool);
	timer->Start();
	during = TIME->Create(3);
}

void Enemy::Update()
{
	for (int i = 0; i < speed; i++)
	{
		if (OBJ->Find("boss")->hp <= 0)
			break;

		pos += dir;

		if (pos.x < L)
			UTILL->Reflex(&dir, V2(-1, 0));
		if (pos.x > R)
			UTILL->Reflex(&dir, V2(1, 0));
		if (pos.y < T)
			UTILL->Reflex(&dir, V2(0, -1));
		if (pos.y > B)
			UTILL->Reflex(&dir, V2(0, 1));

		if (Player::cell[int(pos.x) + 1][int(pos.y)] == 2)
			UTILL->Reflex(&dir, V2(1, 0));
		if (Player::cell[int(pos.x) - 1][int(pos.y)] == 2)
			UTILL->Reflex(&dir, V2(-1, 0));
		if (Player::cell[int(pos.x)][int(pos.y) + 1] == 2)
			UTILL->Reflex(&dir, V2(0, 1));
		if (Player::cell[int(pos.x)][int(pos.y) - 1] == 2)
			UTILL->Reflex(&dir, V2(0, -1));
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
			speed = 1;
		}
		else
		{
			speed = 10;
			fxs.emplace_back(new Effect(img, pos, 0, 3));
		}
		break;
	case 8:
		range = 110;
		if (timer->IsStop())
		{
			CircleShot(360, 36);
			timer->Start();
		}
		break;
	}

	main_col->Set(pos, 16 * size.x, 16 * size.y);

	POINT c = { trunc(pos.x) - gap.x, trunc(pos.y) - gap.y };

	if (Player::cell[c.x][c.y] == 3 && type < 7 && !ANIM->Add("enemy_explosion", "enemyex_Frame", "")->isStart)
		flag = true;

	if (Player::cell[c.x][c.y] == 3)
		if (type < 7)
		{
			//flag = true;
			ANIM->Add("enemy_explosion", "enemyex_Frame", "")->Start(false, false);
			return;
		}

	if (hp <= 0)
	{
		if (!death->isStart && isAnim)
		{
			if (SCENE->round == 1)
				SCENE->Set("next");
			else if (SCENE->round == 2)
				SCENE->Set("nextnext");
			else if (SCENE->round == 3)
				SCENE->Set("clear");
		}
		if (type >= 7)
			if (!death->isStart)
			{
				if (!isAnim)
				{
					death->Start(false);
					isAnim = true;
				}
			}
			else
			{
				CAM->followable = false;
				CAM->pos = OBJ->Find("boss")->pos;
				CAM->scale += V3(0.005, 0.005, 0.005);
			}
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
	death->Render(CAM->pos, ZERO, ONE * 2, 0, 0);
	if (Player::cell[int(pos.x)][int(pos.y)] == 3 && type < 7)
		ANIM->Add("enemy_explosion", "enemyex_Frame", "")->Render(pos, ZERO, ONE, 0, 0);
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
