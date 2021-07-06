#include "DXUT.h"
#include "End.h"

End::End(int type)
	:bg(), map(), type(type)
{
}

void End::Init()
{
	ANIM->Add("next", "next_", "")->Start(false, true);
	ANIM->Add("restart", "restart_", "")->Start(false, true);
	ANIM->Add("home", "home_", "")->Start(false, true);

	CAM->pos = CENTER;
	CAM->scale = { 1,1,1 };

	OBJ->Add(new Mouse, "Mouse");

	map = new ScrollMap(IMG->Add("Bg"));

	switch (type)
	{
	case 1:
		ANIM->Add("clear_title", "Clear_", "")->Start(false, true);
		restart = new Button(IMG->Add("BigBlue"), { CENTER.x,CENTER.y + 300 }, "", 160, 160, 1, [&]()->void {SCENE->Set("stage1"); OBJ->Add(new ChangeEffect("dialog1"), "ChangeEffect"); });
		title = new Button(IMG->Add("BigBlue"), { float(R - 100),float(B - 100) }, "", 160, 160, 1, [&]()->void {SCENE->Set("title"); });
		ANIM->Add("volt", "volt_", "")->Start(false, true);
		break;
	case 2:
		ANIM->Add("fail_title", "FAIL_", "")->Start(false, true);
		restart = new Button(IMG->Add("BigBlue"), { CENTER.x,CENTER.y + 270 }, "", 160, 160, 1, [&]()->void {SCENE->Set("stage1"); OBJ->Add(new ChangeEffect("dialog1"), "ChangeEffect"); });
		title = new Button(IMG->Add("BigBlue"), { float(R - 100),float(B - 100) }, "", 160, 160, 1, [&]()->void {SCENE->Set("title"); });
		break;
	case 3:
		ANIM->Add("clear_title", "Clear_", "")->Start(false, true);
		next = new Button(IMG->Add("BigBlue"), { CENTER.x - 100,CENTER.y + 270 }, "", 160, 160, 1, [&]()->void {SCENE->Set("stage2"); OBJ->Add(new ChangeEffect("dialog2"), "ChangeEffect"); });
		restart = new Button(IMG->Add("BigBlue"), { CENTER.x + 100,CENTER.y + 270 }, "", 160, 160, 1, [&]()->void {SCENE->Set("stage1"); OBJ->Add(new ChangeEffect("dialog1"), "ChangeEffect"); });
		title = new Button(IMG->Add("BigBlue"), { float(R - 100),float(B - 100) }, "", 160, 160, 1, [&]()->void {SCENE->Set("title"); });
		ANIM->Add("volt", "volt_", "")->Start(false, true);
		break;
	case 4:
		ANIM->Add("clear_title", "Clear_", "")->Start(false, true);
		next = new Button(IMG->Add("BigBlue"), { CENTER.x - 100,CENTER.y + 270 }, "", 160, 160, 1, [&]()->void {SCENE->Set("stage3"); OBJ->Add(new ChangeEffect("dialog3"), "ChangeEffect"); });
		restart = new Button(IMG->Add("BigBlue"), { CENTER.x + 100,CENTER.y + 270 }, "", 160, 160, 1, [&]()->void {SCENE->Set("stage1"); OBJ->Add(new ChangeEffect("dialog1"), "ChangeEffect"); });
		title = new Button(IMG->Add("BigBlue"), { float(R - 100),float(B - 100) }, "", 160, 160, 1, [&]()->void {SCENE->Set("title"); });
		ANIM->Add("volt", "volt_", "")->Start(false, true);
		break;
	}
}

void End::Update()
{
	if (map)
		map->Update(500);

	if (type == 3 || type == 4)
		next->bg = ANIM->Add("next", "next_", "")->CurText;

	restart->bg = ANIM->Add("restart", "restart_", "")->CurText;
	title->bg = ANIM->Add("home", "home_", "")->CurText;
}

void End::Render()
{
	if (map)
		map->Render();

	switch (type)
	{
	case 1:
		ANIM->Add("clear_title", "Clear_", "")->Render({ CENTER.x,CENTER.y - 200 });
		break;
	case 2:
		ANIM->Add("fail_title", "FAIL_", "")->Render();
		break;
	case 3:
		ANIM->Add("clear_title", "Clear_", "")->Render({ CENTER.x,CENTER.y - 200 });
		break;
	case 4:
		ANIM->Add("clear_title", "Clear_", "")->Render({ CENTER.x,CENTER.y - 200 });
		break;
	}

	if (type == 1 || type == 3 || type == 4)
		switch (UTILL->player_hp)
		{
		case 1:
			ANIM->Add("volt", "volt_", "")->Render({ CENTER.x,CENTER.y });
			break;
		case 2:
			ANIM->Add("volt", "volt_", "")->Render({ CENTER.x - 100,CENTER.y });
			ANIM->Add("volt", "volt_", "")->Render({ CENTER.x + 100,CENTER.y });
			break;
		case 3:
			ANIM->Add("volt", "volt_", "")->Render({ CENTER.x - 100,CENTER.y });
			ANIM->Add("volt", "volt_", "")->Render({ CENTER.x,CENTER.y });
			ANIM->Add("volt", "volt_", "")->Render({ CENTER.x + 100,CENTER.y });
			break;
		}
}

void End::Release()
{
	SAFE_DELETE(map);
}
