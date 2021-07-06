#include "DXUT.h"
#include "CreditScene.h"

void CreditScene::Init()
{
	back = new Button(IMG->Add("Exit"), { float(L + 200),float(B - 100) }, "", 270, 80, 1, [&]()->void {SCENE->Set("go_title"); });
	ANIM->Add("Back", "Backframe_", "")->Start();
	ANIM->Add("Logo_anim", "LogoFrame_", "")->Start();
}

void CreditScene::Update()
{
	if (OBJ->Find("Mouse") == nullptr)
		OBJ->Add(new Mouse, "Mouse");
	back->bg = ANIM->Add("Back", "Backframe_", "")->CurText;
}

void CreditScene::Render()
{
	IMG->Add("CreditBG")->Render();
	ANIM->Add("Logo_anim", "LogoFrame_", "")->Render(V2(CENTER.x - 375, CENTER.y - 70));
}

void CreditScene::Release()
{
}
