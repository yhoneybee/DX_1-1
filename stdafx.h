#pragma once
#pragma comment(lib,"dsound.lib")
#include <iostream>
#include <random>
#include <list>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;
using V3 = D3DXVECTOR3;
using V2 = D3DXVECTOR2;
using M = D3DXMATRIX;

const int WINX = 1920;
const int WINY = 1080;
const V2 CENTER = { WINX / 2,WINY / 2 };
const int CELLSIZE = 1024;
const int L = CENTER.x - CELLSIZE / 2;
const int R = CENTER.x + CELLSIZE / 2;
const int T = CENTER.y - CELLSIZE / 2;
const int B = CENTER.y + CELLSIZE / 2;
const int x_gap = (WINX - CELLSIZE) / 2;
const int y_gap = (WINY - CELLSIZE) / 2;

const RECT RT_ZERO = { 0,0,0,0 };

static bool WIN = false;
static float time_scale = 1;
static int score = 0;

enum Tag
{
	TAG_BEGIN = -1,
	UI,
	MOUSE,
	P,
	PATK,
	E,
	EATK,
	OBS,
	ITEM,
	TAG_END,
};

#define DEVICE DXUTGetD3D9Device()
#define DT DXUTGetElapsedTime()
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)

#include "SDKsound.h"
#include "SDKwavefile.h"

//mgr
#include "st.h"
#include "CamMgr.h"
#include "ImgMgr.h"
#include "ObjMgr.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "RandomMgr.h"
#include "HotKey.h"
#include "InputMgr.h"

//GAME
#include "Item.h"
#include "Effect.h"
#include "ScrollMap.h"
#include "Bullet.h"

//UI
#include "Mouse.h"
#include "Button.h"
#include "Window.h"

//SCENE
#include "Title.h"
#include "Ingame.h"
#include "End.h"

//OBJ
#include "Player.h"
#include "Enemy.h"