#include "DXUT.h"
#include "Dialog.h"

void Dialog::Init()
{
	chater2.alpha = 0.5;
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
			swap(chater1.pos, chater2.pos);
			swap(chater1.alpha, chater2.alpha);
		}
	}
}

void Dialog::Render()
{
	bg->Render();
	chater1.texture->Render(chater1.pos, ZERO, ONE, 0, 1, D3DXCOLOR(1, 1, 1, chater1.alpha));
	chater2.texture->Render(chater2.pos, ZERO, ONE, 0, 1, D3DXCOLOR(1, 1, 1, chater2.alpha));

	IMG->Write(scripts[index].l1, V2(CENTER.x, CENTER.y));
	IMG->Write(scripts[index].l2, V2(CENTER.x, CENTER.y + 60));
	IMG->Write(scripts[index].l3, V2(CENTER.x, CENTER.y + 120));
	IMG->Write(scripts[index].l4, V2(CENTER.x, CENTER.y + 180));
	IMG->Write(scripts[index].l5, V2(CENTER.x, CENTER.y + 240));
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
