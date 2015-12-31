#include "Crystal.h"
#include <windows.h>
#include ".\include\gl.h" 
#include "Texture.h"

Crystal::Crystal()
{}

Crystal::~Crystal()
{}

void Crystal::Initialise(){
	// Load the texture
	CTexture texture;
	texture.Load("Resources\\Textures\\brick.bmp", false);
	m_textureID = texture.m_textureID;
	theta = 0.0f;

}

void Crystal::Update(float dt){
	
	theta += dt*50.0f;
}

void Crystal::Render(float x,float y,float z,float a)
{
	GLfloat v0[3] = { 0, 20, 0};
	GLfloat v1[3] = { -2, 15, -2 };
	GLfloat v2[3] = { -2, 15, 2 };
	GLfloat v3[3] = { 2, 15, 2 };
	GLfloat v4[3] = { 2, 15, -2 };
	GLfloat v5[3] = { 0, 10, 0 };

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_textureID);

	glColor4f(x,y,z,a);
	glRotatef(theta,0,1,0);
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_TRIANGLES);
	//Upper part
	glNormal3fv(v2);
	glTexCoord2fv(v2);
	glVertex3fv(v2);
	glNormal3fv(v3);
	glTexCoord2fv(v3);
	glVertex3fv(v3);
	glNormal3fv(v0);
	glTexCoord2fv(v0);
	glVertex3fv(v0);

	glNormal3fv(v1);
	glTexCoord2fv(v2);
	glVertex3fv(v1);
	glNormal3fv(v2);
	glTexCoord2fv(v3);
	glVertex3fv(v2);
	glNormal3fv(v0);
	glTexCoord2fv(v0);
	glVertex3fv(v0);

	glNormal3fv(v4);
	glTexCoord2fv(v4);
	glVertex3fv(v4);
	glNormal3fv(v1);
	glTexCoord2fv(v1);
	glVertex3fv(v1);
	glNormal3fv(v0);
	glTexCoord2fv(v0);
	glVertex3fv(v0);

	glNormal3fv(v3);
	glTexCoord2fv(v2);
	glVertex3fv(v3);
	glNormal3fv(v4);
	glTexCoord2fv(v3);
	glVertex3fv(v4);
	glNormal3fv(v0);
	glTexCoord2fv(v0);
	glVertex3fv(v0);
	
	//Lower part
	glNormal3fv(v3);
	glTexCoord2fv(v3);
	glVertex3fv(v3);
	glNormal3fv(v2);
	glTexCoord2fv(v2);
	glVertex3fv(v2);
	glNormal3fv(v5);
	glTexCoord2fv(v5);
	glVertex3fv(v5);

	glNormal3fv(v2);
	glTexCoord2fv(v3);
	glVertex3fv(v2);
	glNormal3fv(v1);
	glTexCoord2fv(v2);
	glVertex3fv(v1);
	glNormal3fv(v5);
	glTexCoord2fv(v5);
	glVertex3fv(v5);

	glNormal3fv(v1);
	glTexCoord2fv(v1);
	glVertex3fv(v1);
	glNormal3fv(v2);
	glTexCoord2fv(v4);
	glVertex3fv(v4);
	glNormal3fv(v5);
	glTexCoord2fv(v5);
	glVertex3fv(v5);

	glNormal3fv(v4);
	glTexCoord2fv(v3);
	glVertex3fv(v4);
	glNormal3fv(v3);
	glTexCoord2fv(v2);
	glVertex3fv(v3);
	glNormal3fv(v5);
	glTexCoord2fv(v5);
	glVertex3fv(v5);

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);


}