#pragma once
class Circle : public Object
{
	Sprite* m_Circle;

public:
	Circle(float posx, float posy);
	~Circle();

	void Render();
	void Release();
	void OnCollision(Object* other, std::string tag);
	void Update(float deltaTime, float Time);
};

