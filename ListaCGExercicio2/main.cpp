#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <stdlib.h>
using namespace std;

int textura = 1;

const int tamInicioJanela = 400;
const double proximo = 0.5;
const double distante = 10.;

const int largura = 32;
const int altura = 32;
GLubyte imagem[altura][largura][3];
GLuint texnome;

void iniciar();
void keyboard(unsigned char , int , int );
void reshape(int , int );
void criarImagem();
void display();
void idle();

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslated(0., 0., -3.);
    glTranslatef(-0.5,-0.8,0);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 1.0); glVertex3d( 1.0, 1.0, 0.0);
    glTexCoord2d(0.0, 0.0); glVertex3d(0.5, 1.25, 0.0);
    glTexCoord2d(0.0, 1.0); glVertex3d(0, 1.0, 0.0);
    glTexCoord2d(1.0, 0.0); glVertex3d( 0.5,0.75, 0.0);
    glEnd();
    glPopMatrix();
    iniciar();
    glutPostRedisplay();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, double(w)/h, proximo, distante);
    glMatrixMode(GL_MODELVIEW);
}


void idle()
{
    if (GLenum err = glGetError())
    {
    cerr << "OpenGL ERROR: "<<gluErrorString(err) << endl;
    }

}

void criarImagem() {
    int aux1 = 0;
    float aux2 = 0;

    if(textura == 1){
        aux1 = 0;
        aux2 = 0;
    }
    for (int i=0; i<largura; ++i) {
    double x = double(i)/(largura-1);

        for (int j=0; j<altura; ++j) {
            double y = double(j)/(altura-1);
            imagem[j][i][0] = int(x*255)*aux1 % 256;
            imagem[j][i][1] = int(y*255)*aux1 % 256;
            imagem[j][i][2] = aux2*255;
        }
    }
}

void iniciar()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); criarImagem();
    glGenTextures(1, &texnome);
    glBindTexture(GL_TEXTURE_2D, texnome);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, largura, altura,

    0, GL_RGB, GL_UNSIGNED_BYTE, imagem);

}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(tamInicioJanela, tamInicioJanela);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Textura Simples");
    iniciar();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
