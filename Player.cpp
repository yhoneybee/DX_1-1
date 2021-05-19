#include "DXUT.h"
#include "Player.h"

extern float time_scale;

int Player::cell[CELLSIZE_X][CELLSIZE_Y] = { 0, };
float Player::coloring_per = 0;

void Player::Init()
{
	boss = OBJ->Find("boss");
	bg = IMG->ReLoad("round1_before");
	bg_lower = IMG->Add("round1_after");
	img = IMG->Add("player");

	OBJ->Add(new MiniMap, "minimap");

	SetUp();

	main_col = new Col(this, P);
	during = TIME->Create(2);

	speed = 3;
	rot = 0;
	hp = 5;
	def = 0;
	draw_mode = false;
	no_damage = false;

	CAM->scale = { 1.5,1.5,2 };
}

void Player::Update()
{
	if (hp <= 0) SCENE->Set("fail");

	main_col->Set(pos, 5, 5);

	if (during->IsStop())
	{
		rot = 0;
		no_damage = false;
		img = IMG->Add("player");
	}
	else
	{
		no_damage = true;
		rot += spin_force;
		if (rot >= 360)
			rot = 0;
	}

	if (INPUT->Down(VK_SPACE)) drawing = !drawing;

	if (INPUT->Press(VK_UP))
	{
		for (size_t i = 0; i < speed; i++)
		{
			key = KeyState::UP;
			if (!drawing) { if (cell[int(pos.x)][int(pos.y - 1)] == 2)pos.y--; }
			else { if (cell[int(pos.x)][int(pos.y - 1)] != 3)pos.y--; }
			if (Current() == 1) pos.y++;
			if (pos.y <= T) pos.y = T;
			if (Current() == 2) DrawArea();
			else if (!Near(key, 3) && !Near(key, -1)) DrawLine();
		}
	}
	else if (INPUT->Press(VK_DOWN))
	{
		for (size_t i = 0; i < speed; i++)
		{
			key = KeyState::DOWN;
			if (!drawing) { if (cell[int(pos.x)][int(pos.y + 1)] == 2)pos.y++; }
			else { if (cell[int(pos.x)][int(pos.y + 1)] != 3)pos.y++; }
			if (Current() == 1) pos.y--;
			if (pos.y >= B) pos.y = B - 1;
			if (Current() == 2) DrawArea();
			else if (!Near(key, 3) && !Near(key, -1)) DrawLine();
		}
	}
	else if (INPUT->Press(VK_LEFT))
	{
		for (size_t i = 0; i < speed; i++)
		{
			key = KeyState::LEFT;
			if (!drawing) { if (cell[int(pos.x - 1)][int(pos.y)] == 2)pos.x--; }
			else { if (cell[int(pos.x - 1)][int(pos.y)] != 3)pos.x--; }
			if (Current() == 1) pos.x++;
			if (pos.x <= L) pos.x = L;
			if (Current() == 2) DrawArea();
			else if (!Near(key, 3) && !Near(key, -1)) DrawLine();
		}
	}
	else if (INPUT->Press(VK_RIGHT))
	{
		for (size_t i = 0; i < speed; i++)
		{
			key = KeyState::RIGHT;
			if (!drawing) { if (cell[int(pos.x + 1)][int(pos.y)] == 2)pos.x++; }
			else { if (cell[int(pos.x + 1)][int(pos.y)] != 3)pos.x++; }
			if (Current() == 1) pos.x--;
			if (pos.x >= R) pos.x = R - 1;
			if (Current() == 2) DrawArea();
			else if (!Near(key, 3) && !Near(key, -1)) DrawLine();
		}
	}

	if (INPUT->Down(VK_F1)) HOT->F1();
	if (INPUT->Down(VK_F2)) HOT->F2();
	if (INPUT->Down(VK_F3)) HOT->F3();
	if (INPUT->Down(VK_F4)) HOT->F4();
	if (INPUT->Down(VK_F5)) HOT->F5();
	if (INPUT->Down(VK_F6)) HOT->F6();

	if (INPUT->Down('Z'))
	{
		CAM->Shake(0.1f, 1);
	}
	if (INPUT->Down('X'))
	{

	}
	if (INPUT->Down('C'))
	{

	}
	if (INPUT->Down('V'))
	{

	}
}

