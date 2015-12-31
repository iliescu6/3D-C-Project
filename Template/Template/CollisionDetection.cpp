#include "CollisionDetection.h"
#include <math.h>

CCollisionDetection::CCollisionDetection()
{}

CCollisionDetection::~CCollisionDetection()
{}

bool CCollisionDetection::DoBoxesIntersect(CBoundingBox box1, CBoundingBox box2)
{
	float width1, height1, depth1, width2, height2, depth2;
	CVector3f centre1, centre2;
	box1.GetSizeAndCentre(width1, height1, depth1, centre1);
	box2.GetSizeAndCentre(width2, height2, depth2, centre2);

	CVector3f v = centre2 - centre1;
	if (fabs(v.x) * 2 <= (width1 + width2) &&
		fabs(v.y) * 2 <= (height1 + height2) &&
		fabs(v.z) * 2 <= (depth1 + depth2))
		return true; // Collision detected
	else
		return false; // No collision detected
}
