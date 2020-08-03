#include <windows.h>
#include <GL/glut.h>
#include <iostream>

//Matheus Souza Cardoso e Lucas Sardinha

double x=0, y=0; // x e y para trabalhar a rotação

void specialKeys( int key, int xi, int yi ) {
	// Seta direita - aumenta rotação em 5 graus
	// Seta para esquerda - diminui a rotação por 5 graus
	if (key == GLUT_KEY_RIGHT) y += 5;
	else if (key == GLUT_KEY_LEFT) y -= 5;
	else if (key == GLUT_KEY_UP ) x += 5;
	else if (key == GLUT_KEY_DOWN) x -= 5;
	// Requisitar atualização do display
	glutPostRedisplay();
}

void poligono(void) {
	// Reinicia transformações
	glLoadIdentity();
	// Rotaciona quando o usuário muda x e y
	glRotatef( x, 1.0, 0.0, 0.0 );
	glRotatef( y, 0.0, 1.0, 0.0 );

	//gluLookAt(0,2,2, 0,0,0, 0,1,0);

	glBegin(GL_POLYGON);
	//Plotando os lados da piramide


    //Lado cyan - FRENTE
    glBegin(GL_POLYGON);
    glColor3f( 0.0, 1.0, 1.0 );
    glVertex3f( 0.5, -0.25, -0.25 );
    glVertex3f( 0.5, 0.25, -0.25 );
    glVertex3f( -0.5, 0.25, -0.25 );
    glVertex3f( -0.5, -0.25, -0.25 );
    glEnd();

    // Lado amarelo - TRASEIRA
    glBegin(GL_POLYGON);
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f( 0.5, -0.25, 0.25 );
    glVertex3f( 0.5, 0.25, 0.25 );
    glVertex3f( -0.5, 0.25, 0.25 );
    glVertex3f( -0.5, -0.25, 0.25 );
    glEnd();

    //Lado cyan - DIREITA
    glBegin(GL_POLYGON);
    glColor3f( 0.5, 0.5, 0.5 );
    glVertex3f( 0.5, -0.25, -0.25 );
    glVertex3f( 0.5, 0.25, -0.25 );
    glVertex3f( 0.5, 0.25, 0.25 );
    glVertex3f( 0.5, -0.25, 0.25 );
    glEnd();

    // Lado amarelo - ESQUERDA
    glBegin(GL_POLYGON);
    glColor3f( 0.0, 1.0, 0.0 );
    glVertex3f( -0.5, -0.25, 0.25 );
    glVertex3f( -0.5, 0.25, 0.25 );
    glVertex3f( -0.5, 0.25, -0.25 );
    glVertex3f( -0.5, -0.25, -0.25 );
    glEnd();

    //Lado cyan - TOPO
    glBegin(GL_POLYGON);
    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( 0.5, 0.25, 0.25 );
    glVertex3f( 0.5, 0.25, -0.25 );
    glVertex3f( -0.5, 0.25, -0.25 );
    glVertex3f( -0.5, 0.25, 0.25 );
    glEnd();

    // Lado amarelo - BASE
    glBegin(GL_POLYGON);
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( 0.5, -0.25, -0.25 );
    glVertex3f( 0.5, -0.25, 0.25 );
    glVertex3f( -0.5, -0.25, 0.25 );
    glVertex3f( -0.5, -0.25, -0.25 );
    glEnd();

    //Lado cyan - FRENTE
    glBegin(GL_POLYGON);
    glColor3f( 0.0, 1.0, 1.0 );
    glVertex3f( 0, 0.25, -0.25 );
    glVertex3f( 0, 1, -0.25 );
    glVertex3f( -0.5, 1, -0.25 );
    glVertex3f( -0.5, 0.25, -0.25 );
    glEnd();

    // Lado amarelo - TRASEIRA
    glBegin(GL_POLYGON);
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f( 0, 0.25, 0.25 );
    glVertex3f( 0, 1, 0.25 );
    glVertex3f( -0.5, 1, 0.25 );
    glVertex3f( -0.5, 0.25, 0.25 );
    glEnd();


        //Lado cyan - DIREITA
    glBegin(GL_POLYGON);
    glColor3f( 0, 0, 1 );
    glVertex3f( 0, 0.25, -0.25 );
    glVertex3f( 0, 1, -0.25 );
    glVertex3f( 0, 1, 0.25 );
    glVertex3f( 0, 0.25, 0.25 );
    glEnd();

    // Lado amarelo - ESQUERDA
    glBegin(GL_POLYGON);
    glColor3f( 0.0, 1.0, 0.0 );
    glVertex3f( -0.5, 0.25, 0.25 );
    glVertex3f( -0.5, 1, 0.25 );
    glVertex3f( -0.5, 1, -0.25 );
    glVertex3f( -0.5, 0.25, -0.25 );
    glEnd();

    //Lado verde escuro - TOPO
    glBegin(GL_POLYGON);
    glColor3f( 0.5, 0.75, 0 );
    glVertex3f( 0, 1, 0.25 );
    glVertex3f( 0, 1, -0.25 );
    glVertex3f( -0.5, 1, -0.25 );
    glVertex3f( -0.5, 1, 0.25 );
    glEnd();
}

static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	poligono(); //função entrada do polígono
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(1024,768);
	glutInitWindowPosition(10,10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Exercicio 1");
	glEnable(GL_DEPTH_TEST);
    gluLookAt(1000,1000,5000, 0,0,0, 0,1,0);
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);
	glClearColor(1,1,1,1);
	glutMainLoop();
	return EXIT_SUCCESS;
}
