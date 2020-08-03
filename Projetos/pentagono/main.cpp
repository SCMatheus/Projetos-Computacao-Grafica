#include <windows.h>
#include <GL/glut.h>
#include <iostream>

//Matheus Souza Cardoso e Lucas Sardinha

double x = 0;

void specialKeys( int key, int xi, int yi ) {
	// Seta direita - aumenta rotação em 5 graus
	// Seta para esquerda - diminui a rotação por 5 graus
	if (key == GLUT_KEY_RIGHT ) x += 5;
	else if (key == GLUT_KEY_LEFT) x -= 5;
	// Requisitar atualização do display
	glutPostRedisplay();
}

void pentagrama(){
	glBegin(GL_LINE_LOOP);
		glColor3f( 0, 0, 1.0 );
		glVertex2f(-2, -3);
		glVertex2f(0, 3.5);
		glVertex2f(2, -3);
		glVertex2f(-3.5, 1);
		glVertex2f(3.5, 1);
		glVertex2f(-2, -3);
	glEnd();
}

static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
		glRotatef( x, 0.0, 0.0, 1.0 );
		pentagrama(); //função entrada do polígono
	glPopMatrix();
	glutSwapBuffers();
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(10,10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("Pentagrama");
	//glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);

	glClearColor(1,1,1,1);

	glOrtho(10,-10,10,-10,10,0);

	glutMainLoop();

	return EXIT_SUCCESS;
}
