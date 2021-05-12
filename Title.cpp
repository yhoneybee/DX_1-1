#include "DXUT.h"
#include "Title.h"

Title::Title(int type)
	:bg(), map(), type(type)
{
}

void Title::Init()
{
	OBJ->Add(new Mouse, "Mouse");

	map = new ScrollMap(IMG->Add("Bg", "Bg"));

	switch (type)
	{
	case 1:
		anim = vector<Texture*>
		{
			IMG->Add("intro1","intro1"),
			IMG->Add("intro2","intro2"),
			IMG->Add("intro3","intro3"),
			IMG->Add("intro4","intro4"),
			IMG->Add("intro5","intro5"),
		};

		delay = TIME->Create(1);
		delay->Start();
		break;
	case 2:
		bg = IMG->Add("Bg", "Bg");
		start = new Button(IMG->Add("BigBlue", "BigBlue"), { CENTER.x + 650,CENTER.y - 85 }, "START", 440, 200, 1, [&]()->void {SCENE->Set("stage1"); });
		credit = new Button(IMG->Find("BigBlue"), { CENTER.x + 650,CENTER.y + 140 }, "HowToPlay", 440, 200, 1, [&]()->void {win_credit->On(); });
		end = new Button(IMG->Find("BigBlue"), { CENTER.x + 650,CENTER.y + 365 }, "EXIT", 440, 200, 1, [&]()->void {PostQuitMessage(0); });
		win_credit = new Window(IMG->Add("HowToPlay", "HowToPlay"), CENTER, 900, 900);
		break;
	}
}

void Title::Update()
{
	switch (type)
	{
	case 1:
		if (INPUT->Down(VK_RETURN))
			SCENE->Set("title");
		if (delay->IsStop())
		{
			index++;
			delay->Start();
			if (index == anim.size())
				SCENE->Set("title");
		}
		break;
	case 2:
		if (map)
			map->Update(500);
		break;
	}
}

void Title::Render()
{
	switch (type)
	{
	case 1:
		anim[index]->Render();
		break;
	case 2:
		if (map)
			map->Render();
		break;
	}
}

void Title::Release()
{
	SAFE_DELETE(map);
}
