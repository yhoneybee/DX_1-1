#include "DXUT.h"
#include "Title.h"

Title::Title(int type)
	:bg(), type(type)
{
}

void Title::Init()
{
	SOUND->Find("BGM")->Stop();

	CAM->scale = { 1,1,1 };
	CAM->pos = CENTER;

	bg = IMG->Add("BG");

	start = new Button(IMG->Add("play"), { CENTER.x,CENTER.y + 255 }, "", 225, 100, 1, [&]()->void {/*SCENE->Set("dialog1");*/OBJ->Add(new ChangeEffect("dialog1"), "ChangeEffect"); });
	credit = new Button(IMG->Add("Credit"), { CENTER.x + 250,CENTER.y + 255 }, "", 225, 50, 1, [&]()->void {/*SCENE->Set("credit");*/OBJ->Add(new ChangeEffect("credit"), "ChangeEffect"); });
	exit = new Button(IMG->Add("Exit"), { CENTER.x - 250,CENTER.y + 255 }, "", 225, 50, 1, [&]()->void {PostQuitMessage(0); });

	ANIM->Add("Logo_anim", "LogoFrame_", "")->Start();
	ANIM->Add("Skill_anim", "Frame_", "")->Start(false, true);
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
	if (type == 3)
		IMG->Add("ClearIcon")->Render({ CENTER.x + 675,CENTER.y - 315 });
}

void Title::Release()
{
}
