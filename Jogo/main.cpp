#include <windows.h>
#include <gl/glut.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

unsigned int texture;
int fase = 1;
int veiculo = 1; // 1 - caminhao    0 - carro
int vertical = 1;
int amarelo = 0;
int i = 0;
int vitoria = 0 ;
float x[8] = {-9.0, 0.0, -0.5, 0.5, 0, 0, 0, 0};
float y[8] = {9.0, 0.5, 0.0, 6.0, 0, 0, 0, 0};



int posicoes[6][6] = {{0,-1,-1,-1,-1,-1},{0,-1,-1,3,-1,-1},{0,1,1,3,-1,-1},{-1,-1,2,-1,-1,-1},{-1,-1,2,-1,-1,-1},{-1,-1,-1,-1,-1,-1}};
int posicoes2[6][6] = {{0,-1,-1,-1,-1,-1},{0,1,1,1,-1,-1},{0,2,2,4,-1,-1},{-1,-1,3,4,-1,-1},{-1,-1,3,4,-1,-1},{-1,-1,5,5,-1,-1}};
int posicoes3[6][6] = {{0,-1,-1,-1,-1,-1},{0,1,1,1,-1,7},{0,2,2,4,-1,7},{-1,-1,3,4,-1,-1},{6,6,3,4,-1,-1},{-1,-1,5,5,-1,-1}};


const char* nome1 = "caminhao.jpg";
const char* nome2 = "carroVertical.jpg";
const char* nome3 = "carroVertical2.jpg";
const char* nome4 = "carroHorizontal.jpg";
const char* nome5 = "fundo.jpg";
const char* nome6 = "caminhaoHorizontal.jpg";

bool upsidedown = true;

const int tamInicioJanela = 400;

GLuint texture_id[6];

const int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;

void troca(){
	for (int m = 0; m<6;m++){
		for(int n = 0; n<6; n++){
			if (fase == 2){
				posicoes[m][n] = posicoes2[m][n];
			}else if(fase == 3){
				posicoes[m][n] = posicoes3[m][n];
			}else return;
		}
	}	
}

void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

bool Busca(string direcao){
	if(("sobe" == direcao) && (vertical == 1)){
		for(int l = 1; l < 6; l++){
			for(int c = 0; c < 6; c++){
				if((posicoes[l][c] == i) && (posicoes[l-1][c] == -1)){
					posicoes[l-1][c] = i;
					if(veiculo == 1){
						posicoes[l+2][c] = -1;
					}else posicoes[l+1][c] = -1;
					return true;
				}
			}
		}
		return false;
	}else if(("desce" == direcao) && (vertical == 1)){
		for(int l = 4; l >= 0; l--){
			for(int c = 0; c < 6; c++){
				if((posicoes[l][c] == i) && (posicoes[l+1][c] == -1)){
					posicoes[l+1][c] = i;
					if(veiculo == 1){
						posicoes[l-2][c] = -1;
					}else posicoes[l-1][c] = -1;
					return true;
				}
			}
		}
		return false;
	}else if(("direita" == direcao) &&(vertical == 0)){
		for(int l = 0; l < 6; l++){
			for(int c = 4; c >= 0; c--){
				if((posicoes[l][c] == i) && (posicoes[l][c+1] == -1)){
					posicoes[l][c+1] = i;
					if(veiculo == 1){
						posicoes[l][c-2] = -1;
					}else posicoes[l][c-1] = -1;
					return true;
				}
			}
		}
		return false;
	}else if(("esquerda" == direcao) && ((vertical == 0))){
		for(int l = 0; l < 6; l++){
			for(int c = 1; c < 6; c++){
				if((posicoes[l][c] == i) && (posicoes[l][c-1] == -1)){
					posicoes[l][c-1] = i;
					if(veiculo == 1){
						posicoes[l][c+2] = -1;
					}else posicoes[l][c+1] = -1;
					return true;
				}
			}
		}
		return false;	
	}else return false;
}

