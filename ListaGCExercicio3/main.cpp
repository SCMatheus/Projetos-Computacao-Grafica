#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <stdlib.h>
using namespace std;



void losangulo25D(float x, float y, float width,float height, float r, float g, float b);



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

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(-0.5,-0.8,0);


    losangulo25D(0.5,1,0.25,0.05,0.6,0.6,0.6);



    glPopMatrix();
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
