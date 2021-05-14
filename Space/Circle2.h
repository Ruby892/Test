#pragma once
class Circle2 : public Object
{
	Sprite* m_Circle2;

public:
	Circle2(float posx, float posy);
	~Circle2();

	void Render();
	void Release();
	void OnCollision(Object* other, std::string tag);
	void Update(float deltaTime, float Time);
};

