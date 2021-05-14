#pragma once
class SoundMgr2 :public Singleton<SoundMgr>
{
public:
	SoundMgr2();
	~SoundMgr2();

	void Play(const WCHAR* pFileName, bool loop);
	void Stop();
};

