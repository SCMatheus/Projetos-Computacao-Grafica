#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <fstream>

void objeto(){
    std::string line;
    std::ifstream myfile ("D:/Projetos/Exercicio-1/coordenadas.txt");
    float x = 0;
    float y = 0;
    int indice = 0;
    std::string result[2];
    if (myfile.is_open())
    {
        glBegin(GL_LINE_LOOP);
            while (!myfile.eof()) //enquanto end of file for false continua
            {
              getline (myfile,line);
              indice = 0;
              for(int i = 0; i < int(line.size()); i++){
                  if(line[i] != ' '){
                    result[indice] += line[i];
                  }else
                  {
                      indice++;
                  }
              }
              x = std::stof(result[0]);
              y = std::stof(result[1]);
              result[0] = "";
              result[1] = "";
              //std::cout<<x<<" "<<y<<std::endl;
              glColor3f( 0.0, 1.0, 1.0 );
              glVertex2f(x,y);


            }
        glEnd();
        myfile.close();
    }

    else std::cout << "Unable to open file";

}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    objeto(); //objeto original
    glutSwapBuffers();
}



int main (int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);

    glClearColor(1,1,1,1);
    glOrtho(-30,28,-20,20,-2,2);
    glutMainLoop();

  return EXIT_SUCCESS;
}
