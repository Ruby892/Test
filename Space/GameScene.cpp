#include "stdafx.h"
#include "GameScene.h"
#include "MainScene.h"

GameScene::GameScene()
{
	
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	m_BG = Sprite::Create(L"Painting/BG/BG.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);
	
	m_Game = Sprite::Create(L"Painting/BG/Game1.png");
	m_Game->SetPosition(1920 / 2, 1080 / 2);

	m_Text = new TextMgr();
	m_Text->Init(32, true, false, "Arial");
	m_Text->SetColor(255, 255, 255, 255);
}

void GameScene::Release()
{
}

void GameScene::Update(float deltaTime, float time)
{
	if (CollisionMgr::GetInst()->MouseWithBoxSize(m_Game) && INPUT->GetButtonDown())
	{
		SceneDirector::GetInst()->ChangeScene(new MainScene());
		INPUT->ButtonDown(false);
		GameMgr::GetInst()->y = 0;
	}
}

void GameScene::Render()
{
	m_BG->Render();
	m_Game->Render();

	if (INPUT->GetKey(VK_F3) == KeyState::DOWN)
	{
		GameMgr::GetInst()->m_offset += 1;
	}

	if (INPUT->GetKey(VK_F4) == KeyState::DOWN)
	{
		GameMgr::GetInst()->m_offset -= 1;
	}

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);

	m_Text->print("\n\n                                                                                                                Offset : " + std::to_string(GameMgr::GetInst()->m_offset), 0, 0);

	Renderer::GetInst()->GetSprite()->End();
}

