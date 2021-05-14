#include "stdafx.h"
#include "Circle2.h"

Circle2::Circle2(float posx, float posy)
{
	m_Circle2 = Sprite::Create(L"Painting/Circle.png");
	m_Circle2->SetParent(this);
	SetPosition(posx, posy);

}

Circle2::~Circle2()
{
}

void Circle2::Render()
{
	m_Circle2->Render();
}

void Circle2::Release()
{
}

void Circle2::OnCollision(Object* other, std::string tag)
{
}

void Circle2::Update(float deltaTime, float Time)
{
	if (m_Position.y > 1080 / 2)
	{
		m_Position.y -= 250 * dt;
	}

	//노트속도

	if (m_Position.y < 620)
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

	if (INPUT->GetKey('S') == KeyState::DOWN && 645 <= m_Position.y && m_Position.y <= 725)
	{
		PlaySound(L"C:\\Sound\\HitSound.wav", NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
		
		if (685 <= m_Position.y && 695 >= m_Position.y)
		{
			GameMgr::GetInst()->m_Score += 200 * (GameMgr::GetInst()->m_Combo * 0.25);
			GameMgr::GetInst()->m_300++;
		}

		if (m_Position.y >= 675 && m_Position.y <= 705)
		{
			GameMgr::GetInst()->m_Score += 50 * (GameMgr::GetInst()->m_Combo * 0.25);
			GameMgr::GetInst()->m_100++;
		}

		if (m_Position.y >= 655 && m_Position.y <= 725)
		{
			GameMgr::GetInst()->m_Combo++;
			GameMgr::GetInst()->m_Score += 50 * (GameMgr::GetInst()->m_Combo * 0.25);
			GameMgr::GetInst()->m_50++;
			SetDestroy(true);
		}

		if (m_Position.y < 655 || m_Position.y > 725)
		{
			GameMgr::GetInst()->m_Score -= 0;
			GameMgr::GetInst()->m_miss++;
			GameMgr::GetInst()->m_Combo = 0;
			SetDestroy(true);
		}

		//판정
	}
}


