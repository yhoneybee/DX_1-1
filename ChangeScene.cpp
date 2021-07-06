#include "DXUT.h"
#include "ChangeScene.h"

void ChangeScene::Init()
{
	ANIM->Add("transition_effect", "tran_", "")->Start(false, true);
}

void ChangeScene::Update()
{
	if (!ANIM->Add("transition_effect", "tran_", "")->isStart)
	{
		SCENE->Set(go_scene_name);
	}
}

void ChangeScene::Render()
{
	ANIM->Add("transition_effect", "tran_", "")->Render();
}

void ChangeScene::Release()
{
}
