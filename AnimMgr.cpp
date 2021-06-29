#include "DXUT.h"
#include "AnimMgr.h"

AnimMgr::AnimMgr()
{
}

AnimMgr::~AnimMgr()
{
	for (auto& anim : anims)
	{
		anim.second->anim.clear();
		SAFE_DELETE(anim.second);
	}
	anims.clear();
}

void AnimMgr::Update()
{
	for (auto& anim : anims)
		anim.second->Update();
}

Anim* AnimMgr::Add(const string& name, const string& before, const string& after)
{
	auto f = anims.find(name);
	if (f == anims.end())
	{
		Anim* temp = new Anim(name, 12, before, after);
		anims[name] = temp;
		return temp;
	}
	return f->second;
}

Anim::Anim(const string& name, float fps, const string& before, const string& after)
{
	timer = TIME->Create(1 / fps);

	frame = 0;

	int index = -1;

	char str_name[256];
	char str_log[256];

	Texture* temp;

	do
	{
		++index;

		sprintf(str_log, "%s anim loading %02d...\n", name.c_str(), index);
		OutputDebugStringA(str_log);

		sprintf(str_name, "anim/%s/%s%d%s", name.c_str(), before.c_str(), index, after.c_str());

		temp = IMG->Add(str_name);

		if (temp == nullptr)
			break;

		anim.emplace_back(temp);
	} while (1);

	sprintf(str_log, "%s anim count : %d\n", name.c_str(), (int)anim.size());
	OutputDebugStringA(str_log);

	CurText = anim[0];
}

void Anim::Update()
{
	if (isStart)
	{
		if (timer->IsStop())
		{
			if (frame >= anim.size() - 1)
			{
				frame = 0;
				if (!isLoop)
				{
					frame = anim.size() - 2;
					isStart = false;
				}
			}
			frame++;
			timer->Start();
		}
	}

	CurText = anim[frame];
}

void Anim::Render(V2 pos, RECT rt, V2 size, float rot, float depth, D3DXCOLOR color, bool center)
{
	if (isStart || render_awalys)
		anim[frame]->Render(pos, rt, size, rot, depth, color, center);
}
