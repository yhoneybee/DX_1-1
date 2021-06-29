#include "DXUT.h"
#include "DialogScene.h"

void DialogScene::Init()
{
	switch (type)
	{
	case 1:
		dialog = new Dialog("player", "Bolt");

		dialog->go_scene = "stage1";

		dialog->scripts.emplace_back(Script("¿©±â´Â...?"));
		dialog->scripts.emplace_back(Script("¹º ¿©±â´ÂÀÌ¾ß? ¿©±â´Â", "»¡¸® ¾È ÀÏ¾î³ª?"));
		dialog->scripts.emplace_back(Script("¹¹ ¾¾¹ß¾Æ"));
		dialog->scripts.emplace_back(Script("???", "¾¾¹ß·³ÀÌ?"));
		dialog->scripts.emplace_back(Script("?"));
		break;
	}

	dialog->chater1.pos = V2(CENTER.x - 300, CENTER.y - 100);
	dialog->chater2.pos = V2(CENTER.x + 300, CENTER.y - 100);

	OBJ->Add(dialog, "dialog")->pos = CENTER;
}

void DialogScene::Update()
{
}

void DialogScene::Render()
{
}

void DialogScene::Release()
{
}
