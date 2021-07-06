#include "DXUT.h"
#include "DialogScene.h"

void DialogScene::Init()
{
	switch (type)
	{
	case 1:
		dialog = new Dialog(/*"player", "Bolt"*/);

		dialog->go_scene = "stage1";

		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->chat_types.emplace_back(ChatType::ME2LINA);
		dialog->chat_types.emplace_back(ChatType::LINA2ME);
		dialog->chat_types.emplace_back(ChatType::TRICKSTER2ME);

		dialog->scripts.emplace_back(Script("여기는...?"));
		dialog->scripts.emplace_back(Script("뭔 여기는이야? 여기는", "빨리 안 일어나?"));
		dialog->scripts.emplace_back(Script("내 이름은?"));
		dialog->scripts.emplace_back(Script("?", "싸가지가 없네"));
		dialog->scripts.emplace_back(Script("히히!히히!네이스!"));
		break;
	}

	//dialog->chater1.pos = V2(CENTER.x - 300, CENTER.y - 100);
	//dialog->chater2.pos = V2(CENTER.x + 300, CENTER.y - 100);

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
