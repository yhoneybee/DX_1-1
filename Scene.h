#pragma once
class Scene
{
public:
	Scene() { ; };
	virtual ~Scene() { ; };

	bool inited = false;

	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
};

