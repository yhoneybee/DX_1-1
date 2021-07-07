#pragma once
struct Sound
{
	CSound* p;
	Sound(CSound* p)
		:p(p) {}
	~Sound() { SAFE_DELETE(p); }

	void Play(bool loop);
	void Copy();
	void Stop();
};
class SoundMgr :
	public st<SoundMgr>
{
public:
	SoundMgr();
	~SoundMgr();

	Sound* Add(const string& key, const wstring& path);
	Sound* Find(const string& key);

	void Play(Sound* p, bool loop);
	void Copy(Sound* p);
	void Stop(Sound* p);

	LONG volume = DSBVOLUME_MAX;
	LONG frequency = DSBFREQUENCY_ORIGINAL;
	LONG pan = DSBPAN_CENTER;

	map<string, Sound*> sounds;
	CSoundManager* mgr;
};

#define SOUND SoundMgr::G()