#include "Pickup.h"
#include ".\include\glut.h"
CPickup::CPickup()
{}
CPickup::~CPickup()
{}
void CPickup::Initialise(CVector3f p)
{
	score_mesh.Load("Resources\\Meshes\\Crate\\Crate1.3ds");
	picked = false;
	m_isActive = true;
	m_theta = 0.0f;
	m_position = p;
}
void CPickup::Update(CVector3f c,int s)
{
	CVector3f d;
	d = m_position - c;
	if (d.Length() < 2){
		m_isActive = false;
		picked = true;
		score = 25;
		m_position = CVector3f(100, 100, 100);

	}

}
void CPickup::Render()
{

	if (m_isActive == true){
	glPushMatrix();
	glTranslatef(m_position.x, m_position.y, m_position.z);
	score_mesh.Render();
	glPopMatrix();
}
}

int CPickup::GetScore(){
	return score;
}

bool CPickup::Picked(){
	return picked;

}