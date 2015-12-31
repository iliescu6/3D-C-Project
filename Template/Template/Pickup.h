#pragma once
#include "Vector3f.h"
#include "OpenAssetImporterMesh.h"

class CPickup
{
public:
	CPickup();
	~CPickup();
	void Initialise(CVector3f p);
	void Update(CVector3f c,int s);
	void Render();
	int GetScore();
	bool Picked();
private:
	int score;
	bool m_isActive; // Indicates if pickup is active
	bool picked;
	CVector3f m_position; // Pickup position in 3D
	float m_theta; // Rotation angle
	COpenAssetImporterMesh score_mesh;
};