#pragma once
#include "Vector3f.h"


class CBoundingBox
{
public:
	CBoundingBox();
	~CBoundingBox();
	bool GetSizeAndCentre(float &dx, float &dy, float &dz, CVector3f &centre);
	void Render(float r, float g, float b);
	void Set(CVector3f minPoint, CVector3f maxPoint);
	void Translate(CVector3f t);
	bool Collision(CBoundingBox otherBox);
private:
	bool m_isValid;
	float m_xmin;
	float m_ymin;
	float m_zmin;
	float m_xmax;
	float m_ymax;
	float m_zmax;
};


