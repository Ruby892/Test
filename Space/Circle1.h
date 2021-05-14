#pragma once
class Circle1 : public Object
{
	Sprite* m_Circle1;

public:
	Circle1(float posx, float posy);
	~Circle1();

	void Render();
	void Release();
	void OnCollision(Object* other, std::string tag);
	void Update(float deltaTime, float Time);
};

