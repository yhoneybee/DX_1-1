#pragma once
struct Anim
{
	Anim(const string& name, float fps, const string& before, const string& after);

	void Start(bool isLoop = true, bool render_awalys = false)
	{
		if (!isStart)
		{
			frame = 0;
			this->isLoop = isLoop;
			this->render_awalys = render_awalys;
			isStart = true;
		}
	}

	void Update();
	void Render(V2 pos = CENTER, RECT rt = ZERO, V2 size = ONE, float rot = 0, float depth = 1, D3DXCOLOR color = MAX, bool center = true);

	vector<Texture*> anim;
	Texture* CurText;
	Timer* timer;

	int frame = 0;
	bool isLoop = true;
	bool isStart = false;
	bool render_awalys = false;
};

class AnimMgr :
	public st<AnimMgr>
{
public:
	AnimMgr();
	~AnimMgr();

	void Update();
	Anim* Add(const string& name, const string& before = "(", const string& after = ")");

	map<string, Anim*> anims;
};

#define ANIM AnimMgr::G()