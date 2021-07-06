#pragma once
#include "stdafx.h"
struct Script
{
public:
	Script(const string& l1 = "", const string& l2 = "", const string& l3 = "", const string& l4 = "", const string& l5 = "")
		:l1(l1), l2(l2), l3(l3), l4(l4), l5(l5) {}

	string l1;
	string l2;
	string l3;
	string l4;
	string l5;
};

//struct Chater
//{
//	Chater(Texture* texture, V2 pos = CENTER, float alpha = 1)
//		:texture(texture), pos(pos), alpha(alpha) {}
//
//	Texture* texture;
//	V2 pos;
//	float alpha;
//};

enum class ChatType
{
	LINA2ME,
	ME2LINA,
	TRICKSTER2ME,
	ME2TRICKSTER,
};

class Dialog :
	public Obj
{
public:
//	Dialog(Texture* chater1_texture, Texture* chater2_texture)
//		:chater1(chater1_texture), chater2(chater1_texture) {}
//	Dialog(const string& chater1, const string& chater2)
//		:chater1(IMG->Add(chater1)), chater2(IMG->Add(chater2)) {}

	Texture* bg = nullptr;
	Texture* chat_bg = nullptr;
	// /*총 대본*/ < 한번의 대화에 사용되는 대본 >
	vector<Script> scripts;
	int index = 0;

	//Chater chater1, chater2;

	vector<ChatType> chat_types;

	string go_scene;

	// Obj을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void Enter(Col* p) override;
	virtual void Stay(Col* p) override;
	virtual void Exit(Col* p) override;
};

