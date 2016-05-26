#include <GL/glut.h>
#include <cmath>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <map>
#include <stack>
using namespace std;

#define PI 3.14159265

//================================================================
//================================================================
double rotate_z = 0;
double rotate_y = 0;
double rotate_x = 0;
double translate_x=0;
double translate_y=0;
int miraX=0;
int miraY=0;
int miraZ=0;
GLuint indice = glGenLists(55);
map<int,GLuint> mapaCubos;
map<int,int> tamanoCubos;
map<int,pair<int,int>> rotacionesCubo;
//================================================================
//variables para poner tiempo en pantalla
//================================================================
time_t horaInicio;
time_t horaActual;
//================================================================
//================================================================

//================================================================
//variables vertices
//================================================================

int vertices[54][4][3]=
{
// Cara 1
 { //vertice 1
  {-3,-3,-3},  {-3,-3,-1},  {-3,-1,-3},  {-3,-1,-1}
 },
 { //vertice 4
  {-3,-3,-1},  {-3,-3,1},  {-3,-1,-1},  {-3,-1,1}
 },
 { //vertice 7
  {-3,-3,1},  {-3,-3,3},  {-3,-1,1},  {-3,-1,3}
 },
 { //vertice 2
  {-3,-1,-3},  {-3,-1,-1},  {-3,1,-3},  {-3,1,-1}
 },
 { //vertice 5
  {-3,-1,-1},  {-3,-1,1},  {-3,1,-1},  {-3,1,1}
 },
 { //vertice 8
  {-3,-1,1},  {-3,-1,3},  {-3,1,1},  {-3,1,3}
 },
 { //vertice 3
  {-3,1,-3},  {-3,1,-1},  {-3,3,-3},  {-3,3,-1}
 },
 { //vertice 6
  {-3,1,-1},  {-3,1,1},  {-3,3,-1},  {-3,3,1}
 },
 { //vertice 9
  {-3,1,1},  {-3,1,3},  {-3,3,1},  {-3,3,3}
 },
// Cara 2
 { //vertice 16
  {3,-3,1},  {3,-3,3},  {3,-1,1},  {3,-1,3}
 },
 { //vertice 13
  {3,-3,-1},  {3,-3,1},  {3,-1,-1},  {3,-1,1}
 },
 { //vertice 10
  {3,-3,-3},  {3,-3,-1},  {3,-1,-3},  {3,-1,-1}
 },
 { //vertice 17
  {3,-1,1},  {3,-1,3},  {3,1,1},  {3,1,3}
 },
 { //vertice 14
  {3,-1,-1},  {3,-1,1},  {3,1,-1},  {3,1,1}
 },
 { //vertice 11
  {3,-1,-3},  {3,-1,-1},  {3,1,-3},  {3,1,-1}
 },
 { //vertice 18
  {3,1,1},  {3,1,3},  {3,3,1},  {3,3,3}
 },
 { //vertice 15
  {3,1,-1},  {3,1,1},  {3,3,-1},  {3,3,1}
 },
 { //vertice 12
  {3,1,-3},  {3,1,-1},  {3,3,-3},  {3,3,-1}
 },

// Cara 3
 { //vertice 25
  {-3,-3,1},  {-3,-3,3},  {-1,-3,1},  {-1,-3,3}
 },
 { //vertice 22
  {-3,-3,-1},  {-3,-3,1},  {-1,-3,-1},  {-1,-3,1}
 },
 { //vertice 19
  {-3,-3,-3},  {-3,-3,-1},  {-1,-3,-3},  {-1,-3,-1}
 },
 { //vertice 26
  {-1,-3,1},  {-1,-3,3},  {1,-3,1},  {1,-3,3}
 },
 { //vertice 23
  {-1,-3,-1},  {-1,-3,1},  {1,-3,-1},  {1,-3,1}
 },
 { //vertice 20
  {-1,-3,-3},  {-1,-3,-1},  {1,-3,-3},  {1,-3,-1}
 },
 { //vertice 27
  {1,-3,1},  {1,-3,3},  {3,-3,1},  {3,-3,3}
 },
 { //vertice 24
  {1,-3,-1},  {1,-3,1},  {3,-3,-1},  {3,-3,1}
 },
 { //vertice 21
  {1,-3,-3},  {1,-3,-1},  {3,-3,-3},  {3,-3,-1}
 },
// Cara 4

 { //vertice 36
  {1,3,1},  {1,3,3},  {3,3,1},  {3,3,3}
 },
 { //vertice 33
  {1,3,-1},  {1,3,1},  {3,3,-1},  {3,3,1}
 },
 { //vertice 30
  {1,3,-3},  {1,3,-1},  {3,3,-3},  {3,3,-1}
 },

 { //vertice 35
  {-1,3,1},  {-1,3,3},  {1,3,1},  {1,3,3}
 },
 { //vertice 32
  {-1,3,-1},  {-1,3,1},  {1,3,-1},  {1,3,1}
 },
 { //vertice 29
  {-1,3,-3},  {-1,3,-1},  {1,3,-3},  {1,3,-1}
 },

 { //vertice 34
  {-3,3,1},  {-3,3,3},  {-1,3,1},  {-1,3,3}
 },
 { //vertice 31
  {-3,3,-1},  {-3,3,1},  {-1,3,-1},  {-1,3,1}
 },
 { //vertice 28
  {-3,3,-3},  {-3,3,-1},  {-1,3,-3},  {-1,3,-1}
 },
// Cara 5

 { //vertice 39
  {1,-3,-3},  {1,-1,-3},  {3,-3,-3},  {3,-1,-3}
  },
 { //vertice 38
  {-1,-3,-3},  {-1,-1,-3},  {1,-3,-3},  {1,-1,-3}
  },
 { //vertice 37
  {-3,-3,-3},  {-3,-1,-3},  {-1,-3,-3},  {-1,-1,-3}
  },

 { //vertice 42
  {1,-1,-3},  {1,1,-3},  {3,-1,-3},  {3,1,-3}
  },
 { //vertice 41
  {-1,-1,-3},  {-1,1,-3},  {1,-1,-3},  {1,1,-3}
  },

 { //vertice 40
  {-3,-1,-3},  {-3,1,-3},  {-1,-1,-3},  {-1,1,-3}
  },

 { //vertice 45
  {1,1,-3},  {1,3,-3},  {3,1,-3},  {3,3,-3}
},
 { //vertice 44
  {-1,1,-3},  {-1,3,-3},  {1,1,-3},  {1,3,-3}
  },
 { //vertice 43
  {-3,1,-3},  {-3,3,-3},  {-1,1,-3},  {-1,3,-3}
  },
// Cara 6
 { //vertice 46
  {-3,-3,3},  {-3,-1,3},  {-1,-3,3},  {-1,-1,3}
  },
 { //vertice 47
  {-1,-3,3},  {-1,-1,3},  {1,-3,3},  {1,-1,3}
  },
 { //vertice 48
  {1,-3,3},  {1,-1,3},  {3,-3,3},  {3,-1,3}
  },
 { //vertice 49
  {-3,-1,3},  {-3,1,3},  {-1,-1,3},  {-1,1,3}
  },
 { //vertice 50
  {-1,-1,3},  {-1,1,3},  {1,-1,3},  {1,1,3}
  },
 { //vertice 51
  {1,-1,3},  {1,1,3},  {3,-1,3},  {3,1,3}
  },
 { //vertice 52
  {-3,1,3},  {-3,3,3},  {-1,1,3},  {-1,3,3}
  },
 { //vertice 53
  {-1,1,3},  {-1,3,3},  {1,1,3},  {1,3,3}
  },
 { //vertice 54
  {1,1,3},  {1,3,3},  {3,1,3},  {3,3,3}
  }
};
 int colores[54]=
{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1,
  2, 2, 2, 2, 2, 2, 2, 2, 2,
  3, 3, 3, 3, 3, 3, 3, 3, 3,
  4, 4, 4, 4, 4, 4, 4, 4, 4,
  5, 5, 5, 5, 5, 5, 5, 5, 5
};
GLfloat color[8][3] =
{
  {1.0,1.0,0.0}, //amarillo 0
  {1.0,1.0,1.0},//Blanco 1
  {0.0,1.0,0.0}, //Verde 2
  {0.0,0.0,1.0},//Azul 3
  {1.0,0.0,0.0}, // Rojo 4
  {0.9,0.38,0.0}, //naranja 5
  {1.0,1.0,1.0},//Blanco
  {0.0,0.0,0.0}//negro
};
//================================================================
//Funciones prototipo
//================================================================
void relizarAccion(string accion,int parametro);
bool completado();
string convierteColores();
void guardarArchivo();
void guardarPasos();
void dibujaVertice(int vertice);
void relizarAccion(string accion,int parametro);
void permutaVertices(int a,int b);
void permutaVerticesRenglon(int a,int b,int renglon);
void permutaVerticesColumna(int a,int b,int columna);
void giraDerecha(int renglon);
void giraIzquierda(int renglon);
void giraArriba(int columna);
void giraAbajo(int columna);
void arriba();
void abajo();
void derecha();
void izquierda();
string posible(string actual);
//================================================================
//================================================================
//================================================================
//Funciones consulta al cubo
//================================================================
bool completado(){
  int numeroInicial=0;
  for (int j = 0; j < 6; ++j)
  {
    numeroInicial=colores[j*9];
    for(int i=0;i<9;i++){
      if(numeroInicial!=colores[j*9+i])
        return false;
    }
  }
  return true;
}

