#include "stdafx.h"
#include "SoundMgr2.h"

SoundMgr2::SoundMgr2()
{
}

SoundMgr2::~SoundMgr2()
{
}

void SoundMgr2::Play(const WCHAR* pFileName, bool loop)
{
	WCHAR szFullPath[256] = L"../Sound/";
	lstrcatW(szFullPath, pFileName);

	if (!loop)
	{
		PlaySound(szFullPath, NULL, SND_ASYNC | SND_NOSTOP | SND_NODEFAULT | SND_FILENAME);
	}
	else if (loop)
	{
		PlaySound(szFullPath, NULL, SND_ASYNC | SND_LOOP | SND_NOSTOP | SND_NODEFAULT | SND_FILENAME);
	}
}

void SoundMgr2::Stop()
{
	PlaySound(nullptr, NULL, SND_ASYNC);
}
