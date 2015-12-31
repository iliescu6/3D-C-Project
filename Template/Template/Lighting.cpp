#include "Lighting.h"	

void CLighting::Initialise(){
	r[0] = 1.0;
	r[1] = 1.0;
	r[2] = 1.0;
	r[3] = 1.0;

	g[0] = 0.0;
	g[1] = 0.0;
	g[2] = 0.0;
	g[3] = 0.0;

}

void CLighting::SetLights(CVector3f f, CVector3f f1, CVector3f f2, CVector3f f3, CVector3f f4 )
{




	glEnable(GL_LIGHTING);

	GLfloat ambientLight0[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat diffuseLight0[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specularLight0[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat positionLight0[] = { f.x, f.y, f.z, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight0);
	glLightfv(GL_LIGHT0, GL_POSITION, positionLight0);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.1);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.01);



	GLfloat ambientLight1[] = { r[0], g[0], 0.0, 1.0 };
	GLfloat diffuseLight1[] = { r[0], g[0], 0.0, 1.0 };
	GLfloat specularLight1[] = { r[0], g[0], 0.0, 1.0 };
	GLfloat positionLight1[] = { f1.x, f1.y, f1.z, 1.0 };
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight1);
	glLightfv(GL_LIGHT1, GL_POSITION, positionLight1);

	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.01);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.01);

	GLfloat ambientLight2[] = { r[1], g[1], 0.0, 1.0 };
	GLfloat diffuseLight2[] = { r[1], g[1], 0.0, 1.0 };
	GLfloat specularLight2[] = { r[1], g[1], 0.0, 1.0 };
	GLfloat positionLight2[] = { f2.x, f2.y, f2.z, 1.0 };
	glLightfv(GL_LIGHT2, GL_AMBIENT, ambientLight2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuseLight2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, specularLight2);
	glLightfv(GL_LIGHT2, GL_POSITION, positionLight2);

	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.1);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.01);

	GLfloat ambientLight3[] = { r[2], g[2], 0.0, 1.0 };
	GLfloat diffuseLight3[] = { r[2], g[2], 0.0, 1.0 };
	GLfloat specularLight3[] = { r[2], g[2], 0.0, 1.0 };
	GLfloat positionLight3[] = { f3.x, f3.y, f3.z, 1.0 };
	glLightfv(GL_LIGHT3, GL_AMBIENT, ambientLight3);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuseLight3);
	glLightfv(GL_LIGHT3, GL_SPECULAR, specularLight3);
	glLightfv(GL_LIGHT3, GL_POSITION, positionLight3);

	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.1);
	glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.01);

	GLfloat ambientLight4[] = { r[3], g[3], 0.0, 1.0 };
	GLfloat diffuseLight4[] = { r[3], g[3], 0.0, 1.0 };
	GLfloat specularLight4[] = { r[3], g[3], 0.0, 1.0 };
	GLfloat positionLight4[] = { f4.x, f4.y, f4.z, 1.0 };
	glLightfv(GL_LIGHT4, GL_AMBIENT, ambientLight4);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, diffuseLight4);
	glLightfv(GL_LIGHT4, GL_SPECULAR, specularLight4);
	glLightfv(GL_LIGHT4, GL_POSITION, positionLight4);

	glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, 0.1);
	glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, 0.01);



	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);

}

void CLighting::ChangeColor(int i,float x,float y){
	r[i] = x;
	g[i] = y;
}

