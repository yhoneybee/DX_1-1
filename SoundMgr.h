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
	Sound* SetVolume(LONG volume = DSBVOLUME_MAX);
	Sound* SetFrequency(LONG frequency = DSBFREQUENCY_ORIGINAL);
	Sound* SetPan(LONG pan = DSBPAN_CENTER);
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
	Sound* SetVolume(Sound* p, LONG volume = DSBVOLUME_MAX);
	Sound* SetFrequency(Sound* p, LONG frequency = DSBFREQUENCY_ORIGINAL);
	Sound* SetPan(Sound* p, LONG pan = DSBPAN_CENTER);

	map<string, Sound*> sounds;
	CSoundManager* mgr;
};

#define SOUND SoundMgr::G()