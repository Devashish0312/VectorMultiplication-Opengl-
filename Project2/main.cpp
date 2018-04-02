#include "Vector3D.h"
#include <iostream>
#include <GL/freeglut.h>

//CAMERA
Vector3D centerPosition = Vector3D(1.f, 1.f, 1.f);
Vector3D eyePosition = Vector3D(0.f, 0.f, 0.f);
Vector3D upVector = Vector3D(0.f, 0.f, 1.f);

//VIEW
float zoom = 0.1f;

void drawDot(Vector3D a, Vector3D b)
{
	glLineWidth(2.5);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(a.x, a.y, 0);
	glEnd();

	glLineWidth(2.5);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(b.x, b.y, 0);
	glEnd();

	float res = dot(a, b);

	glLineWidth(5);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(res, b.y, 0);
	glEnd();

}

void drawCross(Vector3D a, Vector3D b) {

	glLineWidth(2.5);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(a.x, a.y, a.z);
	glEnd();

	glLineWidth(2.5);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(b.x, b.y, b.z);
	glEnd();

	Vector3D res = cross(a, b);

	glLineWidth(2.5);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(res.x, res.y, res.z);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(eyePosition.x, eyePosition.y, eyePosition.z, centerPosition.x, centerPosition.y, centerPosition.z, upVector.x, upVector.y, upVector.z);
	//glScalef(zoom, zoom, zoom);

	Vector3D x = Vector3D(1, 0, 0);
	Vector3D y = Vector3D(0, 1, 0);
	//drawDot(x, y);
	drawCross(x, y);
	glFlush();
	glutSwapBuffers();
}

int main(int argc,char*argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("ReconEngine");
	glEnable(GL_DEPTH_TEST);
	//glutMouseWheelFunc(mouseWheel);
	glutDisplayFunc(display);
	glutMainLoop();
}