#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

int cor = 0;
char palavra[61];
int idaVolta = 1;
float s = 0.0;
GLfloat angulo1 = 0.0, angulo2 = 0.0;

void output(GLfloat x, GLfloat y, char *text)
{
    char *p;
    glPushMatrix();
    glTranslatef(x, y, 0);
    for (p = text; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    glPopMatrix();
}
void tempoOcioso(void)
{
    if(idaVolta == 1){
        if(s <= 1){
            s += 0.001;
        }else{
            idaVolta = 0;
        }
    }else{
        if(s >= 0){
            s -= 0.001;
        }else{
            idaVolta = 1;
            if(cor < 2){
                cor++;
            }else{
                cor = 0;
            }
        }
    }
    glutPostRedisplay();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 1500, 0, 1500);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glRotatef(4, 0.0, 0.0, 1.0);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    tempoOcioso();
    float i = s;
    if(cor == 0){
        glColor3f(0.1,0.1,i);
    }else if (cor == 1){
        glColor3f(0.1,i,0.1);
    }else{
        glColor3f(i,0.1,0.1);
    }
    output(100, 600, palavra);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glPopAttrib();
    glMatrixMode(GL_MODELVIEW);
    glutSwapBuffers();
}



int main(int argc, char **argv)
{
    printf("Digite uma palavra: ");
    scanf("%[^\n]s", palavra);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Texto Ajustado");
    glutDisplayFunc(display);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(5.0);
    glutMainLoop();
    return 0;
}
