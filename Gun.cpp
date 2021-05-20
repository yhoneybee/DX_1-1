#include "DXUT.h"
#include "Gun.h"

void Gun::SetPostiton(V2 pos)
{
	this->pos = pos;
}

void Gun::SetAngle(float angle)
{
	this->angle = angle;
}

void Gun::SetCount(int count)
{
	this->count = count;
}

void Gun::SetDir(V2* dir)
{
	this->dir = dir;
	look = D3DXToDegree(atan2f((*dir).x, -(*dir).y));
}

void Gun::SetPattern(int pattern)
{
	this->pattern = pattern;
}

void Gun::SetBullet(list<BulletCase> bcs)
{
	this->bcs = move(bcs);
}

void Gun::Fire()
{
	//OBJ->Add(new Bullet(BulletCase::SHURIKEN, { cos(D3DXToRadian(i)), sin(D3DXToRadian(i)) }), "Bullet")->pos = pos;
	//OBJ->Add(new Bullet(BulletCase::CRICLE, { cos(D3DXToRadian(i)), sin(D3DXToRadian(i)) }), "Bullet")->pos = pos;
	//OBJ->Add(new Bullet(BulletCase::HURRICANE, { cos(D3DXToRadian(i)), sin(D3DXToRadian(i)) }), "Bullet")->pos = pos;
	//OBJ->Add(new Bullet(BulletCase::CROSS, { cos(D3DXToRadian(i)), sin(D3DXToRadian(i)) }), "Bullet")->pos = pos;

	//		angle = 90;
//		float value = angle / bullet_count;
//		for (float i = look - (angle / 2) + back; i <= look + (angle / 2) + back; i += value)
//		{

	float value = angle / count;

	int lookat = ((*dir).x == 0 ? ((*dir).y < 0 ? B : F) : ((*dir).x < 0 ? R : L));

	for (float i = look - (angle / 2) + lookat; i < look + (angle / 2) + lookat; i += value)
		for (auto& bc : bcs)
			OBJ->Add(new Bullet(bc, { cos(D3DXToRadian(i)), sin(D3DXToRadian(i)) }), "Bullet")->pos = pos;
}
