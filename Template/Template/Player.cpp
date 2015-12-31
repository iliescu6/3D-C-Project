#include "Player.h"

CPlayer::CPlayer()
{
	
}

CPlayer::~CPlayer()
{}

void CPlayer::Update(float dt){
	prevPos = m_position;
	BasicMovement(dt);

	m_boundingBox.Set(m_position - CVector3f(1.0, 2.0,1.0), m_position + CVector3f(1.0, 2.0, 1.0));
}

void CPlayer::MoveForward(float speed)
{
	m_position += CVector3f(0,0,1) * speed;
	m_direction += CVector3f(0, 0, 1) * speed;
}



void CPlayer::Strafe(float speed)
{
	m_position += CVector3f(1, 0, 0) * speed;
	m_direction += CVector3f(1, 0, 0) * speed;

	
}

void CPlayer::Initialise(){
	m_position = CVector3f(0.0f, 8.0f, 30.0f);
	m_direction = CVector3f(0, 0, 1);
	m_speed = 5.0;

	m_boundingBox.Set(m_position - CVector3f(1.0, 2.0, 1.0), m_position + CVector3f(1.0, 2.0, 1.0));
	m_player.Load("./Resources/Meshes/Yohko.md2", "./Resources/Meshes/Yohko.bmp",
		"./Resources/Meshes/YohkoWeapon.md2", "./Resources/Meshes/YohkoWeapon.bmp");

	/*	m_player.Load("./Resources/Meshes/modelpack15/pilot/body.md2", "./Resources/Meshes/modelpack15/pilot/pilot_body.bmp",
		"./Resources/Meshes/modelpack15/pilot/head.md2", "./Resources/Meshes/modelpack15/pilot/pilot_head.bmp");*/

}



void CPlayer::Render(){

	float theta;
	glPushMatrix();
	glTranslatef(m_position.x,m_position.y,m_position.z);
	glScalef(0.1f,0.1f,0.1f);
	theta = atan2(m_direction.z, m_direction.x)*(180.0f / M_PI);
	glRotatef(-theta, 0, 1, 0);
	m_player.Render(true);
	glPopMatrix();

}


void CPlayer::BasicMovement(double dt)
{
	
	float speed = (float)dt * m_speed+ accelerate*dt;

	if ((GetKeyState(VK_UP) & 0x80 || GetKeyState('W') & 0x80)) {
		MoveForward(speed+accelerate);	// Forward
		m_direction = CVector3f(0, 0, 1);
		accelerate += 0.1*dt;
		if (accelerate > 0.5){ accelerate = 0.5; }
		if (m_player.GetAnimation() != YOHKO_RUN ) {
			m_player.SetAnimation(YOHKO_RUN);
		}
		
	}


	if ((GetKeyState(VK_DOWN) & 0x80 || GetKeyState('S') & 0x80)) {
		MoveForward(-speed-accelerate);	// Backward
		m_direction = CVector3f(0, 0, -1);
		accelerate += 0.1*dt;
		if (accelerate > 1){ accelerate = 1; }
		if (m_player.GetAnimation() != YOHKO_RUN ) {
			m_player.SetAnimation(YOHKO_RUN);
		}
	}

	if ((GetKeyState(VK_LEFT) & 0x80 || GetKeyState('A') & 0x80)) {
		Strafe(speed+accelerate); // Left
		m_direction = CVector3f(1,0,0);
		accelerate += 0.1*dt;
		if (accelerate < -1){ accelerate = -1; }
		if (m_player.GetAnimation() != YOHKO_RUN) {
			m_player.SetAnimation(YOHKO_RUN);
		}
	}	

	if ((GetKeyState(VK_RIGHT) & 0x80 || GetKeyState('D') & 0x80)) {
		Strafe(-speed-accelerate); // Right
		m_direction = CVector3f(-1, 0, 0);
		accelerate += 0.1f*dt;
		if (accelerate > 1){ accelerate = 1; }
		if (m_player.GetAnimation() != YOHKO_RUN) {
			m_player.SetAnimation(YOHKO_RUN);
		}
	}
	if (m_position==prevPos){
		if (m_player.GetAnimation()!=YOKHO_IDLE){
			m_player.SetAnimation(YOKHO_IDLE);
			accelerate = 0;
		}
	}
}


CBoundingBox CPlayer::GetBoundingBox()
{
	return m_boundingBox;
}

CVector3f CPlayer::GetStrafeVector() const
{
	return m_strafeVector;
}

CVector3f CPlayer::GetPosition(){
	return m_position;
}

void CPlayer::SetPosition (CVector3f v){
	m_position = v;
}

void CPlayer::ZeroAccelerate(){
	accelerate = 0;
}

