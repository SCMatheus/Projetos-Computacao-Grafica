#include <windows.h>
#include <GL/glut.h>
//#include <GL/freeglut.h>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <cmath>

GLfloat movebola=0;
GLint direcao=1;
GLint yEsquerda = 0;
GLint yDireita = 0;
GLint yBola = 0;
GLint somaX = 0;
GLfloat angulo = 215;
GLint direcaoBolaY = 0;
GLfloat inclinacao = 0;
int direita = 0;
int esquerda = 0;
int pause = 0;
//float scaleFactor = 1000 / 120;
const int font=(int)GLUT_BITMAP_9_BY_15;
//210
//limite cima 384
//limite baixo 10



void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void reset(){
    movebola=0;
    direcao=1;
    yEsquerda = 0;
    yDireita = 0;
    yBola = 0;
    somaX = 0;
    angulo = 215;
    direcaoBolaY = 0;
    inclinacao = 0;
}

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho (0, 600, 0, 400, -1 ,1);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);



    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(15.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(2,2); glVertex2i(599,2);
    glVertex2i(599,399); glVertex2i(2,399);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(100,yEsquerda + 190); glVertex2i(100,yEsquerda + 240);
    glVertex2i(500,yDireita + 190); glVertex2i(500,yDireita + 240);
    glEnd();

    glPointSize(15.0);
    glBegin(GL_POINTS);
    glVertex2i(movebola+200,angulo);
    glEnd();

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);

    renderBitmapString(10,380,(void *)font,"Player 1");
    renderBitmapString(10,360,(void *)font,"Pontos:");
    std::stringstream strs;
    strs << esquerda;
    std::string temp_str = strs.str();
    char* char_type = (char*) temp_str.c_str();
    renderBitmapString(78,358,(void *)font,char_type);

    renderBitmapString(10,30,(void *)font,"Player 2");
    renderBitmapString(10,10,(void *)font,"Pontos:");
    std::stringstream strs2;
    strs2 << direita;
    std::string temp_str2 = strs2.str();
    char* char_type2 = (char*) temp_str2.c_str();
    renderBitmapString(78,8,(void *)font,char_type2);

    if (pause >= 1){
        renderBitmapString(170,200,(void *)font,"Pressione (espaco) para continuar.");
    }

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 119:
            if(yEsquerda < 148){
                yEsquerda += 4;
            }
            break;
        case 115:
            if(yEsquerda > -176){
                yEsquerda -= 4;
            }
            break;

        case 111:
            if(yDireita < 148){
                yDireita += 4;
            }
            break;

        case 108:
            if(yDireita > -176){
                yDireita -= 4;
            }
            break;
        case 32:
            reset();
            pause = 0;
            break;
        case 27:
            exit(0);
            break;
    }
}

void bola(int passo){
    if(direcao == 1) {
        movebola = movebola + 1.5 + somaX;
        if(direcaoBolaY == 1){
            angulo = angulo + inclinacao;
            if(angulo >= 380.0){
                direcaoBolaY = 2;
                inclinacao = -(inclinacao);
            }
        }else{
            angulo = angulo + inclinacao;
            if(angulo <= 14.0){
                    direcaoBolaY = 1;
                    inclinacao = -(inclinacao);
            }
           //printf("%i \n", angulo);
        }
        if(movebola>=290.0){
            if((angulo - 32 <= yDireita+215) && (angulo - 28 >= yDireita+215) || ((angulo + 20 <= yDireita+215) && (angulo + 32 >= yDireita+215))){
                   // printf("%i \n",(yDireita+215));
                   //printf("%i \n",(angulo));
                if((angulo - 32 <= yDireita+215) && (angulo - 28 >= yDireita+215)){
                    inclinacao = 1;
                    direcaoBolaY = 1;
                }else{
                    inclinacao = -1;
                    direcaoBolaY = 2;
                }
                somaX = 2;
            }else if(((angulo - 28 <= yDireita+215) && (angulo - 8 >= yDireita+215)) || ((angulo + 8 <= yDireita+215) && (angulo + 24 >= yDireita+215))){
                if((angulo - 28 <= yDireita+215) && (angulo - 8 >= yDireita+215)){
                    inclinacao = 0.5;
                    direcaoBolaY = 1;
                }else{
                    inclinacao = -0.5;
                    direcaoBolaY = 2;
                }
                somaX = 1;
            }else if((angulo - 8 <= yDireita+215) && (angulo + 8 >= yDireita+215)){
                if (inclinacao > 0){
                    inclinacao--;
                }else if (inclinacao < 0){
                    inclinacao++;
                }

                somaX = 0;
            }else{
                esquerda++;
                pause = 1;

                //reset();
            }
            //printf("Bola %i \n",angulo);
            //printf("Teste %i \n",yDireita);
            direcao = 0;
        }

    }else{
        movebola = movebola - 1.5 - (somaX);
        if(direcaoBolaY == 1){
            angulo = angulo + inclinacao;
            if(angulo >= 380.0){
                direcaoBolaY = 2;
                inclinacao = -(inclinacao);
            }
        }else{
            angulo = angulo + inclinacao;
            if(angulo <= 14.0){
                direcaoBolaY = 1;
                inclinacao = -(inclinacao);
            }
            //printf("%i \n", angulo);
        }
        if(movebola<=-90.0){
            if((angulo - 32 <= yEsquerda+215) && (angulo - 28 >= yEsquerda+215) || ((angulo + 20 <= yEsquerda+215) && (angulo + 32 >= yEsquerda+215))){
                if((angulo - 32 <= yEsquerda+215) && (angulo - 28 >= yEsquerda+215)){
                    inclinacao = 1;
                    direcaoBolaY = 1;
                }else{
                    inclinacao = -1;
                    direcaoBolaY = 2;
                }
                somaX = 2;
            }else if(((angulo - 28 <= yEsquerda+215) && (angulo - 8 >= yEsquerda+215)) || ((angulo + 8 <= yEsquerda+215) && (angulo + 24 >= yEsquerda+215))){
                if((angulo - 28 <= yEsquerda+215) && (angulo - 8 >= yEsquerda+215)){
                    inclinacao = 0.5;
                    direcaoBolaY = 1;
                }else{
                    inclinacao = -0.5;
                    direcaoBolaY = 2;
                }
                somaX = 1;
            }else if((angulo - 8 <= yEsquerda+215) && (angulo + 8 >= yEsquerda+215)){
                if (inclinacao > 0){
                    inclinacao = inclinacao - 0.5;
                }else if (inclinacao < 0){
                    inclinacao = inclinacao + 0.5;
                }
                somaX = 0;
            }else{
                direita++;
                pause = 1;
                //reset();
            }
            direcao = 1;
        }
    }
    if(pause == 0){
       glutPostRedisplay();
    }else if(pause == 1){
        pause++;
        glutPostRedisplay();
    }
    glutTimerFunc(10,bola, 1);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (600, 400);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Pong");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(10,bola,1);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(1.0);
    glutKeyboardFunc(keyboard);
//    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
