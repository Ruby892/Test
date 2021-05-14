#pragma once
class GameMgr : public Singleton<GameMgr>
{
public:
	GameMgr(); //������
	~GameMgr(); //�Ҹ���

	void Render();
	void Release();
	void Update(float deltaTime, float Time);

public:
	int m_Combo; //�޺�
	int m_300; //300��
	int m_100; //100��
	int m_50; //50��
	int m_miss; //�̽�
	float m_acc; //��Ȯ��
	int m_Score;

	int m_offset;

	int y;

	int count;

};

