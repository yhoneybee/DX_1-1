#include "DXUT.h"
#include "Player.h"

extern float time_scale;

int Player::cell[CELLSIZE_X][CELLSIZE_Y] = { 0, };
float Player::coloring_per = 0;

int Player::Nums(int num, int index)
{
	vector<int> nums;

	while (num != 0)
	{
		nums.emplace_back(num % 10);
		num /= 10;
	}

	return nums.size() <= index ? 0 : nums[index];
}

void Player::Init()
{
	ANIM->Add("Start", "START_", "")->Start(false);

	CAM->followable = true;
	CAM->Reset();
	CAM->scale = { 1.5,1.5,1.5 };

	idle = ANIM->Add("player_idle");
	idle->Start();
	boss = OBJ->Find("boss");
	bg = IMG->ReLoad("round1_before");
	bg_lower = IMG->Add("round1_after");
	img = IMG->Add("player");

	OBJ->Add(new MiniMap, "minimap");

	//gun = new Gun();

	memset(bg_color, D3DXCOLOR(0, 0, 0, 0), sizeof(bg_color));

	D3DLOCKED_RECT lr;
	bg->p->LockRect(0, &lr, 0, D3DLOCK_DISCARD);
	DWORD* pixel = (DWORD*)lr.pBits;

	for (int y = CELLSIZE_Y - 1; y != -1; --y)
		for (int x = CELLSIZE_X - 1; x != -1; --x)
			bg_color[x][y] = pixel[y * CELLSIZE_X + x];

	bg->p->UnlockRect(0);

	SetUp();

	main_col = new Col(this, P);
	during = TIME->Create(2);

	speed = 3;
	rot = 0;
	hp = 3;
	def = 0;
	title_a = 255;
	draw_mode = false;
	no_damage = false;

	//gun->SetDir(&dir);
}

void Player::Update()
{
	time -= DT;
	if (time < 0) SCENE->Set("fail");
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

	if (INPUT->Down(VK_SPACE))
		if (Current() == 2)
			drawing = !drawing;

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

	//if (INPUT->Down('Z'))
	//{
	//	gun->pattern = gun->pattern - 1 < 1 ? 1 : gun->pattern - 1;
	//}
	//if (INPUT->Down('X'))
	//{
	//	CAM->Shake(0.1f, 2);
	//	gun->SetPostiton(pos);
	//	gun->PatternStart();
	//}
	//if (INPUT->Down('C'))
	//{
	//	gun->pattern = gun->pattern + 1 > gun->GetMaxPattern() ? gun->GetMaxPattern() : gun->pattern + 1;
	//}

	if (INPUT->Down('X'))
	{
		ANIM->Add("Skill_anim", "Frame_", "")->Start(false, true);
	}
}

