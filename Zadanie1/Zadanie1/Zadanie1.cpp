#include "stdafx.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void RenderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT);

	glFlush();
}

void SetupRC(void) {
	glClearColor(0.0f, 0.1f, 0.0f, 0.0f);
}

void main(int argc, char **argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Moj pierwszy program w GLUT");
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();
}