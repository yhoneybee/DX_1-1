#pragma once
class Timer;
class CamMgr :
	public st<CamMgr>
{
public:
	CamMgr();
	~CamMgr() { ; };

	void Update();
	void Reset();
	void Apply();
	void Shake(float time, float force = 5);

	V2 pos, size;
	V3 scale;
	float rot;
private:
	M pro, view;

	Timer* shake_timer;
	float shake_force = 5;
};

#define CAM CamMgr::G()