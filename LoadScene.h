#pragma once
#include "stdafx.h"

struct LoadInfo
{
	LoadInfo(const string& name, const string& before = "default", const string& after = "default")
		:name(name), before(before), after(after) {}

	string name;
	string before;
	string after;
};

class LoadScene :
	public Scene
{
public:
	list<LoadInfo> loads;

	int load_count;

	void AddImg(const string& name);
	void AddAnim(const string& name, const string& before = "(", const string& after = ")");

	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

