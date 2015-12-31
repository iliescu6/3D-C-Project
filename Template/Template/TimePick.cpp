#include "TimePick.h"
#include ".\include\glut.h"
CTimePick::CTimePick()
{}
CTimePick::~CTimePick()
{}
void CTimePick::Initialise(CVector3f p)
{
	timemesh.Load("Resources\\Meshes\\Rock\\Rock.obj");
	picked = false;
	m_isActive = true;
	m_position = p;
}
void CTimePick::Update(CVector3f c, int s)
{
	CVector3f d;
	d = m_position - c;
	if (d.Length() < 2){
		m_isActive = false;
		picked = true;
		time = 20;
		m_position = CVector3f(100, 100, 100);

	}

}
void CTimePick::Render()
{

	if (m_isActive == true){
		glPushMatrix();
		glTranslatef(m_position.x, m_position.y, m_position.z);
		glScalef(1.5f,1.5f,1.5f);
		timemesh.Render();
		glPopMatrix();
	}
}

int CTimePick::GetTime(){
	return time;
}

bool CTimePick::Picked(){
	return picked;

}