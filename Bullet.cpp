#include "DXUT.h"
#include "Bullet.h"

Bullet::Bullet(BulletCase gc, V2 dir, bool eatk)
	:gc(gc), dir(dir), speed(0), eatk(eatk)
{
}

void Bullet::Init()
{
	speed = 2;
	delay = TIME->Create(0.5f);
	main_col = new Col(this, (eatk ? EATK : PATK), 1);
	switch (gc)
	{
	case CRICLE:
		img = IMG->Add("/bullet/bullet_1");
		break;
	case SHURIKEN:
		img = IMG->Add("/bullet/bullet_2");
		break;
	case HURRICANE:
		img = IMG->Add("/bullet/bullet_3");
		break;
	case CROSS:
		img = IMG->Add("/bullet/bullet_4");
		break;
	case BULB:
		img = IMG->Add("/bullet/Player_bullet");
		break;
	}
	rot = atan2(dir.x, -dir.y);
}

void Bullet::Update()
{
	pos += dir * speed;

	if (delay->IsStop())
	{
		fxs.emplace_back(new Effect(img, pos, rot, 3));
		delay->Start();
	}

	main_col->Set(pos, 20, 20);

	POINT c = { trunc(pos.x), trunc(pos.y) };

	if (Player::cell[int(c.x)][int(c.y)] == 3)
		flag = true;

	if (pos.x < L || R < pos.x || pos.y < T || B < pos.y)
		flag = true;
}

void Bullet::Render()
{
	main_col->Draw();
	for (auto& i : fxs)
		i->Render();
	img->Render(pos, { 0,0,0,0 }, ONE, rot += DT * 2, 0, D3DCOLOR_RGBA(255, 255, 255, 255));
}

void Bullet::Release()
{
	SAFE_DELETE(main_col);
	for (auto& i : fxs)
		SAFE_DELETE(i);
	fxs.clear();
}

void Bullet::Enter(Col* p)
{
}

void Bullet::Stay(Col* p)
{
}

void Bullet::Exit(Col* p)
{
}