string convierteColores(){
  string nodos="";
  for (int i = 0; i < 54; ++i)
  {
     nodos+=to_string(colores[i]);
  }
  return nodos;
}
string posible(string actual){
  
}

//=================================================================
//Funciones OpenGL
//=================================================================

void dibujaVertice(int vertice){

  glLineWidth(1.0);
  glBegin(GL_QUADS);

    glColor3fv(color[colores[vertice]]);

    glVertex3iv(vertices[vertice][0]);
    glVertex3iv(vertices[vertice][1]);
    glVertex3iv(vertices[vertice][3]);
    glVertex3iv(vertices[vertice][2]);

  glEnd();
  glLineWidth(4.0);
  glBegin(GL_LINE_STRIP);

    glColor3fv(color[7]);
    glVertex3iv(vertices[vertice][0]);
    glVertex3iv(vertices[vertice][1]);
    glVertex3iv(vertices[vertice][3]);
    glVertex3iv(vertices[vertice][2]);
    glVertex3iv(vertices[vertice][0]);
  glEnd();
}
void cuboRubik()
{
  glColor3f(1.0,1.0,1.0);
  time(&horaActual);
  double segundos=difftime(horaActual,horaInicio);
  string cadena="Puntaje : "+to_string(segundos);
 

  glRasterPos2i( -14, 6);
  for (int i = 0; i < cadena.size(); ++i)
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, cadena[i]);
  }
  for (int k = 0; k < 2; ++k)
  for(int i=0;i<tamanoCubos[k];i=i+1){ 

    glPushMatrix();
     glTranslatef(k*20.0,0,0);
    glRotatef(rotacionesCubo[k].first,0,1,0);
    glRotatef(rotacionesCubo[k].second,0,0,1);
    glCallList(mapaCubos[k]+i+1); 
    glPopMatrix();
  }
 

}


