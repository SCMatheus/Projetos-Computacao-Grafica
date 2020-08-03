#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <stdlib.h>

void objeto(void){
    glBegin(GL_LINE_LOOP);
        glVertex2f(1,3);
        glVertex2f(2,0);
        glVertex2f(5,-1);
        glVertex2f(2,-2);
        glVertex2f(1,-5);
        glVertex2f(0,-2);
        glVertex2f(-3,-1);
        glVertex2f(0,0);
    glEnd();
}

/* Entrada do Programa */
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
    objeto(); //objeto original
    glPushMatrix();
        glColor3d(0,0,1);
        glTranslatef(-7,7,0);
        glRotatef(45,0,0,1); // rotação em 45°
        glTranslatef(-4,0,0);
        objeto(); //objeto transladado e rotacionado
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);

    glClearColor(1,1,1,1);
    glOrtho(-13,7,-10,10,-10,10);
    glutMainLoop();

    return EXIT_SUCCESS;
}
