#include "DXUT.h"
#include "End.h"

End::End(int type)
	:bg(), map(), type(type)
{
}

void End::Init()
{
	CAM->pos = CENTER;
	CAM->scale = { 1,1,1 };

	OBJ->Add(new Mouse, "Mouse");

	map = new ScrollMap(IMG->Add("Bg"));

	restart = new Button(IMG->Add("BigBlue"), { CENTER.x - 300,CENTER.y + 300 }, "RESTART", 440, 200, 1, [&]()->void {SCENE->Set("stage1"); });
	title = new Button(IMG->Add("BigBlue"), { CENTER.x + 300,CENTER.y + 300 }, "TITLE", 440, 200, 1, [&]()->void {SCENE->Set("title"); });
}

void End::Update()
{
	if (map)
		map->Update(500);
}

void End::Render()
{
	if (map)
		map->Render();

	switch (type)
	{
	case 1:
		IMG->Write("Congratulations on Clear!");
		break;
	case 2:
		IMG->Write("I wish you success next time...");
		break;
	}
}

void End::Release()
{
	SAFE_DELETE(map);
}
