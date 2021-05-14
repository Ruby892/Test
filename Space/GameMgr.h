#pragma once
class GameMgr : public Singleton<GameMgr>
{
public:
	GameMgr(); //생성자
	~GameMgr(); //소멸자

	void Render();
	void Release();
	void Update(float deltaTime, float Time);

public:
	int m_Combo; //콤보
	int m_300; //300점
	int m_100; //100점
	int m_50; //50점
	int m_miss; //미스
	float m_acc; //정확도
	int m_Score;

	int m_offset;

	int y;

	int count;

};

