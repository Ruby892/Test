#include "stdafx.h"
#include "Circle.h"
#include "MainScene.h"
#include "GameScene.h"

Circle::Circle(float posx, float posy)
{
	m_Circle = Sprite::Create(L"Painting/Circle.png");
	m_Circle->SetParent(this);
	SetPosition(posx, posy);

}

Circle::~Circle()
{
}

void Circle::Render()
{
	m_Circle->Render();
}

void Circle::Release()
{
}

void Circle::OnCollision(Object* other, std::string tag)
{
}

void Circle::Update(float deltaTime, float Time)
{
	

	if (m_Position.y < 1080 / 2)
	{
		m_Position.y += 250 * dt;
	}

	//노트속도

	if (m_Position.y > 460)
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

	if (INPUT->GetKey('A') == KeyState::DOWN && 345 <= m_Position.y && m_Position.y <= 435)
	{
		PlaySound(L"C:\\Sound\\HitSound.wav", NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);

		GameMgr::GetInst()->count++;

		if (385 <= m_Position.y && 395 >= m_Position.y)
		{
			GameMgr::GetInst()->m_Score += 200 * (GameMgr::GetInst()->m_Combo * 0.25);
			GameMgr::GetInst()->m_300++;
		}
			
		if (m_Position.y >= 375 && m_Position.y <= 405)
		{
			GameMgr::GetInst()->m_Score += 50 * (GameMgr::GetInst()->m_Combo * 0.25);
			GameMgr::GetInst()->m_100++;
		}

		if (m_Position.y >= 355 && m_Position.y <= 425)
		{
			GameMgr::GetInst()->m_Combo++;
			GameMgr::GetInst()->m_Score += 50 * (GameMgr::GetInst()->m_Combo * 0.25);
			GameMgr::GetInst()->m_50++;
			SetDestroy(true);
			
		}

		if (m_Position.y < 355 || m_Position.y > 425)
		{
			GameMgr::GetInst()->m_Score -= 0;
			GameMgr::GetInst()->m_miss++;
			GameMgr::GetInst()->m_Combo = 0;
			SetDestroy(true);
		}

		//판정
	}

}



