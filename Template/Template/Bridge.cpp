#include "Bridge.h"
#include <windows.h>
#include ".\include\gl.h" 
#include "Texture.h"

CBridge::CBridge()
{}

CBridge::~CBridge()
{}

void CBridge::Initialise(){
	// Load the texture
	CTexture texture;
	texture.Load("Resources\\Textures\\marble.bmp", false);
	m_textureID = texture.m_textureID;

}

/*
CVector3f Cross(CVector3f v1,CVector3f v2){
	CVector3f Normal;
	Normal.x = ((v1.y*v2.z)-(v1.z*v2.y));
	Normal.y = ((v1.z*v2.x) - (v1.x*v2.z));
	Normal.z = ((v1.y*v2.x) - (v1.x*v2.y));
	return Normal;

}*/


void CBridge::Render(float x, float y, float z, float a)
{
	//Top
	GLfloat v0[3] = { 0, 17, 0 };
	GLfloat v1[3] = { -10, 17, 0 };
	GLfloat v2[3] = { -10, 17, -5 };
	GLfloat v3[3] = { 0, 17, -5 };
	//Bottom
	GLfloat v4[3] = { 0, 15, 0 };
	GLfloat v5[3] = { -10, 15, 0 };
	GLfloat v6[3] = { 0, 15, -5 };
	GLfloat v7[3] = { -10, 15, -5 };


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
	glColor4f(x, y, z, a);
	//glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin(GL_QUADS);

	//Left
	glNormal3fv(v6);
	glTexCoord2fv(v6);
	glVertex3fv(v6);
	glNormal3fv(v3);
	glTexCoord2fv(v7);
	glVertex3fv(v3);
	glNormal3fv(v0);
	glTexCoord2fv(v2);
	glVertex3fv(v0);
	glNormal3fv(v4);
	glTexCoord2fv(v3);
	glVertex3fv(v4);

	//Right
	glNormal3fv(v1);
	glTexCoord2fv(v6);
	glVertex3fv(v1);
	glNormal3fv(v2);
	glTexCoord2fv(v7);
	glVertex3fv(v2);
	glNormal3fv(v7);
	glTexCoord2fv(v2);
	glVertex3fv(v7);
	glNormal3fv(v5);
	glTexCoord2fv(v3);
	glVertex3fv(v5);

	//Up
	glNormal3fv(v2);
	glTexCoord2fv(v6);
	glVertex3fv(v2);
	glNormal3fv(v1);
	glTexCoord2fv(v7);
	glVertex3fv(v1);
	glNormal3fv(v0);
	glTexCoord2fv(v2);
	glVertex3fv(v0);
    glNormal3fv(v3);
	glTexCoord2fv(v3);
	glVertex3fv(v3);
	
	//Front
	glNormal3fv(v6);
	glTexCoord2fv(v6);
	glVertex3fv(v6);
	glNormal3fv(v7);
	glTexCoord2fv(v7);
	glVertex3fv(v7);
	glNormal3fv(v2);
	glTexCoord2fv(v2);
	glVertex3fv(v2);
	glNormal3fv(v3);
	glTexCoord2fv(v3);
	glVertex3fv(v3);

	//Bottom
	glNormal3fv(v4);
	glTexCoord2fv(v6);
	glVertex3fv(v4);

	glNormal3fv(v5);
	glTexCoord2fv(v7);
	glVertex3fv(v5);

	glNormal3fv(v7);
	glTexCoord2fv(v2);
	glVertex3fv(v7);

	glNormal3fv(v6);
	glTexCoord2fv(v3);
	glVertex3fv(v6);

	//Back
	glNormal3fv(v5);
	glTexCoord2fv(v5);
	glVertex3fv(v5);
	glNormal3fv(v4);
	glTexCoord2fv(v4);
	glVertex3fv(v4);
	glNormal3fv(v0);
	glTexCoord2fv(v0);
	glVertex3fv(v0);
	glNormal3fv(v1);
	glTexCoord2fv(v1);
	glVertex3fv(v1);
	glEnd();

	//glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);
}