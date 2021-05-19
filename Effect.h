#pragma once
class Effect
{
public:
	Effect(Texture* fx, V2 pos, int rot, int flag);
	void Render();
	bool IsFinished();

	Texture* fx;
	Timer* delay;
	V2 size, pos;

	int flag = 0, rot, alpha;
};

