#pragma once
#include "stdafx.h"
class DialogScene :
	public Scene
{
public:
	DialogScene(int type) : type(type) {}

	Dialog* dialog = nullptr;

	int type;

	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

