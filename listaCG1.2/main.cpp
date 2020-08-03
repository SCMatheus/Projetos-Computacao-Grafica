/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

const int tamInicioJanela = 400;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    //glTranslated(0., 0., -3.);
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex3d( 0.5, 0.5, 0.0);
    glVertex3d(-0.5, 0.5, 0.0);
    glVertex3d(-0.3,-0.5, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(-0.5, 0.5, 0.0);
    glVertex3d(-0.5,-0.6, 0.0);
    glVertex3d(-0.35,-0.1, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3d(0.5, 0.5, 0.0);
    glVertex3d(0.4,-0.3, 0.0);
    glVertex3d(0.1,0, 0.0);
    glEnd();
    glPopMatrix();
    glutPostRedisplay();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(5,5);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Letra B");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glClearColor(1,1,1,1);
    glutMainLoop();
    return EXIT_SUCCESS;
}