void Player::Render()
{
	main_col->Draw();
	bg_lower->Render();
	bg->Render(CENTER, ZERO, ONE, 0, 1, D3DCOLOR_RGBA(255, 255, 255, 255));
 	idle->Render(pos, ZERO, ONE / 2, atan2(dir.x, -dir.y));

	switch (key)
	{
	case Player::KeyState::UP: dir = { 0,-1 }; break;
	case Player::KeyState::DOWN: dir = { 0,1 }; break;
	case Player::KeyState::LEFT: dir = { -1,0 }; break;
	case Player::KeyState::RIGHT: dir = { 1,0 }; break;
	}

	IMG->Add("Start_BG")->Render(pos, ZERO, ONE, 0, 1, D3DCOLOR_RGBA(255, 255, 255, title_a));
	ANIM->Add("Start", "START_", "")->Render(pos, ZERO, ONE * 0.7, 0, 1, D3DCOLOR_RGBA(255, 255, 255, 255));

	title_a = (title_a - 10 < 0 ? 0 : title_a - 10);

	if (title_a > 0)
		return;

	char str[256];
	//-409 : -3
	// 1 : 99 = -406 : 0
	// 0 : 100 = -407 : 1
	//int value = 408 * (coloring_per / 100);
	//IMG->Add("gage_infill")->Render({ pos.x - 15,pos.y - 222 }, { -LONG(415 / 2),-LONG(47 / 2),LONG(415 / 2) - 410 + value,LONG(47 / 2) }, ONE, 0, 0);
	//IMG->Add("gage")->Render({ pos.x,pos.y - 250 }, ZERO, ONE, 0, 0);
	//IMG->Add("tik")->Render({ pos.x - 14.5f + (LONG(415 / 2) - 410 + value),pos.y - 200 }, ZERO, ONE, 0, 0);

	IMG->Add("score_ui")->Render({ pos.x,pos.y - 230 }, ZERO, ONE * 0.7, 0, 0);



	sprintf(str, "ST_%d", SCENE->round);
	IMG->Add(str)->Render({ pos.x + 440,pos.y - 260 });
	 
	V2 temp = { -210,-493 };

	sprintf(str, "number/%d", Nums(int(coloring_per), 1));
	IMG->Add(str)->Render({ pos.x + 340 + temp.x,pos.y + 260 + temp.y }, ZERO, ONE * 0.2, 0, 0);
	sprintf(str, "number/%d", Nums(int(coloring_per), 0));
	IMG->Add(str)->Render({ pos.x + 353 + temp.x,pos.y + 260 + temp.y }, ZERO, ONE * 0.2, 0, 0);

	IMG->Add("number/dot")->Render({ pos.x + 362 + temp.x,pos.y + 270 + temp.y }, ZERO, ONE * 0.2, 0, 0);

	sprintf(str, "number/%d", Nums(int(coloring_per * 10), 0));
	IMG->Add(str)->Render({ pos.x + 371 + temp.x,pos.y + 260 + temp.y }, ZERO, ONE * 0.2, 0, 0);

	sprintf(str, "number/%d", Nums(int(coloring_per * 100), 0));
	IMG->Add(str)->Render({ pos.x + 384 + temp.x,pos.y + 260 + temp.y }, ZERO, ONE * 0.2, 0, 0);

	//IMG->Add("Time_Text")->Render({ pos.x + 475,pos.y - 260 });
	//IMG->Add("bar")->Render({ pos.x + 450,pos.y - 240 });
	sprintf(str, "number/%d", Nums(int(time), 0));
	IMG->Add(str)->Render({ pos.x + 485 - 465,pos.y - 220 }, ZERO, ONE * 0.3, 0, 0);
	sprintf(str, "number/%d", Nums(int(time), 1));
	IMG->Add(str)->Render({ pos.x + 465 - 465,pos.y - 220 }, ZERO, ONE * 0.3, 0, 0);
	sprintf(str, "number/%d", Nums(int(time), 2));
	IMG->Add(str)->Render({ pos.x + 445 - 465,pos.y - 220 }, ZERO, ONE * 0.3, 0, 0);

	ANIM->Add("Skill_anim", "Frame_", "")->Render({ pos.x + 400,pos.y + 200 }, ZERO, ONE, 0, 0);

	switch (hp)
	{
	case 3:
		break;
	case 2:
		break;
	case 1:
		break;
	}
}

void Player::Release()
{
	SAFE_DELETE(main_col);
	//SAFE_DELETE(gun);
}

void Player::Enter(Col* p)
{
	switch (p->tag)
	{
	case EATK:
		if (Current() == 1 || Current() == 0)
		{
			hp--;
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
					change = bg_color[x][y];
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

	cell[int(pos.x)][int(pos.y)] = change;
	if (add) temp++;

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
			if (add) temp++;
			v2q.push({ n.x - 1, n.y });
		}
		if (cell[(int)n.x + 1][(int)n.y] == target)
		{
			cell[(int)n.x + 1][(int)n.y] = change;
			if (add) temp++;
			v2q.push({ n.x + 1, n.y });
		}
		if (cell[(int)n.x][(int)n.y - 1] == target)
		{
			cell[(int)n.x][(int)n.y - 1] = change;
			if (add) temp++;
			v2q.push({ n.x, n.y - 1 });
		}
		if (cell[(int)n.x][(int)n.y + 1] == target)
		{
			cell[(int)n.x][(int)n.y + 1] = change;
			if (add) temp++;
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
