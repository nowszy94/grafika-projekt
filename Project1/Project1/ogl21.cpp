#include <windows.h> 
										 
#include "freeglut.h"

void displaySquareX(double x, double r, double g, double b) {
	glColor3f(r, g, b);
	glVertex3f(x, 0.5, 0.5);
	glVertex3f(x, 0.5, -0.5);
	glVertex3f(x, -0.5, -0.5);
	glVertex3f(x, -0.5, 0.5);
}

void displaySquareY(double y, double r, double g, double b) {
	glColor3f(r, g, b);
	glVertex3f(0.5, y, 0.5);
	glVertex3f(0.5, y, -0.5);
	glVertex3f(-0.5, y, -0.5);
	glVertex3f(-0.5,y, 0.5);
}

void displaySquareZ(double z, double r, double g, double b) {
	glColor3f(r, g, b);
	glVertex3f(0.5, 0.5, z);
	glVertex3f(0.5, -0.5, z);
	glVertex3f(-0.5, -0.5, z);
	glVertex3f(-0.5, 0.5, z);
}

void display() 
{
glClearColor(1.0,1.0,1.0,1.0); 
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//"czyszczenie" t³a okan i bufora g³êbokosci
glEnable(GL_DEPTH_TEST);//w³¹cznie algorytmu zas³aniania
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(60.0, 1.0, 0.1, 10.0); //bry³a widzenia perspektywicznego
gluLookAt(2.0,2.0,2.0, 0.0,0.0,0.0, 0.0,1.0,0.0);//obserwator 
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glBegin(GL_QUADS);

//œciana: y = 0.5
displaySquareY(0.5, 1.0, 0.0, 0.0);

//œciana: y = -0.5
  displaySquareY(-0.5, 0.0, 1.0, 0.0);
  
//œciana: x = 0.5
  displaySquareX(0.5, 0.0, 0.0, 1.0);
  
  //œciana: x = -0.5
  
  glColor3f(1.0, 1.0, 0.0);
  glVertex3f(-0.5,  0.5,  0.5);
  glVertex3f(-0.5,  0.5, -0.5);
  glVertex3f(-0.5, -0.5, -0.5);
  glVertex3f(-0.5, -0.5,  0.5);
  
  //œciana: z = 0.5
  
  glColor3f(1.0, 0.0, 1.0);
  glVertex3f( 0.5,  0.5,  0.5);
  glVertex3f( 0.5, -0.5,  0.5);
  glVertex3f(-0.5, -0.5,  0.5);
  glVertex3f(-0.5,  0.5,  0.5);
  
  //œciana: z = -0.5
  
  glColor3f(0.0, 1.0, 1.0);
  glVertex3f( 0.5,  0.5, -0.5);
  glVertex3f( 0.5, -0.5, -0.5);
  glVertex3f(-0.5, -0.5, -0.5);
  glVertex3f(-0.5,  0.5, -0.5);
  
glEnd();

glFlush();
} 

void main(int argc, char** argv)
{
  glutInit(&argc, argv);  
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH );
  glutInitWindowSize(400,300);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Scena testowa");
  glutDisplayFunc(display);
  glutMainLoop();
}