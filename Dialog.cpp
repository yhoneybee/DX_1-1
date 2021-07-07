#include "DXUT.h"
#include "Dialog.h"

void Dialog::Init()
{
	//chater2.alpha = 0.3;
	bg = IMG->Add("Story_BG");
	ANIM->Add("ping", "ping_Frame", "")->Start();
}

void Dialog::Update()
{
	if (INPUT->Down(VK_SPACE))
	{
		if (index == scripts.size() - 1)
			SCENE->Set(go_scene);
		else
		{
			++index;
			SOUND->Add("DIALOG", L"DIALOG")->Copy();
			//swap(chater1.pos, chater2.pos);
			//swap(chater1.alpha, chater2.alpha);
		}
	}

	switch (chat_types[index])
	{
	case ChatType::LINA2ME:
		chat_bg = IMG->Add("lina_me");
		break;
	case ChatType::ME2LINA:
		chat_bg = IMG->Add("me_lina");
		break;
	case ChatType::TRICKSTER2ME:
		chat_bg = IMG->Add("trickster_me");
		break;
	case ChatType::ME2TRICKSTER:
		chat_bg = IMG->Add("me_trickster");
		break;
	}
}

void Dialog::Render()
{
	bg->Render();
	//chater1.texture->Render(chater1.pos, ZERO, ONE, 0, 1, D3DXCOLOR(1, 1, 1, chater1.alpha));
	//chater2.texture->Render(chater2.pos, ZERO, ONE, 0, 1, D3DXCOLOR(1, 1, 1, chater2.alpha));

	chat_bg->Render();

	ANIM->Add("ping", "ping_Frame", "")->Render({ CENTER.x + 450 - (static_cast<int>(chat_types[index]) % 2 == 0 ? 120 : 0),CENTER.y + 320 });

	IMG->Write(scripts[index].l1, V2(CENTER.x - 300 - (static_cast<int>(chat_types[index]) % 2 == 0 ? 120 : 0), CENTER.y + 220), 40, MAX, false);
	IMG->Write(scripts[index].l2, V2(CENTER.x - 300 - (static_cast<int>(chat_types[index]) % 2 == 0 ? 120 : 0), CENTER.y + 260), 40, MAX, false);
	IMG->Write(scripts[index].l3, V2(CENTER.x - 300 - (static_cast<int>(chat_types[index]) % 2 == 0 ? 120 : 0), CENTER.y + 300), 40, MAX, false);
	IMG->Write(scripts[index].l4, V2(CENTER.x - 300 - (static_cast<int>(chat_types[index]) % 2 == 0 ? 120 : 0), CENTER.y + 340), 40, MAX, false);
	IMG->Write(scripts[index].l5, V2(CENTER.x - 300 - (static_cast<int>(chat_types[index]) % 2 == 0 ? 120 : 0), CENTER.y + 380), 40, MAX, false);
}

void Dialog::Release()
{
}

void Dialog::Enter(Col* p)
{
}

void Dialog::Stay(Col* p)
{
}

void Dialog::Exit(Col* p)
{
}
