#pragma once
class GameScene : public Scene
{
	Sprite* m_BG;
	Sprite* m_Game;

	TextMgr* m_Text;

public:
	GameScene();
	~GameScene();

	void Init();
	void Release();

	void Update(float deltaTime, float time);
	void Render();
};

