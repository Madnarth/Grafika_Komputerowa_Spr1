#include "stdafx.h"
#include "math.h"
#include "iostream"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Pocztkowy rozmiar i pozycja prostokta
GLfloat x_1 = 200.0f;
GLfloat y_1 = 150.0f;
GLfloat angle = 0;
GLsizei rsize = 150;

// Rozmiar kroku (liczba pikseli) w osi x i y
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;
// Dane zmieniajcych siê rozmiarów okna
GLfloat windowWidth;
GLfloat windowHeight;
///////////////////////////////////////////////////////////
// Wywo³ywana w celu przerysowania sceny
void RenderScene(void) {
	// Wyczyszczenie okna aktualnym kolorem czyszcz¹cym
	glClear(GL_COLOR_BUFFER_BIT);
	// Aktualny kolor rysuj¹cy - pastelowy
	//	R	G	B
	glColor3f(0.98f, 0.04f, 0.70f);
	// Narysowanie piêciok¹ta wype³nionego aktualnym kolorem
	int triangleAmount = 5;
	GLfloat twicePi = 2.0f * 3.14;
	angle += 0.8f;

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(x_1, y_1, 0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glTranslatef(-x_1, -y_1, 0);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x_1, y_1); // center of circle
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x_1 + (6.0*cos(i*twicePi / triangleAmount)) * 4,
			y_1 + (6.0*sin(i*twicePi / triangleAmount)) * 4
		);
	}
	glEnd();
	glPopMatrix();
	glFlush();
	// Wys³anie poleceñ do wykonania - !!! dla animacji to jest inne polecenie
	glutSwapBuffers();
}


///////////////////////////////////////////////////////////
// Wywo³ywana przez bibliotek GLUT przy ka¿dej zmianie wielkoœci okna
void ChangeSize(GLsizei w, GLsizei h) {
	// Zabezpieczenie przed dzieleniem przez zero
	if (h == 0)
		h = 1;

	// Ustalenie wielkoœci widoku zgodnego z rozmiarami okna
	glViewport(0, 0, w, h);

	// Ustalenie uk³adu wspó³rzêdnych
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Keep the square square, this time, save calculated
	// width and height for later use
	if (w <= h)
	{
		windowHeight = 250.0f*h / w;
		windowWidth = 250.0f;
	}
	else
	{
		windowWidth = 250.0f*w / h;
		windowHeight = 250.0f;
	}

	// Ustanowienie przestrzeni ograniczaj¹cej (lewo, prawo, dó³, góra, blisko, daleko)
	glOrtho(0.0f, windowWidth, 0.0f, windowHeight, 1.0f, -1.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

///////////////////////////////////////////////////////////
// Konfigurowanie stanu renderowania
void SetupRC(void) {
	// Ustalenie niebieskiego koloru czyszcz¹cego     
	glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
}
///////////////////////////////////////////////////////////
// G³ówny punkt wejœcia programu
void main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Moj pierwszy program w GLUT");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	//glutTimerFunc(33, TimerFunction, 1);
	SetupRC();
	glutMainLoop();

}