#include "Material.h"	



void CMaterial::SetDefaultMaterial()
{
	GLfloat ambientMaterial[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat diffuseMaterial[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat specularMaterial[] = {0.0, 1.0, 5.0, 1.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0f);

}



void CMaterial::SetRedMaterial(int shiness)
{
	GLfloat ambientMaterial[] = {1.0, 0.0, 0.0, 1.0};
	GLfloat diffuseMaterial[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat specularMaterial[] = {1.0, 1.0, 1.0, 1.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
	glMaterialf(GL_FRONT, GL_SHININESS, shiness);

}