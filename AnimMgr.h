#pragma once
struct Anim
{
	Anim(const string& name, float fps);

	void Start(bool isLoop = true)
	{
		this->isLoop = isLoop;
		isStart = true;
	}
	void Update();
	void Render(V2 pos = CENTER, RECT rt = ZERO, V2 size = ONE, float rot = 0, float depth = 1, D3DXCOLOR color = D3DCOLOR_RGBA(255, 255, 255, 255), bool center = true);

	vector<Texture*> anim;
	Timer* timer;

	int frame = 0;
	bool isLoop = true;
	bool isStart = false;
};

class AnimMgr :
	public st<AnimMgr>
{
public:
	AnimMgr();
	~AnimMgr();

	void Update();
	Anim* Add(const string& name, float fps = 1);

	map<string, Anim*> anims;
};

#define ANIM AnimMgr::G()