//=================================================================
//=================================================================
//Funciones para operar en el cubo
//=================================================================

void specialKeys( int key, int x, int y )
{
    
    glutPostRedisplay();
}

void teclado(unsigned char key,int x, int y){
  if (key == 'd')
  translate_x-=1;
  else if (key == 'a')
  translate_x+=1;
  else if (key == 's')
  translate_y+=1;
  else if (key == 'w')
  translate_y-=1;
  glutPostRedisplay();
}
void myMouse(int x, int y){
    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY, winZ;
    GLdouble posX, posY, posZ;

    glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
    glGetDoublev( GL_PROJECTION_MATRIX, projection );
    glGetIntegerv( GL_VIEWPORT, viewport );

    winX = (float)x;
    winY = (float)viewport[3] - (float)y;  // Subtract The Current Mouse Y Coordinate 

    glReadPixels( x, winY, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );//Reads the depth buffer


    gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);


    miraX=posX;
    miraY=posY;
    miraZ=posZ;
}
void display()
{

  //scanf("%d ",&numeroInicio);

    glClearColor( 0, 0, 0, 1 );
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );
    gluPerspective( 60, w / h, 0.1, 300 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt
        (
        40, 4, 10,
        0, 0, 0,
        0, 0, 1
        );

glTranslatef(translate_x, translate_y, 0.0 );

    cuboRubik();
    glPointSize(7.0);
    glBegin(GL_POINTS);

    glVertex3f(3.0,-3.0,-3.0);
    glVertex3f(3.0,3.0,-3.0);
    glVertex3f(3.0,-3.0,3.0);
    glVertex3f(3.0,3.0,3.0);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
      for(int i =0; i <= 300; i++){
      double angle = 2 * PI * i / 300;
      double x = cos(angle);
      double y = sin(angle);
      glVertex3d(25,miraY+2*x,miraZ+2*y);
      }
    glEnd();
    glutSwapBuffers();
}
void motion(int x,int y){
  

    rotacionesCubo[0].first+=1;
    rotacionesCubo[1].first+=1;
  
  myMouse(x,y);
  cout<<"mira en x="<<x<<" y="<<y<<endl;
 glutPostRedisplay();
}

