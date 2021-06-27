#include "DXUT.h"
#include "Button.h"

// 버튼의 사진, 버튼의 위치, 버튼에 띄우는 사진, 버튼 Col w, h, 사진의 depth, 버튼 누르면 실행될 람다 함수
Button::Button(Texture* bg, V2 pos, const string& text, float w, float h, float depth, function<void()> func)
	:bg(bg), text(text), func(func), depth(depth), isOn(true)
{
	this->pos = pos;

	main_col = new Col(this, UI);

	this->w = w;
	this->h = h;

	OBJ->Add(this, "Button");
}

void Button::On()
{
	isOn = true;
	main_col->flag = true;
}

void Button::Off()
{
	isOn = false;
	main_col->flag = false;
}

void Button::Init()
{
}

void Button::Update()
{
	main_col->Set(pos, w, h);
}

void Button::Render()
{
	if (isOn)
	{
		bg->Render(pos, ZERO, ONE, 0, depth, D3DCOLOR_RGBA(r, g, b, a));
		IMG->Write(text, pos);
		main_col->Draw();
	}
}

void Button::Release()
{
	SAFE_DELETE(main_col);
}

void Button::Enter(Col* p)
{
	if (isOn)
		switch (p->tag)
		{
		case MOUSE:
			r -= 100;
			g -= 100;
			b -= 100;
			break;
		}
}

void Button::Stay(Col* p)
{
	if (isOn)
		switch (p->tag)
		{
		case MOUSE:
			if (INPUT->Down(VK_LBUTTON))
				func();
			break;
		}
}

void Button::Exit(Col* p)
{
	if (isOn)
		switch (p->tag)
		{
		case MOUSE:
			r += 100;
			g += 100;
			b += 100;
			break;
		}
}
