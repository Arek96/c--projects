#include <iostream>
#include <gl/glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>
size_t width = 400;
size_t height = 300;

void OnReshape(int w, int h)
{
	width = w;
	height = h;
	// aktualizacja viewportu
	glViewport(0, 0, w, h);
	
	// aktualizacja macierzy projekcji
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, h, 0);
	//gluPerspective(45, 1.33, 0, 100);
}
void OnRender(void)
{
	// wyczyszczenie ekranu kolorem bia³ym
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	// ustawienie domyœlej macierzy widoku
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// przerysowanie ekranu
	
		// Rozpoczêsie rysowania trójk¹ta
		glBegin(GL_POLYGON);
		{
			//Pierwszy wierzcho³ek
			glColor3f(0.0f, 0.0f, 1.0f);//Blue
			glVertex2d(GLdouble(1), GLdouble(1));
			//Drugi wieszcho³ek
			glColor3f(0.0f, 1.0f, 0.0f);//Green
			glVertex2d(GLdouble(500), GLdouble(256));
			//Trzeci wieszcho³ek
			glColor3f(1.0f, 0.0f, 0.0f);//Red
			glVertex2d(GLdouble(581), GLdouble(150));
			glColor3f(3.0f, 0.0f, 1.0f);//Blue
			glVertex2d(GLdouble(126), GLdouble(158));
			glColor3f(0.0f, 2.0f, 1.5f);//Blue
			glVertex2d(GLdouble(130), GLdouble(103));
			glColor3f(0.0f, 2.0f, 1.5f);//Blue
			glVertex2d(GLdouble(666), GLdouble(254));
			glColor3f(0.0f, 2.0f, 1.5f);//Blue
			glVertex2d(GLdouble(182), GLdouble(531));
		}
		// Zakoñczenie rysowania trójk¹ta
		glEnd();
	
	// wykonanie poleceñ OpenGL oraz opró¿nienie wszystkich u¿ytych buforów
	glFlush();
	// zamiana buforów (tylnego i przdniego)
	glutSwapBuffers();
}
int main(int argc, char** argv)
{
	// Inicjalizacja biblioteki glut, która tworzy okienko z poziomu OpenGL
	glutInit(&argc, argv);
	// Ustawienie trybu kolorów RGBA oraz podwójnego buforowania
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	// Inicjalizacja rozmiaru oraz pozycji okna
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 100);
	// Stworzenie okna
	glutCreateWindow("OpenGL Window");
	// Zarejestrowanie funkcji zwrotnych
	glutDisplayFunc(OnRender);
	glutIdleFunc(OnRender);
	glutReshapeFunc(OnReshape);
	//Uruchamianie g³ównej pêtli OpenGL
	glutMainLoop();
	return 1;
}