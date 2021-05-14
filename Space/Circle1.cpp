#include "stdafx.h"
#include "Circle1.h"

Circle1::Circle1(float posx, float posy)
{
	m_Circle1 = Sprite::Create(L"Painting/Circle1.png");
	m_Circle1->SetParent(this);
	SetPosition(posx, posy);

}

Circle1::~Circle1()
{
}

void Circle1::Render()
{
	m_Circle1->Render();
}

void Circle1::Release()
{
}

void Circle1::OnCollision(Object* other, std::string tag)
{
}

void Circle1::Update(float deltaTime, float Time)
{

	if (m_Position.x < 1920 / 2)
	{
		m_Position.x += 250 * dt;
	}

	//노트속도

	if (m_Position.x > 880)
	{
		GameMgr::GetInst()->m_Score -= 0;
		GameMgr::GetInst()->m_miss++;
		GameMgr::GetInst()->m_Combo = 0;
		SetDestroy(true);
	}

	if (GameMgr::GetInst()->y == 1)
	{
		SetDestroy(true);
	}

	if (INPUT->GetKey('K') == KeyState::DOWN && 765 <= m_Position.x && m_Position.x <= 855)
	{
		PlaySound(L"C:\\Sound\\HitSound.wav", NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);

		if (805 <= m_Position.x && 815 >= m_Position.x)
		{
			GameMgr::GetInst()->m_Score += 200 * (GameMgr::GetInst()->m_Combo * 0.25);
			GameMgr::GetInst()->m_300++;
		}

		if (m_Position.x >= 795 && m_Position.x <= 825)
		{
			GameMgr::GetInst()->m_Score += 50 * (GameMgr::GetInst()->m_Combo * 0.25);
			GameMgr::GetInst()->m_100++;
		}

		if (m_Position.x >= 775 && m_Position.x <= 845)
		{
			GameMgr::GetInst()->m_Combo++;
			GameMgr::GetInst()->m_Score += 50 * (GameMgr::GetInst()->m_Combo * 0.25);
			GameMgr::GetInst()->m_50++;
			SetDestroy(true);
		}

		if (m_Position.x < 775 || m_Position.x > 845)
		{
			GameMgr::GetInst()->m_Score -= 0;
			GameMgr::GetInst()->m_miss++;
			GameMgr::GetInst()->m_Combo = 0;
			SetDestroy(true);
		}

		//판정
	}
}




