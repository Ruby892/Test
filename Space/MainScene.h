#pragma once

class MainScene : public Scene
{
	Sprite* m_BG;
	Sprite* m_Ga;
	Sprite* m_Pan;
	Sprite* m_Pan1;
	Sprite* m_Pan2;
	Sprite* m_Pan3;

	TextMgr* m_Text;
public:
	MainScene();
	~MainScene();

	int Note;
	int Bote;
	int Bote1;
	int Bote2;
	int Bote3;
	int Bote4;
	int time;
	int m_Count1;
	int m_Count2;
	int m_Count3;
	int i = 0;
	int j = 0;

	float m_1;
	float m_2;
	int m_3;
	int m_4;
	int Count;

	float m_NowTick;
	float m_LastTick;
	float m_Delay;

	float Offset;

	void Init();
	void Release();

	void Update(float deltaTime, float time);
	void Render();
};