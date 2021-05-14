#include "stdafx.h"
#include "Circle3.h"

Circle3::Circle3(float posx, float posy)
{
	m_Circle3 = Sprite::Create(L"Painting/Circle1.png");
	m_Circle3->SetParent(this);
	SetPosition(posx, posy);

}

Circle3::~Circle3()
{
}

void Circle3::Render()
{
	m_Circle3->Render();
}

void Circle3::Release()
{
}

void Circle3::OnCollision(Object* other, std::string tag)
{
}

void Circle3::Update(float deltaTime, float Time)
{
	if (m_Position.x > 1920 / 2)
	{
		m_Position.x -= 250 * dt;
	}

	//노트속도

	if (m_Position.x < 1040)
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

	if (INPUT->GetKey('L') == KeyState::DOWN && 1065 <= m_Position.x && m_Position.x <= 1155)
	{
		PlaySound(L"C:\\Sound\\HitSound.wav", NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);

		if (1105 <= m_Position.x && 1115 >= m_Position.x)
		{
			GameMgr::GetInst()->m_Score += 200 * (GameMgr::GetInst()->m_Combo * 0.25);
			GameMgr::GetInst()->m_300++;
		}

		if (m_Position.x >= 1095 && m_Position.x <= 1125)
		{
			GameMgr::GetInst()->m_Score += 50 * (GameMgr::GetInst()->m_Combo * 0.25);
			GameMgr::GetInst()->m_100++;
		}

		if(m_Position.x >= 1075 && m_Position.x <=1145)
		{
			GameMgr::GetInst()->m_Combo++;
			GameMgr::GetInst()->m_Score += 50 * (GameMgr::GetInst()->m_Combo * 0.25);
			GameMgr::GetInst()->m_50++;
			SetDestroy(true);
		}

		if (m_Position.x < 1075 || m_Position.x > 1145)
		{
			GameMgr::GetInst()->m_Score -= 0;
			GameMgr::GetInst()->m_miss++;
			GameMgr::GetInst()->m_Combo = 0;
			SetDestroy(true);
		}

		//판정
	}
}
