#pragma once
#include "stdafx.h"
class DialogScene :
	public Scene
{
public:
	DialogScene(int type) : type(type) {}

	Dialog* dialog = nullptr;

	int type;

	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