void Player::Render()
{
	main_col->Draw();
	bg_lower->Render();
	bg->Render(CENTER, ZERO, ONE, 0, 1, D3DCOLOR_RGBA(255, 255, 255, 255));

	V2 dir;

	switch (key)
	{
	case Player::KeyState::UP: dir = { 0,-1 }; break;
	case Player::KeyState::DOWN: dir = { 0,1 }; break;
	case Player::KeyState::LEFT: dir = { -1,0 }; break;
	case Player::KeyState::RIGHT: dir = { 1,0 }; break;
	}

	img->Render(pos, ZERO, ONE / 4, atan2(dir.x, -dir.y));

	char str1[256];
	sprintf(str1, "%.2f%%", (double)coloring_per);
	IMG->Write(str1, { pos.x - 425 - 10,pos.y - 200 + 100 }, 10);
	sprintf(str1, "hp : %d", hp);
	IMG->Write(str1, { pos.x - 425 - 10,pos.y - 200 + 120 }, 10);
	sprintf(str1, "speed : %.2f", (double)speed);
	IMG->Write(str1, { pos.x - 425 - 20,pos.y - 200 + 140 }, 10);
	//sprintf(str1, "def : %d", def); 아마도 무기 장착 뜰것같음
	//IMG->Write(str1, { pos.x - 425 - 15,pos.y - 200 + 160 }, 10);
}

void Player::Release()
{
	SAFE_DELETE(main_col);
}

void Player::Enter(Col* p)
{
	switch (p->tag)
	{
	case EATK:
		if (Current() == 1 || Current() == 0)
		{
			hp--;
			speed *= 2;
			pos = start;
			DrawArea(2);
		}
		break;
	case ITEM:
		switch (((Item*)p->owner)->type)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		}
		p->owner->flag = true;
		break;
	}
}

void Player::Stay(Col* p)
{
	switch (p->tag)
	{
	case OBS:
		switch (key)
		{
		case Player::KeyState::UP:
			pos.y++;
			break;
		case Player::KeyState::DOWN:
			pos.y--;
			break;
		case Player::KeyState::LEFT:
			pos.x++;
			break;
		case Player::KeyState::RIGHT:
			pos.x--;
			break;
		}
		break;
	}
}

void Player::Exit(Col* p)
{
}

void Player::SetUp()
{
	memset(cell, 0, sizeof(cell));

	for (size_t x = 0; x < CELLSIZE_X; x++)
		for (size_t y = 0; y < CELLSIZE_Y; y++)
			if (x == 0 || x == CELLSIZE_X - 1 || y == 0 || y == CELLSIZE_Y - 1)
				cell[x][y] = 1;

	coloring_per = 0;
	coloring_cells = 0;
	temp = 0;

	draw_mode = true;
	DrawArea();
}

void Player::DrawLine()
{
	draw_mode = true;

	D3DLOCKED_RECT lr;
	bg->p->LockRect(0, &lr, 0, D3DLOCK_DISCARD);
	DWORD* pixel = (DWORD*)lr.pBits;

	POINT c = { pos.x - gap.x,pos.y - gap.y };
	int index = c.y * CELLSIZE_X + c.x;

	cell[c.x][c.y] = 1;

	pixel[index] = D3DCOLOR_RGBA(255, 0, 0, 255);

	bg->p->UnlockRect(0);
}

void Player::DrawArea(int draw_flag)
{
	if (!draw_mode)
	{
		start = pos;
		return;
	}

	draw_mode = false;

	D3DLOCKED_RECT lr;
	bg->p->LockRect(0, &lr, 0, D3DLOCK_DISCARD);
	DWORD* pixel = (DWORD*)lr.pBits;

	for (int y = CELLSIZE_Y - 1; y != -1; --y)
	{
		for (int x = CELLSIZE_X - 1; x != -1; --x)
		{
			D3DXCOLOR change = pixel[y * CELLSIZE_X + x];

			if ((cell[x + 1][y] & cell[x - 1][y] == 3 || cell[x][y + 1] & cell[x][y - 1] == 3) ||
				(x == 0 && cell[x + 1][y] == 3) ||
				(x == CELLSIZE_X - 1 && cell[x - 1][y] == 3) ||
				(y == 0 && cell[x][y + 1] == 3) ||
				(y == CELLSIZE_Y - 1 && cell[x][y - 1] == 3))
				cell[x][y] = 3;

			switch (cell[x][y])
			{
			case 0:
				change = pixel[y * CELLSIZE_X + x];
				break;
			case 1:
				if (draw_flag == 2)
				{
					change = pixel[y * CELLSIZE_X + x];
					cell[x][y] = 0;
					break;
				}

				change = D3DXCOLOR(0, 1, 0, 1);
				cell[x][y] = 2;

				coloring_cells++;
				break;
			case 2:
				change = D3DXCOLOR(0, 1, 0, 1);
				break;
			case 3:
				change = D3DXCOLOR(0, 0, 0, 0);
			}

			pixel[y * CELLSIZE_X + x] = change;
		}
	}

	bg->p->UnlockRect(0);

	if (draw_flag != 1)
		AutoFill();

	drawing = false;
}

