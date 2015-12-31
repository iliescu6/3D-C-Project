#pragma once
#include <windows.h>

class CRamp
{
public:
	CRamp();
	~CRamp();
	void Initialise();
	void Render(float an,float x, float y, float z, float a);

private:
	UINT m_textureID;
};