#include "DXUT.h"
#include "MiniMap.h"

MiniMap::MiniMap()
	:player(OBJ->Find("player")), target(OBJ->Find("boss"))
{
}

void MiniMap::Init()
{
	minimap = IMG->ReLoad("minimap");
	minimap_bg = IMG->ReLoad("minimapbg");

	minimap_color = new D3DXCOLOR[160 * 90];

	D3DLOCKED_RECT lr;

	minimap->p->LockRect(0, &lr, 0, D3DLOCK_DISCARD);

	DWORD* pixel = (DWORD*)lr.pBits;

	for (int y = 90 - 1; y != -1; --y)
		for (int x = 160 - 1; x != -1; --x)
			minimap_color[y * 160 + x] = pixel[y * 160 + x];

	minimap->p->UnlockRect(0);
}

void MiniMap::Update()
{
	pos = { player->pos.x - 425,player->pos.y - 200 };

	D3DLOCKED_RECT lr;

	minimap->p->LockRect(0, &lr, 0, D3DLOCK_DISCARD);

	DWORD* pixel = (DWORD*)lr.pBits;

	int p_x = player->pos.x / 10;
	int p_y = player->pos.y / 10;

	int t_x = target->pos.x / 10;
	int t_y = target->pos.y / 10;

	for (int y = 90 - 1; y != -1; --y)
	{
		for (int x = 160 - 1; x != -1; --x)
		{
			D3DXCOLOR change = minimap_color[y * 160 + x];

			if (Player::cell[int(x * 10)][int(y * 10)] == 3)
				change = D3DXCOLOR(0, 0, 0, 0);

			if (p_x != x && p_y != y && t_x != x && t_y != y && Player::cell[int(x * 10)][int(y * 10)] != 3)
				change = D3DXCOLOR(0.3, 0.3, 0.3, 1);

			if (t_x == x)
			{
				if (t_y == y + 1)
					change = D3DXCOLOR(1, 0, 0, 1);
				if (t_y == y - 1)
					change = D3DXCOLOR(1, 0, 0, 1);
			}

			if (t_y == y)
			{
				if (t_x == x + 1)
					change = D3DXCOLOR(1, 0, 0, 1);
				if (t_x == x - 1)
					change = D3DXCOLOR(1, 0, 0, 1);
			}

			if (p_x == x)
			{
				if (p_y == y + 1)
					change = D3DXCOLOR(0, 1, 0, 1);
				if (p_y == y - 1)
					change = D3DXCOLOR(0, 1, 0, 1);
			}

			if (p_y == y)
			{
				if (p_x == x + 1)
					change = D3DXCOLOR(0, 1, 0, 1);
				if (p_x == x - 1)
					change = D3DXCOLOR(0, 1, 0, 1);
			}

			pixel[y * 160 + x] = change;
		}
	}

	minimap->p->UnlockRect(0);
}

void MiniMap::Render()
{
	minimap_bg->Render(pos, ZERO, ONE, 0, 0);
	minimap->Render(pos, ZERO, ONE, 0, 0);
}

void MiniMap::Release()
{
	SAFE_DELETE_ARRAY(minimap_color);
}

void MiniMap::Enter(Col* p)
{
}

void MiniMap::Stay(Col* p)
{
}

void MiniMap::Exit(Col* p)
{
}
