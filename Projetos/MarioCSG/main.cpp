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

void poligono(void) {
    double i =0;
	// Reinicia transforma��es
	glLoadIdentity();
	// Rotaciona quando o usu�rio muda x e y
	glRotatef( x, 1.0, 0.0, 0.0 );
	glRotatef( y, 0.0, 1.0, 0.0 );

	//gluLookAt(0,2,2, 0,0,0, 0,1,0);

	glBegin(GL_POLYGON);
	//Plotando os lados da piramide



		////////////////////////bra�o esquerdo////////////////////////




    for(i = 0.07; i >= -0.01; i -= 0.001){
        //Lado cyan - DIREITA
        glBegin(GL_POLYGON);
        glColor3f( 0.98, 0.91, 0.90 );
        glVertex3f( i, 0.1, 0.13 );
        glVertex3f( i, 0.2, 0.13 );
        glVertex3f( i, 0.2, 0.19 );
        glVertex3f( i, 0.1, 0.19 );
        glEnd();
    }



	////////////////////////mao direita///////////////////////////

    for(i = 0.07; i >= -0.01; i -= 0.001){
        //Lado cyan - DIREITA
        glBegin(GL_POLYGON);
        glColor3f( 0.98, 0.91, 0.90 );
        glVertex3f( i, 0.1, -0.13 );
        glVertex3f( i, 0.2, -0.13 );
        glVertex3f( i, 0.2, -0.19 );
        glVertex3f( i, 0.1, -0.19 );
        glEnd();
    }



	////////////////////////bra�o esquerdo////////////////////////


    for(i = 0.01; i >= -0.23; i -= 0.001){
            //Lado cyan - DIREITA
        glBegin(GL_POLYGON);
        glColor3f( 1, 0, 0 );
        glVertex3f( i, 0.1, 0.13 );
        glVertex3f( i, 0.2, 0.13 );
        glVertex3f( i, 0.2, 0.19 );
        glVertex3f( i, 0.1, 0.19 );
        glEnd();
    }


	////////////////////////bra�o direito///////////////////////////

    for(i = 0.01; i >= -0.23; i -= 0.001){
            //Lado cyan - DIREITA
        glBegin(GL_POLYGON);
        glColor3f( 1, 0, 0 );
        glVertex3f( i, 0.1, -0.13 );
        glVertex3f( i, 0.2, -0.13 );
        glVertex3f( i, 0.2, -0.19 );
        glVertex3f( i, 0.1, -0.19 );
        glEnd();
    }


	////////////////////////pes//////////////////////////////


    for(i = 0.09; i >= -0.24; i -= 0.001){
            //Lado cyan - DIREITA
        glBegin(GL_POLYGON);
        glColor3f( 0.66,0.41,0.17  );
        glVertex3f( i, -0.3, -0.15 );
        glVertex3f( i, -0.1, -0.15 );
        glVertex3f( i, -0.1, 0.15 );
        glVertex3f( i, -0.3, 0.15 );
        glEnd();
    }


	/////////////////////////Corpo///////////////////////////


    for(i = -0.02; i >= -0.23; i -= 0.001){
            //Lado cyan - DIREITA
        glBegin(GL_POLYGON);
        glColor3f( 0.33, 0.58, 0.83 );
        glVertex3f( i, -0.1, -0.13 );
        glVertex3f( i, 0.3, -0.13 );
        glVertex3f( i, 0.3, 0.13 );
        glVertex3f( i, -0.1, 0.13 );
        glEnd();
    }




	///////////////////////////////Cabe�a/////////////////////////////////////




        //Lado cyan - DIREITA
    for(i = 0; i >= -0.25; i -= 0.001){
        glBegin(GL_POLYGON);
        glColor3f( 1, 0.95, 0.81 );
        glVertex3f( i, 0.3, -0.15 );
        glVertex3f( i, 0.6, -0.15 );
        glVertex3f( i, 0.6, 0.15 );
        glVertex3f( i, 0.3, 0.15 );
        glEnd();
}




///////////////////////////Bone//////////////////////////////



        //Lado cyan - DIREITA
    for(i = 0; i >= -0.25; i -= 0.001){
        glBegin(GL_POLYGON);
        glColor3f( 1.0, 0, 0 );
        glVertex3f( i, 0.6, -0.15 );
        glVertex3f( i, 0.75, -0.15 );
        glVertex3f( i, 0.75, 0.15 );
        glVertex3f( i, 0.6, 0.15 );
        glEnd();
}

}

static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	poligono(); //fun��o entrada do pol�gono
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
