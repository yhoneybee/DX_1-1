#include "DXUT.h"
#include "ChangeEffect.h"

void ChangeEffect::Init()
{
	ANIM->Add("transition_effect", "tran_", "")->Start(false, true);
}

void ChangeEffect::Update()
{
	if (!ANIM->Add("transition_effect", "tran_", "")->isStart)
		SCENE->Set(go_scene_name);
}

void ChangeEffect::Render()
{
	ANIM->Add("transition_effect", "tran_", "")->Render(CENTER, ZERO, ONE, 0, 0);
}

void ChangeEffect::Release()
{
}

void ChangeEffect::Enter(Col* p)
{
}

void ChangeEffect::Stay(Col* p)
{
}

void ChangeEffect::Exit(Col* p)
{
}
