#pragma once
#include "BoundingBox.h"
#include "float.h"
#include <windows.h>									// Header File For The Windows Library
#include ".\include\gl.h"								// Header File For The OpenGL32 Library
#include <math.h>


CBoundingBox::CBoundingBox()
{
	m_isValid = false;
	m_xmin = FLT_MAX;
	m_ymin = FLT_MAX;
	m_zmin = FLT_MAX;
	m_xmax = -FLT_MAX;
	m_ymax = -FLT_MAX;
	m_zmax = -FLT_MAX;

}

void CBoundingBox::Set(CVector3f minPoint, CVector3f maxPoint)
{
	m_isValid = true;
	m_xmin = minPoint.x;
	m_ymin = minPoint.y;
	m_zmin = minPoint.z;
	m_xmax = maxPoint.x;
	m_ymax = maxPoint.y;
	m_zmax = maxPoint.z;

}


void CBoundingBox::Translate(CVector3f t)
{
	m_isValid = true;
	m_xmin += t.x;
	m_ymin += t.y;
	m_zmin += t.z;
	m_xmax += t.x;
	m_ymax += t.y;
	m_zmax += t.z;

}

CBoundingBox::~CBoundingBox()
{}




bool CBoundingBox::GetSizeAndCentre(float &dx, float &dy, float &dz, CVector3f &centre)
{
	if (m_isValid == false)
		return false;

	dx = m_xmax - m_xmin;
	dy = m_ymax - m_ymin;
	dz = m_zmax - m_zmin;
	centre.x = m_xmin + dx / 2.0f;
	centre.y = m_ymin + dy / 2.0f;
	centre.z = m_zmin + dz / 2.0f;


	return true;

}


void CBoundingBox::Render(float r, float g, float b)
{
	
	if (m_isValid == false)
		return;

	glColor3f(r, g, b);
	glBegin(GL_LINE_LOOP);
	glVertex3f(m_xmin, m_ymin, m_zmin);
	glVertex3f(m_xmax, m_ymin, m_zmin);
	glVertex3f(m_xmax, m_ymax, m_zmin);
	glVertex3f(m_xmin, m_ymax, m_zmin);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(m_xmin, m_ymin, m_zmax);
	glVertex3f(m_xmax, m_ymin, m_zmax);
	glVertex3f(m_xmax, m_ymax, m_zmax);
	glVertex3f(m_xmin, m_ymax, m_zmax);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(m_xmin, m_ymin, m_zmin);
	glVertex3f(m_xmin, m_ymin, m_zmax);
	glVertex3f(m_xmax, m_ymin, m_zmin);
	glVertex3f(m_xmax, m_ymin, m_zmax);
	glVertex3f(m_xmax, m_ymax, m_zmin);
	glVertex3f(m_xmax, m_ymax, m_zmax);
	glVertex3f(m_xmin, m_ymax, m_zmin);
	glVertex3f(m_xmin, m_ymax, m_zmax);
	glEnd();

}



bool CBoundingBox::Collision(CBoundingBox otherBox)
{
	float width1, height1, depth1, width2, height2, depth2;
	CVector3f centre1, centre2;
	GetSizeAndCentre(width1, height1, depth1, centre1);
	otherBox.GetSizeAndCentre(width2, height2, depth2, centre2);

	CVector3f v = centre2 - centre1;
	if (fabs(v.x) * 2 <= (width1 + width2) && 
        fabs(v.y) * 2 <= (height1 + height2) && 
        fabs(v.z) * 2 <= (depth1 + depth2))
		return true; // Collision detected
	else
		return false; // No collision detected
}




