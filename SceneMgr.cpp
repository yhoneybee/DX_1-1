#include "DXUT.h"
#include "SceneMgr.h"

SceneMgr::~SceneMgr()
{
	if (now)
		now->Release();
	for (auto& i : scenes)
		SAFE_DELETE(i.second);
	scenes.clear();
}

void SceneMgr::Add(Scene* p, const string& key)
{
	if (p && scenes.find(key) == scenes.end())
		scenes[key] = p;
}

void SceneMgr::Set(const string& key)
{
	if (key == "stage1")
		round = 1;
	if (key == "stage2")
		round = 2;
	if (key == "stage3")
		round = 3;

	auto f = scenes.find(key);
	if (f != scenes.end())
	{
		if (now)
		{
			now->Release();
			now->inited = false;
		}
		OBJ->Clear();
		now = f->second;
	}
}

void SceneMgr::Update()
{
	if (OBJ->l_obj.empty() && !now->inited)
	{
		now->Init();
		now->inited = true;
		HOT->Reset();
	}

	if (now->inited)
		now->Update();
}

void SceneMgr::Render()
{
	if (now->inited)
		now->Render();
}
