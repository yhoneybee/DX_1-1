#pragma once
struct Sound
{
	CSound* p;
	Sound(CSound* p)
		:p(p) {}
	~Sound() { SAFE_DELETE(p); }

	/// <summary>
	/// 
	/// </summary>
	/// <param name="loop"></param>
	/// <param name="volume">0 ~ -10000</param>
	/// <param name="frequency">0 ~ 200000</param>
	/// <param name="pan">-10000 ~ 10000</param>
	void Play(bool loop, LONG volume = DSBVOLUME_MAX, LONG frequency = DSBFREQUENCY_ORIGINAL, LONG pan = DSBPAN_CENTER);
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

	/// <summary>
	/// 
	/// </summary>
	/// <param name="p"></param>
	/// <param name="loop"></param>
	/// <param name="volume">0 ~ -10000</param>
	/// <param name="frequency">0 ~ 200000</param>
	/// <param name="pan">-10000 ~ 10000</param>
	void Play(Sound* p, bool loop, LONG volume = DSBVOLUME_MAX, LONG frequency = DSBFREQUENCY_ORIGINAL, LONG pan = DSBPAN_CENTER);
	void Copy(Sound* p);
	void Stop(Sound* p);

	map<string, Sound*> sounds;
	CSoundManager* mgr;
};

#define SOUND SoundMgr::G()