int Player::FloodFill(V2 pos, int target, int change)
{
	if (target == change) return 1;
	if (cell[int(pos.x)][int(pos.y)] != target) return 2;
	if (int(pos.x) < 0 || int(pos.y) < 0 || int(pos.x) > CELLSIZE_X - 1 || int(pos.y) > CELLSIZE_Y - 1) return 3;

	queue<V2> v2q;

	bool add = false;
	temp = 0;

	if (change == 3)
		add = true;

	cell[int(pos.x)][int(pos.x)] = change;
	if (add)
		temp++;

	v2q.push(pos);

	while (!v2q.empty())
	{
		V2 n = v2q.front();
		v2q.pop();

		if (n.x == (int)(boss->pos.x - gap.x) && n.y == (int)(boss->pos.y - gap.y))
			return 4;

		if (cell[(int)n.x - 1][(int)n.y] == target)
		{
			cell[(int)n.x - 1][(int)n.y] = change;
			if (add)
				temp++;
			v2q.push({ n.x - 1, n.y });
		}
		if (cell[(int)n.x + 1][(int)n.y] == target)
		{
			cell[(int)n.x + 1][(int)n.y] = change;
			if (add)
				temp++;
			v2q.push({ n.x + 1, n.y });
		}
		if (cell[(int)n.x][(int)n.y - 1] == target)
		{
			cell[(int)n.x][(int)n.y - 1] = change;
			if (add)
				temp++;
			v2q.push({ n.x, n.y - 1 });
		}
		if (cell[(int)n.x][(int)n.y + 1] == target)
		{
			cell[(int)n.x][(int)n.y + 1] = change;
			if (add)
				temp++;
			v2q.push({ n.x, n.y + 1 });
		}
	}

	draw_mode = true;
	DrawArea(1);

	AddItem();

	coloring_cells += temp;

	float temp1 = coloring_cells * 100;
	coloring_per = temp1 / total_cell;

	return 0;
}

void Player::AutoFill()
{
	V2 value[4];
	int isOk[4] = { 0, };
	value[0] = { -1,-1 };
	value[1] = { 1,1 };
	value[2] = { -1,1 };
	value[3] = { 1,-1 };

	for (size_t i = 0; i < 4; i++)
	{
		temp_pos = { pos.x - gap.x + value[i].x ,pos.y - gap.y + value[i].y };
		isOk[i] = FloodFill(temp_pos, 0, 100);
		if (isOk[i] == 0)
		{
			FloodFill(temp_pos, 100, 3);
			break;
		}
		else
			FloodFill(temp_pos, 100, 0);
	}
}

void Player::AddItem()
{
	int temp_per = double(coloring_cells + temp) * 100 / total_cell - double(coloring_cells * 100) / total_cell;

	for (size_t i = 0; i < temp_per % 2; i++)
		OBJ->Add(new Item(RANDOM->INT(1, 5)), "Item")->pos = { float(RANDOM->INT(L + 1, R - 1)),float(RANDOM->INT(T + 1, B - 1)) };
}

void Player::NoDamage()
{
	during->Start();
	img = IMG->Add("player1");
}

bool Player::Near(KeyState dir, int target)
{
	int cx = pos.x - gap.x;
	int cy = pos.y - gap.y;

	switch (dir)
	{
	case KeyState::UP:
		return cell[cx][cy - 1] == target;
		break;
	case KeyState::DOWN:
		return cell[cx][cy + 1] == target;
		break;
	case KeyState::LEFT:
		return cell[cx - 1][cy] == target;
		break;
	case KeyState::RIGHT:
		return cell[cx + 1][cy] == target;
		break;
	}
}

int Player::Current()
{
	return cell[int(pos.x - gap.x)][int(pos.y - gap.y)];
}

//void Player::little_sleep(milliseconds us)
//{
//	auto start = high_resolution_clock::now();
//	auto end = start + us;
//	do {
//		this_thread::yield();
//	} while (high_resolution_clock::now() < end);
//}

//void Player::Flash(V2 v2)
//{
//	little_sleep(milliseconds(500));
//	for (size_t i = 0; i < 2; ++i)
//	{
//		FloodFill(temp_pos, 3, -1, true);
//		little_sleep(milliseconds(500));
//		FloodFill(temp_pos, -1, 3, true);
//		little_sleep(milliseconds(500));
//	}
//}
