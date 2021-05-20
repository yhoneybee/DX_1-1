#pragma once
class Gun
{
private:
	V2 pos;
	float angle;
	int count;
	V2* dir;
	list<BulletCase> bcs;
	int max_pattern = 1;

	int F = -90;
	int R = 0;
	int L = 180;
	int B = 90;

	float look;
public:
	int pattern = 1;
	int GetMaxPattern() { return max_pattern; }
	void SetPostiton(V2 pos);
	void SetAngle(float angle);
	void SetCount(int count);
	void SetDir(V2* dir);
	void SetPattern(int pattern);
	void PatternStart();
	void SetBullet(list<BulletCase> bcs);
	void Fire();
};

