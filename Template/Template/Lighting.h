#pragma once

#include ".\include\glut.h"	
#include "Vector3f.h"




class CLighting
{
public:
	void Initialise();
	void SetLights(CVector3f v0, CVector3f v1, CVector3f v2, CVector3f v3, CVector3f v4 ); //Create Lighting Effects
	void SetPlayerLight(CVector3f v);
	void ChangeColor(int i,float r,float b);
	float r[5];
	float g[5];

private:

};

