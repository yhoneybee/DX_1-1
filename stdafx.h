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
#include <mutex>
#include <chrono>
#include <future>
#include <condition_variable>
#include <cstdio>

using namespace std;
using namespace std::chrono;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;
using V3 = D3DXVECTOR3;
using V2 = D3DXVECTOR2;
using M = D3DXMATRIX;

const int WINX = 1600;
const int WINY = 900;
const V2 CENTER = { WINX / 2,WINY / 2 };
const int CELLSIZE_X = 1600;
const int CELLSIZE_Y = 900;
const int L = CENTER.x - CELLSIZE_X / 2;
const int R = CENTER.x + CELLSIZE_X / 2;
const int T = CENTER.y - CELLSIZE_Y / 2;
const int B = CENTER.y + CELLSIZE_Y / 2;
const V2 gap = { (WINX - CELLSIZE_X) / 2 ,(WINY - CELLSIZE_Y) / 2 };

const RECT ZERO = { 0,0,0,0 };
const V2 ONE = { 1,1 };
const D3DXCOLOR MAX = D3DXCOLOR(1, 1, 1, 1);

const bool DrawDebug = false;

static bool WIN = true;
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

enum BulletCase
{
	CRICLE,
	SHURIKEN,
	HURRICANE,
	CROSS,
	BULB,
};

#define DEVICE DXUTGetD3D9Device()
#define DT DXUTGetElapsedTime()
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)

#include "SDKsound.h"
#include "SDKwavefile.h"

#include "ThreadPool.h"

//mgr
#include "st.h"
#include "TimeMgr.h"
#include "ImgMgr.h"
#include "AnimMgr.h"
#include "ObjMgr.h"
#include "CamMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "UtillMgr.h"
#include "HotKey.h"
#include "InputMgr.h"

//GAME
#include "Item.h"
#include "Effect.h"
#include "ScrollMap.h"
#include "Gun.h"
#include "Bullet.h"

//UI
#include "Mouse.h"
#include "Button.h"
#include "Window.h"
#include "Dialog.h"
#include "ChangeEffect.h"


//SCENE
#include "LoadScene.h"
#include "Title.h"
#include "Ingame.h"
#include "End.h"
#include "DialogScene.h"
#include "CreditScene.h"

//OBJ
#include "MiniMap.h"
#include "Player.h"
#include "Enemy.h"