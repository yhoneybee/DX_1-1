#include "DXUT.h"
#include "Title.h"

Title::Title(int type)
	:bg(), type(type)
{
}

void Title::Init()
{
	CAM->scale = { 1,1,1 };
	CAM->pos = CENTER;

	switch (type)
	{
	case 1:
		break;
	case 2:
		bg = IMG->Add("BG");

		start = new Button(IMG->Add("play"), { CENTER.x,CENTER.y + 255 }, "", 225, 100, 1, [&]()->void {SCENE->Set("dialog1"); });
		credit = new Button(IMG->Add("Credit"), { CENTER.x + 250,CENTER.y + 255 }, "", 225, 50, 1, [&]()->void {SCENE->Set("credit"); });
		exit = new Button(IMG->Add("Exit"), { CENTER.x - 250,CENTER.y + 255 }, "", 225, 50, 1, [&]()->void {PostQuitMessage(0); });

		ANIM->Add("Logo_anim", "LogoFrame_", "")->Start();
		break;
	}
}

void Title::Update()
{
	if (OBJ->Find("Mouse") == nullptr)
		OBJ->Add(new Mouse, "Mouse");
}

void Title::Render()
{
	bg->Render();
	ANIM->Add("Logo_anim", "LogoFrame_", "")->Render(V2(CENTER.x + 45, CENTER.y - 200));
}

void Title::Release()
{
}
