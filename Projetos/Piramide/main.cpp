#include <windows.h>
#include <GL/glut.h>
#include <iostream>

//Matheus Souza Cardoso e Lucas Sardinha

double x=0, y=0; // x e y para trabalhar a rota��o

void specialKeys( int key, int xi, int yi ) {
	// Seta direita - aumenta rota��o em 5 graus
	// Seta para esquerda - diminui a rota��o por 5 graus
	if (key == GLUT_KEY_RIGHT) y += 5;
	else if (key == GLUT_KEY_LEFT) y -= 5;
	else if (key == GLUT_KEY_UP ) x += 5;
	else if (key == GLUT_KEY_DOWN) x -= 5;
	// Requisitar atualiza��o do display
	glutPostRedisplay();
}

void piramide(void) {
	// Reinicia transforma��es
	glLoadIdentity();
	// Rotaciona quando o usu�rio muda x e y
	glRotatef( x, 1.0, 0.0, 0.0 );
	glRotatef( y, 0.0, 1.0, 0.0 );
	glBegin(GL_POLYGON);
	//Plotando os lados da piramide


	glBegin(GL_POLYGON);
	glColor3f( 1.0, 1.0, 0.0 );
	glVertex3f( -0.5, 0, -0.5 );
	glVertex3f( 0.5, 0, -0.5 );
	glVertex3f( 0, 1, 0 );
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f( 1.0, 0.0, 1.0 );
	glVertex3f( -0.5, 0, 0.5 );
	glVertex3f( -0.5, 0, -0.5 );
	glVertex3f( 0, 1, 0 );
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f( 0.0, 1.0, 0.0 );
	glVertex3f( -0.5, 0, 0.5 );
	glVertex3f( 0.5, 0, 0.5 );
	glVertex3f( 0, 1, 0 );
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f( 0.0, 0.0, 1.0 );
	glVertex3f( 0.5, 0, 0.5 );
	glVertex3f( 0.5, 0, -0.5 );
	glVertex3f( 0, 1, 0 );
	glEnd();

	// Lado Vermelho - BASE
	glBegin(GL_POLYGON);
	glColor3f( 1.0, 0.0, 0.0 );
	glVertex3f( 0.5, 0, 0.5);
	glVertex3f( 0.5, 0, -0.5 );
	glVertex3f( -0.5, 0, -0.5 );
	glVertex3f( -0.5, 0, 0.5 );
	glEnd();

}

static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	piramide(); //fun��o entrada do pol�gono
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(10,10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Piramide");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);
	glClearColor(1,1,1,1);
	glutMainLoop();
	return EXIT_SUCCESS;
}
