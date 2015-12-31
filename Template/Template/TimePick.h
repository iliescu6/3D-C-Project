#pragma once
#include "Vector3f.h"
#include "OpenAssetImporterMesh.h"
class CTimePick
{
public:
	CTimePick();
	~CTimePick();
	void Initialise(CVector3f p);
	void Update(CVector3f c, int s);
	void Render();
	int GetTime();
	bool Picked();
private:
	int time;
	bool m_isActive; // Indicates if pickup is active
	bool picked;
	CVector3f m_position; // Pickup position in 3D
	COpenAssetImporterMesh timemesh;

};