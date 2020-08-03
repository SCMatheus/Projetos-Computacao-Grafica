#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>

void func1(void){
    //x^2+5x+4
    //raizes: 1 e 5
    glBegin(GL_LINES); //plotando uma linha
    glColor3d(0,0,1);
    double y=0, auxY = 100000, auxX = 0;
    for (double x=0;x<=6;x+=0.01){
        y = pow(x,2) -6*x +5;
        glVertex2f(x,y);
        if(y < auxY){
            auxY = y;
            auxX = x;
        }
    }
    glEnd();

        glPointSize(5);
        glBegin(GL_POINTS);
            glColor3d(1,0,0);
            glVertex2f(auxX,auxY);
            glVertex2f(1,0);
            glVertex2f(5,0);
        glEnd();


}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    func1(); //função entrada
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
    glOrtho(-1,6.5,-4.5,5.5,-2,2); //específico para a equação
    glutMainLoop();
    return EXIT_SUCCESS;
}