void mouseClickHandler(int button, int state, int x, int y)
{
  
    tamanoCubos[0]--;
    tamanoCubos[1]--;
    rotacionesCubo[0].second+=20.0;
    rotacionesCubo[1].second+=20.0;
    glutPostRedisplay();
  


}

void dibujaVerticeLista(int contenedor,int vertice){

  glLineWidth(1.0);
  if(!mapaCubos[contenedor]){
    mapaCubos[contenedor]=glGenLists(55);
    tamanoCubos[contenedor]=54;
    rotacionesCubo[contenedor].first=0.0;
    rotacionesCubo[contenedor].second=0.0;
  }
   glNewList( mapaCubos[contenedor]+vertice+1,GL_COMPILE);
    glBegin(GL_QUADS);

      glColor3fv(color[colores[vertice]]);

      glVertex3iv(vertices[vertice][0]);
      glVertex3iv(vertices[vertice][1]);
      glVertex3iv(vertices[vertice][3]);
      glVertex3iv(vertices[vertice][2]);

    glEnd();
    
        glLineWidth(4.0);
        glBegin(GL_LINE_STRIP);

          glColor3fv(color[7]);
          glVertex3iv(vertices[vertice][0]);
          glVertex3iv(vertices[vertice][1]);
          glVertex3iv(vertices[vertice][3]);
          glVertex3iv(vertices[vertice][2]);
          glVertex3iv(vertices[vertice][0]);
        glEnd();
    
  glEndList();

}
void init(){
  time(&horaInicio);
  for (int k = 0; k < 2; ++k)
  for(int i=0;i<54;i=i+1){ 
    dibujaVerticeLista(k,i);
  }
}
//=================================================================
//=================================================================
int main( int argc, char **argv )
{
   
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
    glutInitWindowSize( 640, 480 );
    glutCreateWindow( "GLUT" );
    glutDisplayFunc( display );
    glutSpecialFunc( specialKeys );
    glutKeyboardFunc(teclado);
    glutMouseFunc(mouseClickHandler);
   // glutMotionFunc(motion);
    glutPassiveMotionFunc(motion);
    glEnable( GL_DEPTH_TEST );

  glutSetCursor(GLUT_CURSOR_NONE);
   init();
    glutMainLoop();
    return 0;
}
