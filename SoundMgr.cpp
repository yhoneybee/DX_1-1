#include "DXUT.h"
#include "SoundMgr.h"

Sound* Sound::SetVolume(LONG volume)
{
	SOUND->SetVolume(this, volume);
	return this;
}

Sound* Sound::SetFrequency(LONG frequency)
{
	SOUND->SetFrequency(this, frequency);
	return this;
}

Sound* Sound::SetPan(LONG pan)
{
	SOUND->SetPan(this, pan);
	return this;
}

void Sound::Play(bool loop)
{
	SOUND->Play(this, loop);
}

void Sound::Copy()
{
	SOUND->Copy(this);
}

void Sound::Stop()
{
	SOUND->Stop(this);
}

SoundMgr::SoundMgr()
{
	mgr = new CSoundManager;
	mgr->Initialize(DXUTGetHWND(), 2);
}

SoundMgr::~SoundMgr()
{
	for (auto& i : sounds)
		SAFE_DELETE(i.second);
	sounds.clear();
	SAFE_DELETE(mgr);
}

Sound* SoundMgr::Add(const string& key, const wstring& path)
{
	auto f = sounds.find(key);
	if (f == sounds.end())
	{
		wchar_t wstr[256];
		swprintf(wstr, L"./Resource/sound/%s.wav", path.c_str());
		CSound* cs;
		mgr->Create(&cs, wstr, DSBCAPS_CTRLPAN | DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLFREQUENCY);
		Sound* s = new Sound(cs);
		sounds[key] = s;
		return s;
	}
	return f->second;
}

Sound* SoundMgr::Find(const string& key)
{
	auto f = sounds.find(key);
	if (f != sounds.end())
		return f->second;
	return nullptr;
}

void SoundMgr::Play(Sound* p, bool loop)
{
	if (p)
		p->p->Play(0, loop);
}

void SoundMgr::Copy(Sound* p)
{
	if (p)
	{
		LPDIRECTSOUNDBUFFER buf;
		mgr->GetDirectSound()->DuplicateSoundBuffer(p->p->GetBuffer(0), &buf);
		buf->SetCurrentPosition(0);
		buf->Play(0, 0, 0);
	}
}

void SoundMgr::Stop(Sound* p)
{
	if (p)
		p->p->Stop();
}

Sound* SoundMgr::SetVolume(Sound* p, LONG volume)
{
	if (p)
		p->p->GetBuffer(0)->SetVolume(volume);
	return p;
}

Sound* SoundMgr::SetFrequency(Sound* p, LONG frequency)
{
	if (p)
		p->p->GetBuffer(0)->SetFrequency(frequency);
	return p;
}

Sound* SoundMgr::SetPan(Sound* p, LONG pan)
{
	if (p)
		p->p->GetBuffer(0)->SetPan(pan);
	return p;
}
