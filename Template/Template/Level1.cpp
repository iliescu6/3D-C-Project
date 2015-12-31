#include "Level1.h"
#include "Texture.h"
#include <vector>
#include "Vector3f.h"
#include "CollisionDetection.h"

CLevel1::CLevel1()
{}

CLevel1::~CLevel1()
{}

void CLevel1::Initialise(CVector3f v)
{
	
	m_position = v;
	m_level.Load("Resources\\Meshes\\level1.obj");

	// Outter walls' bounding boxes
	
	m_boundingBox[0].Set(CVector3f(m_position.x+38.0f, m_position.y, m_position.z-40.0f), CVector3f (m_position.x+45.0f, m_position.y+10.0f,m_position.z+40.0f));	
	m_boundingBox[1].Set(CVector3f(m_position.x-40.0f , m_position.y, m_position.z +34.0f), CVector3f(m_position.x+40.0f, m_position.y + 10.0f, m_position.z + 40.0f));
	m_boundingBox[2].Set(CVector3f(m_position.x -45.0f, m_position.y, m_position.z - 40.0f), CVector3f(m_position.x - 38.0f, m_position.y + 10.0f, m_position.z + 40.0f));
	m_boundingBox[3].Set(CVector3f(m_position.x - 40.0f, m_position.y, m_position.z - 40.0f), CVector3f(m_position.x + 40.0f, m_position.y + 10.0f, m_position.z - 34.0f));

	//Top left L wall
	m_boundingBox[4].Set(CVector3f(m_position.x + 3.5f, m_position.y, m_position.z + 21.5f), CVector3f(m_position.x +31.2f, m_position.y + 10.0f, m_position.z + 27.8f));
	m_boundingBox[5].Set(CVector3f(m_position.x +3.5f , m_position.y, m_position.z +21.5f), CVector3f(m_position.x + 10.4f, m_position.y + 10.0f, m_position.z + 42.0f));

	//Top right L wall
	m_boundingBox[6].Set(CVector3f(m_position.x -31.2f, m_position.y, m_position.z +21.5f), CVector3f(m_position.x - 3.5f, m_position.y + 10.0f, m_position.z + 27.8f));
	m_boundingBox[7].Set(CVector3f(m_position.x -10.4f, m_position.y, m_position.z +21.5f), CVector3f(m_position.x - 3.5f, m_position.y + 10.0f, m_position.z + 42.0f));
	//Middle left L
	m_boundingBox[8].Set(CVector3f(m_position.x +3.5f, m_position.y, m_position.z -7.3f), CVector3f(m_position.x +10.4f, m_position.y + 10.0f, m_position.z +9.0f));
	m_boundingBox[9].Set(CVector3f(m_position.x +3.5f, m_position.y, m_position.z +3.0f), CVector3f(m_position.x + 31.2f, m_position.y + 10.0f, m_position.z + 9.8f));
	//Middle right L
	m_boundingBox[10].Set(CVector3f(m_position.x -10.4f, m_position.y, m_position.z -9.0f), CVector3f(m_position.x - 3.5f, m_position.y + 10.0f, m_position.z + 7.3f));
	m_boundingBox[11].Set(CVector3f(m_position.x -31.2f, m_position.y, m_position.z +3.0f), CVector3f(m_position.x -3.5f, m_position.y + 10.0f, m_position.z + 9.8f));
	//Middle left block
	m_boundingBox[12].Set(CVector3f(m_position.x +3.5f, m_position.y, m_position.z -9.5f), CVector3f(m_position.x + 39.0f, m_position.y + 10.0f, m_position.z -3.0f));
	m_boundingBox[13].Set(CVector3f(m_position.x +3.5f, m_position.y, m_position.z -15.0f), CVector3f(m_position.x + 31.2f, m_position.y + 10.0f, m_position.z - 9.5f));
	//Middle right block
	m_boundingBox[14].Set(CVector3f(m_position.x - 39.0f, m_position.y, m_position.z -9.5f), CVector3f(m_position.x - 3.5f, m_position.y + 10.0f, m_position.z - 3.0f));
	m_boundingBox[15].Set(CVector3f(m_position.x - 31.2f, m_position.y, m_position.z -15.0f), CVector3f(m_position.x - 3.5f, m_position.y + 10.0f, m_position.z - 9.5f));
	//Bottom Walls
	m_boundingBox[16].Set(CVector3f(m_position.x - 31.5f, m_position.y, m_position.z -27.5f), CVector3f(m_position.x + 31.5f, m_position.y + 10.0f, m_position.z -21.5f));
	m_boundingBox[17].Set(CVector3f(m_position.x - 3.5f, m_position.y, m_position.z -34.0f), CVector3f(m_position.x +3.5f, m_position.y + 10.0f, m_position.z - 27.5f));


}  

void CLevel1::Render()
{

	glPushMatrix();
	glTranslatef(m_position.x, m_position.y, m_position.z);
	glRotatef(180, 0, 1, 0);
	glScalef(4.5, 5, 4);
	m_level.Render();
	glPopMatrix();

}

CBoundingBox CLevel1::GetBoundingBox(int i)
{
	return m_boundingBox[i];
}

