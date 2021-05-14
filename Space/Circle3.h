#pragma once
class Circle3 : public Object
{
	Sprite* m_Circle3;

public:
	Circle3(float posx, float posy);
	~Circle3();

	void Render();
	void Release();
	void OnCollision(Object* other, std::string tag);
	void Update(float deltaTime, float Time);
};

