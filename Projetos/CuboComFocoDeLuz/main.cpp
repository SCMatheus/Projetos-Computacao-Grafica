#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

static int girarY = 0;
static int girarX = 0;
static int inicioX;
static int inicioY;

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

void moverLuz(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        inicioX = x;
        inicioY = y;

    }
}

void movimento(int x, int y)
{
    girarY = (girarY + (y - inicioY)) % 360;
    inicioY = y;

    girarX = (girarX + (x - inicioX)) % 360;
    inicioX = x;
    glutPostRedisplay();
}

void focoLuz(void)
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
}

void estrutura(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
    GLfloat position[] = {0.0, 0.0, 1.5, 1.0};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -5.0);
    glPushMatrix();
    glRotated((GLdouble) girarX, 0.0, 1.0, 0.0);
    glRotated(0.0, 1.0, 0.0, 0.0);
    glRotated((GLdouble) girarY, 1.0, 0.0, 0.0);
    glRotated(1.0, 0.0, 0.0, 0.0);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glTranslated(0.0, 0.0, 1.5);
    glDisable(GL_LIGHTING);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(0.2);
    glEnable(GL_LIGHTING);
    glPopMatrix();
    glRotatef( x, 1.0, 0.0, 0.0 );
    glRotatef( y, 0.0, 1.0, 0.0 );
    glutSolidCube(1);
    glFlush();
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow(argv[0]);
    focoLuz();
    glutMouseFunc(moverLuz);
    glutMotionFunc(movimento);
    glutReshapeFunc(estrutura);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