void specialKeys( int key, int xi, int yi ) {
	
	if(vitoria != 1){
		if (key == GLUT_KEY_RIGHT){
			if(Busca("direita")){
				x[i] += 3;
			}
		}
		else if (key == GLUT_KEY_LEFT){
			if(Busca("esquerda")){
				x[i] -= 3;
			}
			
		}
		else if (key == GLUT_KEY_UP ) {
			if((amarelo == 1) && (y[i] >= 8)){
				if(fase >= 3){
					vitoria = 1;
					y[i] += 3;
					glutPostRedisplay();
					return;
				}else{
					vitoria = 0;
					fase++;
					 if (fase == 3){
					 	i = 0;
					 	veiculo = 1;
						vertical = 1;
						amarelo = 0;
						x[0] = -9.0; y[0] = 9.0;
						x[1] = 3.0; y[1] = 3.5;
						x[2] = 0.0; y[2] = 0.5;
						x[3] = -0.5; y[3] = -0.3;
						x[4] = 0.5; y[4] = 3.0;
						x[5] = 3.0; y[5] = -8.7;
						x[6] = -3.0; y[6] = -5.7;
						x[7] = 6.8; y[7] = 6.0;
					
					}else if (fase == 2){
						i = 0;
						veiculo = 1;
						vertical = 1;
						amarelo = 0;
						x[0] = -9.0; y[0] = 9.0;
						x[1] = 3.0; y[1] = 3.5;
						x[2] = 0.0; y[2] = 0.5;
						x[3] = -0.5; y[3] = -0.3;
						x[4] = 0.5; y[4] = 3.0;
						x[5] = 3; y[5] = -8.7;
					}
					troca();
					glutPostRedisplay();
					return;
				}
			}
			if(Busca("sobe")){
				y[i] += 3;
			}
				
		}
		else if (key == GLUT_KEY_DOWN){
			if(Busca("desce")){
				y[i] -= 3;
			}
		}
	}else return;
	// Requisitar atualização do display
	glutPostRedisplay();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	if(fase == 1){
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texture_id[0]);
		glBegin(GL_POLYGON); // Quadrado caminhao
			glTexCoord2d(1.0, 1.0); glVertex3d(x[0]+2.0, y[0], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(x[0], y[0], 0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(x[0], y[0]-9.0, 0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[0]+2.0, y[0]-9.0, 0.0); // inferior direito
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, texture_id[1]);
		glBegin(GL_POLYGON); // Quadrado cinza vertical
			glTexCoord2d(1.0, 1.0); glVertex3d(x[3], y[3], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(2.0+x[3], y[3], 0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(2.0+x[3], y[3]-6.0, 0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[3], y[3]-6.0, 0.0); // inferior direito
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, texture_id[2]);
		glBegin(GL_POLYGON); // Quadrado amarelo
			glTexCoord2d(1.0, 1.0); glVertex3d(x[2]-2.0, y[2], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(x[2], y[2], 0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(x[2], y[2]-6.0, 0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[2]-2.0, y[2]-6.0, 0.0); // inferior direito
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, texture_id[3]);
		glBegin(GL_POLYGON);//cinza horizontal
			glTexCoord2d(1.0, 1.0); glVertex3d(x[1]-6.0, y[1], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(x[1], y[1], 0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(x[1], y[1]+2.0, 0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[1]-6.0, y[1]+2.0, 0.0); // inferior direito
		glEnd();
		
	}else if(fase == 2){
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texture_id[0]);
		glBegin(GL_POLYGON); //  caminhao
			glTexCoord2d(1.0, 1.0); glVertex3d(x[0]+2.0, y[0], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(x[0], y[0], 0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(x[0], y[0]-9.0, 0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[0]+2.0, y[0]-9.0, 0.0); // inferior direito
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, texture_id[5]);
		glBegin(GL_POLYGON); //  caminhao horizontal
			glTexCoord2d(1.0, 1.0); glVertex3d(x[1]-9.0, y[1], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(x[1], y[1], 0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(x[1], y[1]+2.0, 0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[1]-9.0, y[1]+2.0, 0.0); // inferior direito
		glEnd();
		
		
		glBindTexture(GL_TEXTURE_2D, texture_id[3]);
		glBegin(GL_POLYGON); // cinza horizontal
			glTexCoord2d(1.0, 1.0); glVertex3d(x[2]-6.0, y[2], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(x[2],y[2],0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(x[2],y[2]+2.0,0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[2]-6.0, y[2]+2.0, 0.0); // inferior direito
		glEnd();		
		
				glBindTexture(GL_TEXTURE_2D, texture_id[2]);
		glBegin(GL_POLYGON); //  amarelo
			glTexCoord2d(1.0, 1.0); glVertex3d(x[3]-2.0, y[3], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(x[3], y[3], 0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(x[3], y[3]-6.0, 0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[3]-2.0, y[3]-6.0, 0.0); // inferior direito
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, texture_id[0]);
		glBegin(GL_POLYGON); // Quadrado caminhao
			glTexCoord2d(1.0, 1.0); glVertex3d(x[4]+2.0, y[4], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(x[4], y[4], 0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(x[4], y[4]-9.0, 0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[4]+2.0, y[4]-9.0, 0.0); // inferior direito
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, texture_id[3]);
		glBegin(GL_POLYGON); // cinza horizontal
			glTexCoord2d(1.0, 1.0); glVertex3d(x[5]-6.0, y[5], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(x[5],y[5],0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(x[5],y[5]+2.0,0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[5]-6.0, y[5]+2.0, 0.0); // inferior direito
		glEnd();
		
		glFlush();
		glPopMatrix();
	}else if (fase == 3){
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texture_id[0]);
		glBegin(GL_POLYGON); //  caminhao
			glTexCoord2d(1.0, 1.0); glVertex3d(x[0]+2.0, y[0], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(x[0], y[0], 0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(x[0], y[0]-9.0, 0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[0]+2.0, y[0]-9.0, 0.0); // inferior direito
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, texture_id[5]);
		glBegin(GL_POLYGON); //  caminhao horizontal
			glTexCoord2d(1.0, 1.0); glVertex3d(x[1]-9.0, y[1], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(x[1], y[1], 0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(x[1], y[1]+2.0, 0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[1]-9.0, y[1]+2.0, 0.0); // inferior direito
		glEnd();
		
		
		glBindTexture(GL_TEXTURE_2D, texture_id[3]);
		glBegin(GL_POLYGON); // cinza horizontal
			glTexCoord2d(1.0, 1.0); glVertex3d(x[2]-6.0, y[2], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(x[2],y[2],0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(x[2],y[2]+2.0,0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[2]-6.0, y[2]+2.0, 0.0); // inferior direito
		glEnd();		
		
				glBindTexture(GL_TEXTURE_2D, texture_id[2]);
		glBegin(GL_POLYGON); //  amarelo
			glTexCoord2d(1.0, 1.0); glVertex3d(x[3]-2.0, y[3], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(x[3], y[3], 0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(x[3], y[3]-6.0, 0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[3]-2.0, y[3]-6.0, 0.0); // inferior direito
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, texture_id[0]);
		glBegin(GL_POLYGON); // Quadrado caminhao
			glTexCoord2d(1.0, 1.0); glVertex3d(x[4]+2.0, y[4], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(x[4], y[4], 0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(x[4], y[4]-9.0, 0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[4]+2.0, y[4]-9.0, 0.0); // inferior direito
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, texture_id[3]);
		glBegin(GL_POLYGON); // cinza horizontal
			glTexCoord2d(1.0, 1.0); glVertex3d(x[5]-6.0, y[5], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(x[5],y[5],0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(x[5],y[5]+2.0,0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[5]-6.0, y[5]+2.0, 0.0); // inferior direito
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, texture_id[3]);
		glBegin(GL_POLYGON); // cinza horizontal
			glTexCoord2d(1.0, 1.0); glVertex3d(x[6]-6.0, y[6], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(x[6],y[6],0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(x[6],y[6]+2.0,0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[6]-6.0, y[6]+2.0, 0.0); // inferior direito
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, texture_id[1]);
		glBegin(GL_POLYGON); // Quadrado cinza vertical
			glTexCoord2d(1.0, 1.0); glVertex3d(x[7], y[7], 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(x[7]+2.0, y[7], 0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(x[7]+2.0, y[7]-6.0, 0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(x[7], y[7]-6.0, 0.0); // inferior direito
		glEnd();
		
		

	}else{
		
	}
		glBindTexture(GL_TEXTURE_2D, texture_id[4]);
		glBegin(GL_POLYGON); // Quadrado
			glTexCoord2d(1.0, 1.0); glVertex3d(10.0, 10.0, 0.0); // superior direito
			glTexCoord2d(0.0, 1.0); glVertex3d(-10.0, 10.0, 0.0); // superior esquerdo
			glTexCoord2d(0.0, 0.0); glVertex3d(-10.0, -10.0, 0.0); // inferior esquerdo
			glTexCoord2d(1.0, 0.0); glVertex3d(10.0, -10.0, 0.0); // inferior direito
		glEnd();
		glFlush();
		glPopMatrix();
		
		
	if(vitoria == 1){
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_TEXTURE_2D);
		glColor3f(1.0, 0.0, 0.0);
	
	    renderBitmapString(-2,0,(void *)font,"Voce Venceu!");
	    glEnable(GL_DEPTH_TEST);
		glEnable(GL_TEXTURE_2D);
	}
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 48:
        	if(fase == 1){
	        	i = 0;
				veiculo = 1;
				vertical = 1;
				amarelo = 0;
			}else if(fase == 2){
				i = 0;
				veiculo = 1;
				vertical = 1;
				amarelo = 0;
			}else if(fase == 3){
				i = 0;
				veiculo = 1;
				vertical = 1;
				amarelo = 0;
			}
            break;
        case 49:
			if(fase == 1){
				i = 1;
				veiculo = 0;
				vertical = 0;
				amarelo = 0;
			}else if(fase == 2){
				i = 1;
				veiculo = 1;
				vertical = 0;
				amarelo = 0;
			}else if(fase == 3){
				i = 1;
				veiculo = 1;
				vertical = 0;
				amarelo = 0;
			}
            break;

        case 50:
			if(fase == 1){
				i = 2;
				veiculo = 0;
				vertical = 1;
				amarelo = 1;
			}else if(fase == 2){
				i = 2;
				veiculo = 0;
				vertical = 0;
				amarelo = 0;
			}else if(fase == 3){
				i = 2;
				veiculo = 0;
				vertical = 0;
				amarelo = 0;
			}
            break;

        case 51:
			if(fase == 1){
				i = 3;
				veiculo = 0;
				vertical = 1;
				amarelo = 0;
			}else if(fase == 2){
				i = 3;
				veiculo = 0;
				vertical = 1;
				amarelo = 1;
			}else if(fase == 3){
				i = 3;
				veiculo = 0;
				vertical = 1;
				amarelo = 1;
			}
            break;
        case 52:
        	if(fase == 2){
	        	i = 4;
				veiculo = 1;
				vertical = 1;
				amarelo = 0;
			}else if(fase == 3){
	        	i = 4;
				veiculo = 1;
				vertical = 1;
				amarelo = 0;
			}
            break;
        case 53:
        	if(fase == 2){
	        	i = 5;
				veiculo = 0;
				vertical = 0;
				amarelo = 0;
			}else if(fase == 3){
	        	i = 5;
				veiculo = 0;
				vertical = 0;
				amarelo = 0;
			}
            break;
            case 54:
			if(fase == 3){
	        	i = 6;
				veiculo = 0;
				vertical = 0;
				amarelo = 0;
			}
            break;
            case 55:
			if(fase == 3){
	        	i = 7;
				veiculo = 0;
				vertical = 1;
				amarelo = 0;
			}
            break;
        case 32:
           // reset();
            //pause = 0;
            break;
        case 27:
            exit(0);
            break;
    }
}

void idle()
{
	if (GLenum err = glGetError())
	{
	cerr << "OpenGL ERROR: "<<gluErrorString(err) << endl;
	}

}

void loadTexture(GLuint texture, const char* filename)
{
	glBindTexture(GL_TEXTURE_2D, texture);
	
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(upsidedown);
	unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, STBI_rgb);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data); 
	}
	else
	{
	    std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}

void iniciar()
{
	glClearColor(0.4, 0.4, 0.4, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	
	glGenTextures(5, texture_id);
	
	loadTexture(texture_id[0], nome1);
	loadTexture(texture_id[1], nome2);
	loadTexture(texture_id[2], nome3);
	loadTexture(texture_id[3], nome4);
	loadTexture(texture_id[4], nome5);
	loadTexture(texture_id[5], nome6);
	

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
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}



