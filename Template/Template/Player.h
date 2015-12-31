#pragma once
#include <windows.h>
#include "Vector3f.h"
#include "Camera.h"
#include "MD2Animation.h"
#include "BoundingBox.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "include/gl.h"

#define YOKHO_IDLE 0
#define YOHKO_RUN 1
#define YOHKO_ATTACK 2

class CPlayer
{
public:
	CPlayer();
	~CPlayer();
	void Update(float dt);
	void Initialise();
	void Render();
	void UpdateCamera(Camera &camera); // Update camera based on player
	void Advance(float speed);
	void MoveForward(float speed);
	void Strafe(float speed);
	void BasicMovement(double dt);
	void SetAnimation(int i);
	void ZeroAccelerate();

	void SetPosition(CVector3f);
	CVector3f GetPosition();

	CBoundingBox GetBoundingBox();
	CVector3f GetStrafeVector() const;
private:
	CVector3f m_position; // Position of player
	CVector3f prevPos;
	CVector3f m_direction; // Direction they are facing
	CVector3f m_strafeVector;
	float m_speed; // Player speed
	CMD2Model m_player; // Mesh representing player
	CBoundingBox m_boundingBox;
	float accelerate;

};