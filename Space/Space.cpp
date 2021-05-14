#include"stdafx.h"
#include"GameScene.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
#if _DEBUG
	AllocConsole();
	FILE* stream;
	freopen_s(&stream, "CONOUT$", "wt", stdout);

#endif
	App::GetInst()->Init(1920, 1080, 1);
	SceneDirector::GetInst()->ChangeScene(new GameScene());
	App::GetInst()->Run();
	return 0;
}