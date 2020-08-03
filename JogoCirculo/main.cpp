#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>
#include<stdio.h>

float s = 0;
int ida = 1;
int vidas = 5;
char palavra[61];

void specialKeys( int key, int xi, int yi ) {
    // Seta direita - aumenta rotação em 5 graus
    // Seta para esquerda - diminui a rotação por 5 graus
    if (key == GLUT_KEY_RIGHT){
        if(s <= -10){
            ida = 1;
        }
    }else if (key == GLUT_KEY_LEFT) {
        if(s >= 10){
            ida = 0;
        }
    }
    // Requisitar atualização do display
    //glutPostRedisplay();
}

void output(GLfloat x, GLfloat y, char *text)
{
    char *p;
    glPushMatrix();
    glTranslatef(x, y, 0);
    for (p = text; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    glPopMatrix();
}

void movimento(void){
    if(ida == 1){
        if(s <= 14){
            s += 0.005;
        }else{
            ida = 0;
        }
    }else{
        if(s >= -14){
            s -= 0.005;
        }else{
            ida = 1;
        }

    }

    glutPostRedisplay();
}


static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
    amb[3] = dif[3] = cos(s) / 2.0 + 0.5;
    glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, dif);
    movimento();
    if(s == 14 || s == -14){
        vidas--;
    }
    glPushMatrix();
        glColor3f(1,0,0);
        glTranslatef(s, 0.0, 0.0);//objeto original
        glutSolidSphere(1,10, 10);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, 1500, 0, 1500);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        //glRotatef(4, 0.0, 0.0, 1.0);
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_BLEND);
        glColor3f(1,0,0);
        char teste = (vidas + '0');
        output(10,15, "Vidas: " );
        //output(15,10, teste);
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
    glutSpecialFunc(specialKeys);
    //glClearColor(1,1,1,1);
    //glOrtho(-15,15,-15,15,-15,15); //específico para a equação
    glutMainLoop();
    return EXIT_SUCCESS;
}
