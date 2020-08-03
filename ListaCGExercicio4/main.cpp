#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <stdlib.h>
using namespace std;

const int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;


void losangulo25D(float x, float y, float width,float height, float r, float g, float b);


void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void losangulo25D(float x, float y, float width,float height, float r, float g, float b){

    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex3d( x+width, y+height, 0.0);
    glVertex3d(x+(width/2), (y + ((width/2)/2)+height), 0.0);
    glVertex3d(x, y+height, 0.0);
    glVertex3d( x+(width/2),(y - ((width/2)/2)+height), 0.0);
    glEnd();
    glColor3f(r*0.7,g*0.7,b*0.7);
    glBegin(GL_POLYGON);
    glVertex3d( x+width, y+height, 0.0);
    glVertex3d(x+width, y , 0.0);
    glVertex3d( x+(width/2),(y - ((width/2)/2)), 0.0);
    glVertex3d(x+(width/2), (y - ((width/2)/2)+height), 0.0);
    glEnd();
    glColor3f(r*0.7,g*0.7,b*0.7);
    glBegin(GL_POLYGON);
    glVertex3d(x+(width/2), y - ((width/2)/2), 0.0);
    glVertex3d( x+(width/2),(y - ((width/2)/2)+height), 0.0);
    glVertex3d(x, y+height, 0.0);
    glVertex3d(x, y, 0.0);
    glEnd();

    // CONTORNO
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex3d( x+width, y+height, 0.0);
    glVertex3d(x+(width/2), (y + ((width/2)/2)+height), 0.0);
    glVertex3d(x, y+height, 0.0);
    glVertex3d( x+(width/2),(y - ((width/2)/2)+height), 0.0);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex3d( x+width, y+height, 0.0);
    glVertex3d(x+width, y , 0.0);
    glVertex3d( x+(width/2),(y - ((width/2)/2)), 0.0);
    glVertex3d(x+(width/2), (y - ((width/2)/2)+height), 0.0);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex3d(x+(width/2), y - ((width/2)/2), 0.0);
    glVertex3d( x+(width/2),(y - ((width/2)/2)+height), 0.0);
    glVertex3d(x, y+height, 0.0);
    glVertex3d(x, y, 0.0);
    glEnd();

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(-0.5,-0.8,0);


    //cima
    losangulo25D(0.375,1.1875,0.25,0.03,0.65,0.65,0.65);
    //direita
    losangulo25D(0.5,1.125,0.25,0.03,0.65,0.65,0.65);
    losangulo25D(0.625,1.0625,0.25,0.03,0.65,0.65,0.65);
    losangulo25D(0.75,1,0.25,0.03,0.65,0.65,0.65);

    //cima
    losangulo25D(0.25,1.125,0.25,0.03,0.65,0.65,0.65);
    losangulo25D(0.125,1.0625,0.25,0.03,0.65,0.65,0.65);
    losangulo25D(0,1,0.25,0.03,0.65,0.65,0.65);
//
    //meio
    losangulo25D(0.250,1,0.25,0,0.3,0.3,0.3);
    losangulo25D(0.375,1.0625,0.25,0,0.3,0.3,0.3);
    losangulo25D(0.375,0.9375,0.25,0,0.3,0.3,0.3);
    losangulo25D(0.5,1,0.25,0.03,0.40,0.54,0.93);


    //baixo
    losangulo25D(0.625,0.9375,0.25,0.03,0.65,0.65,0.65);
    losangulo25D(0.5,0.875,0.25,0.03,0.65,0.65,0.65);

    //esquerda
    losangulo25D(0.125,0.9375,0.25,0.03,0.65,0.65,0.65);
    losangulo25D(0.25,0.875,0.25,0.03,0.65,0.65,0.65);
    losangulo25D(0.375,0.8125,0.25,0.03,0.65,0.65,0.65);


    glPopMatrix();
    glColor3f(1.0, 1.0, 1.0);
    //glEnable(GL_LINE_SMOOTH);
    //glEnable(GL_BLEND);
    renderBitmapString(-0.25,-0.2,(void *)font,"Matheus Souza Cardoso");
    glutPostRedisplay();
    glutSwapBuffers();
}




int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Textura Simples");
    glutDisplayFunc(display);
    glClearColor(0,0,0,0);
    glLineWidth(1.0);
    glutMainLoop();
    return 0;
}
