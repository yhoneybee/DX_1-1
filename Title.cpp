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
		bolt = IMG->Add("Bolt");
		title = IMG->Add("Title");

		bolt_rot = 180;
		bolt_end_pos = { CENTER.x - 315 ,CENTER.y + 95 };
		bolt_pos = { bolt_end_pos.x - 250, bolt_end_pos.y - 125 };

		title_end_pos = { CENTER.x + 150,CENTER.y - 250 };
		title_pos = { title_end_pos.x,title_end_pos.y - 300 };

		start = new Button(IMG->Add("Start"), { CENTER.x + 150,CENTER.y + 30 }, "", 225, 100, 1, [&]()->void {SCENE->Set("dialog1"); });
		start->a = 0;
		option = new Button(IMG->Add("Option"), { CENTER.x + 200,CENTER.y + 180 }, "", 225, 50, 1, [&]()->void {});
		option->a = 0;
		exit = new Button(IMG->Add("Exit"), { CENTER.x + 225,CENTER.y + 255 }, "", 225, 50, 1, [&]()->void {PostQuitMessage(0); });
		exit->a = 0;

		delay_up = TIME->Create(1);
		delay_up->Start();
		up = true;
		break;
	}
}

void Title::Update()
{
	if (OBJ->Find("Mouse") == nullptr)
		OBJ->Add(new Mouse, "Mouse");

	title_pos.x == title_end_pos.x && title_pos.y == title_end_pos.y ? (start->a < 255 ? start->a += 20 : start->a = 255) : 0;
	start->a == 255 ? (option->a < 255 ? option->a += 20 : option->a = 255) : 0;
	option->a == 255 ? (exit->a < 255 ? exit->a += 20 : exit->a = 255) : 0;

	if (delay_up->IsStop())
	{
		up = !up;
		delay_up->Start();
	}

	if (is_pos_end)
	{
		if (up)
			bolt_pos.y -= DT * 30;
		else
			bolt_pos.y += DT * 30;
		bolt_end_pos = bolt_pos;
	}
}

void Title::Render()
{
	bg->Render();
	bolt->Render({ bolt_pos.x < bolt_end_pos.x ? bolt_pos.x += 10 : bolt_end_pos.x,bolt_pos.y < bolt_end_pos.y ? bolt_pos.y += 5 : bolt_end_pos.y }, ZERO, ONE, D3DXToRadian(bolt_rot > 0 ? bolt_rot -= 7 : 0));
	bolt_pos.x == bolt_end_pos.x && bolt_pos.y == bolt_end_pos.y ? is_pos_end = true, title->Render({ title_pos.x < title_end_pos.x ? title_pos.x += 10 : title_end_pos.x, title_pos.y < title_end_pos.y ? title_pos.y += 5 : title_end_pos.y }) : 0;
}

void Title::Release()
{
}
