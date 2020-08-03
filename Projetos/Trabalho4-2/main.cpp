#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <stdlib.h>

void objeto(void){
    glBegin(GL_TRIANGLES);
        glVertex2f(1,5);
        glVertex2f(1,9);
        glVertex2f(6,8);
        glVertex2f(1,1);
        glVertex2f(9,9);
        glVertex2f(6,1);
    glEnd();
}

/* Entrada do Programa */
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
    glTranslatef(7,5,0);
    glTranslatef(-6,0,0);
    objeto(); //objeto original
    glPushMatrix();
        glColor3d(0,0,1);
        glTranslatef(-7,-5,0);
        glRotatef(60,0,0,1); // rota��o em 45�
        glTranslatef(-7,0,0);
        objeto(); //objeto transladado e rotacionado
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(900,700);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);

    glClearColor(1,1,1,1);
    glOrtho(-20,15,-5,15,-10,10);
    glutMainLoop();

    return EXIT_SUCCESS;
}
