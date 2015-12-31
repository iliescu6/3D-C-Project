#pragma once
#include <windows.h>

class Crystal
{
public:
	Crystal();
	~Crystal();
	void Initialise();
	void Update(float dt);
	void Render(float x,float y,float z,float a);

private:
	UINT m_textureID;
	float theta;
};