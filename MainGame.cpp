#include "DXUT.h"
#include "MainGame.h"

void MainGame::Init()
{
	SCENE->Add(new LoadScene(), "load");
	SCENE->Add(new Title(1), "intro");
	SCENE->Add(new Title(2), "title");
	SCENE->Add(new Title(3), "cleartitle");
	SCENE->Add(new Ingame(1), "stage1");
	SCENE->Add(new Ingame(2), "stage2");
	SCENE->Add(new Ingame(3), "stage3");
	SCENE->Add(new End(1), "clear");
	SCENE->Add(new End(2), "fail");
	SCENE->Add(new End(3), "next");
	SCENE->Add(new End(4), "nextnext");
	SCENE->Add(new CreditScene, "credit");
	SCENE->Add(new DialogScene(1), "dialog1");
	SCENE->Add(new DialogScene(2), "dialog2");
	SCENE->Add(new DialogScene(3), "dialog3");
	SCENE->Add(new DialogScene(4), "dialog4");

	SCENE->Set("load");
}

void MainGame::Update()
{
	INPUT->Update();
	TIME->Update();
	CAM->Update();
	SCENE->Update();
	OBJ->Update();
	ANIM->Update();
}

void MainGame::Render()
{
	CAM->Apply();

	IMG->Begin();
	SCENE->Render();
	OBJ->Render();
	IMG->End();
}

void MainGame::Release()
{
	CamMgr::D();
	AnimMgr::D();
	ImgMgr::D();
	ObjMgr::D();
	HotKey::D();
	TimeMgr::D();
	SceneMgr::D();
	SoundMgr::D();
	InputMgr::D();
	UtillMgr::D();
}

void MainGame::Lost()
{
	IMG->Lost();
}

void MainGame::Reset()
{
	IMG->Reset();
}
