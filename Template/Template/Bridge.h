#pragma once
#include <windows.h>
#include "Vector3f.h"

class CBridge
{
public:
	CBridge();
	~CBridge();
	void Initialise();
	void Update(float dt);
	void Render(float x, float y, float z, float a);
	//CVector3f Cross(CVector3f v,CVector3f);

private:
	UINT m_textureID;
};