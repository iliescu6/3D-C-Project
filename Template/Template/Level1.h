#pragma once

#include "OpenAssetImporterMesh.h"
#include <windows.h>									// Header File For The Windows Library
#include ".\include\gl.h"											// Header File For The OpenGL32 Library
#include "Texture.h"
#include "BoundingBox.h"
#include "Player.h"


class CLevel1
{
public:
	CLevel1();
	~CLevel1();
	void Initialise(CVector3f v);
	void Render();
	CBoundingBox GetBoundingBox(int i);
	CVector3f GetPosition();


private:
	CVector3f m_position;
	COpenAssetImporterMesh m_level;


private:
	CBoundingBox m_boundingBox[18];
	

};