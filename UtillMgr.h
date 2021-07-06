#pragma once
class UtillMgr :
	public st<UtillMgr>
{
public:
	UtillMgr()
		:rd(), gen(rd()), r() {}

	~UtillMgr() { ; };

	int INT(int min, int max);
	V2 Vec2(V2 origin);
	void Reflex(V2* dir_out, V2 side);

	random_device rd;
	mt19937 gen;
	uniform_int_distribution<int> r;

	int player_hp;
};

#define UTILL UtillMgr::G()