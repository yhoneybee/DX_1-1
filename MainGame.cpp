#include "DXUT.h"
#include "MainGame.h"

void MainGame::Init()
{
	SCENE->Add(new LoadScene(), "load");
	SCENE->Add(new Title(1), "intro");
	SCENE->Add(new Title(2), "title");
	SCENE->Add(new Ingame(1), "stage1");
	SCENE->Add(new Ingame(2), "stage2");
	SCENE->Add(new End(1), "clear");
	SCENE->Add(new End(2), "fail");
	SCENE->Add(new End(3), "next");
	SCENE->Add(new CreditScene, "credit");
	SCENE->Add(new DialogScene(1), "dialog1");

	SCENE->Add(new ChangeScene("title"), "go_title");
	SCENE->Add(new ChangeScene("credit"), "go_credit");

	SCENE->Add(new ChangeScene("dialog1"), "go_dialog1");

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
	RandomMgr::D();
}

void MainGame::Lost()
{
	IMG->Lost();
}

void MainGame::Reset()
{
	IMG->Reset();
}
