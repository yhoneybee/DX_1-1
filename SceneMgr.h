#pragma once
#include "Scene.h"
class SceneMgr :
    public st<SceneMgr>
{
public:
    SceneMgr() { ; };
    ~SceneMgr();

    void Add(Scene* p, const string& key);
    void Set(const string& key);

    void Update();
    void Render();

    int round = 0;

    map<string, Scene*> scenes;
    Scene* now = nullptr;
};

#define SCENE SceneMgr::G()