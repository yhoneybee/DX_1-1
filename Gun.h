#pragma once
class Gun
{
private:
	V2 pos;
	float angle;
	int count;
	V2 dir;
	int pattern;

	int F = -90;
	int R = 0;
	int L = 180;
	int B = 90;

	float look;
public:
	list<BulletCase> bcs;
	void SetPostiton(V2 pos);
	void SetAngle(float angle);
	void SetCount(int count);
	void SetDir(V2 dir);
	void SetPattern(int pattern);
	void AddBullet(BulletCase bc);
	void Fire();
};

