#include "Ramp.h"
#include <windows.h>
#include ".\include\gl.h" 
#include "Texture.h"

CRamp::CRamp()
{}

CRamp::~CRamp()
{}

void CRamp::Initialise(){
	// Load the texture
	CTexture texture;
	texture.Load("Resources\\Textures\\marble.bmp", false);
	m_textureID = texture.m_textureID;


}



void CRamp::Render(float an,float x, float y, float z, float a)
{

	GLfloat v0[3] = { 0, 15, 2 };
	GLfloat v1[3] = { 5, 15, 2 };
	GLfloat v2[3] = { 0, 17, 2 };

	GLfloat v3[3] = { 5, 15, 4.5 };
	GLfloat v4[3] = { 5, 15, 7 };
	GLfloat v5[3] = { 0, 15, 7};
	GLfloat v6[3] = {0,17,7};

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
	glColor4f(x, y, z, a);
	glRotatef(an,0,1,0);
	//glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glBegin(GL_TRIANGLE_STRIP);

	glNormal3fv(v5);
	glTexCoord2f(0,0);
	glVertex3fv(v5);

	glNormal3fv(v4);
	glTexCoord2f(1,0);
	glVertex3fv(v4);

	glNormal3fv(v6);
	glTexCoord2f(0,1);
	glVertex3fv(v6);

	glNormal3fv(v4);
	glTexCoord2f(0,0);
	glVertex3fv(v4);

	glNormal3fv(v3);
	glTexCoord2f(1,1);
	glVertex3fv(v3);

	glNormal3fv(v1);
	glTexCoord2f(1,0);
	glVertex3fv(v1);

	glNormal3fv(v6);
	glTexCoord2fv(v6);
	glVertex3fv(v6);

	glNormal3fv(v2);
	glTexCoord2fv(v4);
	glVertex3fv(v2);

	glNormal3fv(v1);
	glTexCoord2fv(v1);
	glVertex3fv(v1);
	glNormal3fv(v0);
	glTexCoord2fv(v0);
	glVertex3fv(v0);
	glNormal3fv(v2);
	glTexCoord2fv(v2);
	glVertex3fv(v2);

	glEnd();
	//glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);
}