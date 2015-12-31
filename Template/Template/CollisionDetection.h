#pragma once
#include "Vector3f.h"
#include "BoundingBox.h"

class CCollisionDetection
{
public:
	CCollisionDetection();
	~CCollisionDetection();
	bool DoBoxesIntersect(CBoundingBox box1, CBoundingBox box2);

private:

};


