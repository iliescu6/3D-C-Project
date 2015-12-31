#include "Screen.h"

void Screen::MakeScreen(int i){
	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, i);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	int w = viewport[2];
	int h = viewport[3];
	gluOrtho2D(0, w, 0, h);
	glScalef(1, -1, 1);
	glTranslatef(0, (float)-h, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(0.0f, h);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(w, h);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(w, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(0.0f, 0.0f);
	glEnd();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}