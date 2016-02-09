#include <iostream>

#include <GL/gl.h>

#include <GL/glut.h>

static float HourOfDay = 0.0;
static float HourOfDay2 = 0.0;
static float AnimateIncrement = 0.01;

void drawBitmapText(char *string,float x,float y,float z) 
{  
  char *c;
  glPushMatrix();
  // glTranslatef(1/100000000000000000, 0.0, 0.0);
  HourOfDay += AnimateIncrement;
  int i=0;

  
  for (c = string; *c != '\0'; c++) 
  { 
    if(HourOfDay<200){
        glTranslatef(0.001, 200-HourOfDay, 0);
       
    }
    glRasterPos3f(x+i, y,z);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    i+=20;
  }
  glPopMatrix();
}

void drawBitmapText2(char *string,float x,float y,float z) 
{  
  char *c;
  glPushMatrix();
  // glTranslatef(1/100000000000000000, 0.0, 0.0);
  HourOfDay2 += AnimateIncrement;
  int i=0;

  
  for (c = string; *c != '\0'; c++) 
  { 
    if(HourOfDay2<200){
        glTranslatef(0.001, 200-HourOfDay2, 0);
       
    }
    glRasterPos3f(x+i, y,z);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    i+=20;
  }
  glPopMatrix();
}

void drawStrokeText(char*string,int x,int y,int z)
{
  char *c;
  // glScalef(0.09f,-0.08f,z);

  for (c=string; *c != '\0'; c++)
  {
    glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
  }
}

void reshape(int w,int h) 
{ 
  glViewport(0,0,w,h); 
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity(); 
  gluOrtho2D(0,w,h,0); 
  glMatrixMode(GL_MODELVIEW); 
  glLoadIdentity(); 
}


void render(void)
{ 
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
     // proportion rgb
  if(HourOfDay>200){
    glColor3f(1,1,1); 
    drawBitmapText2("Afrizal Fikri", 100, 250, 0); 
    drawBitmapText2("Azam Iszuhri", 300, 100, 0); 
    drawBitmapText2("Luqman Arifin", 100, 70, 0); 
    drawBitmapText2("Heri Fauzan", 300, 300, 0); 
    drawBitmapText2("Gazandi Cahyadarma", 200, 220, 0); 
    glColor3f(1,1,0.8); 
  }
  else{
    glColor3f(0.3,1,1);
  }
  drawBitmapText("Kelompok : Iyaaaa ??", 100, 180, 0);  // initial position
  glutSwapBuffers(); 
   glutPostRedisplay();  
} 
void OpenGLInit(void)
{
    glShadeModel( GL_FLAT );
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glClearDepth( 1.0 );
    glEnable( GL_DEPTH_TEST );
}


// Main routine
// Set up OpenGL, hook up callbacks, and start the main loop
int main( int argc, char** argv )
{
  // Need to double buffer for animation
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

  // Create and position the graphics window
  glutInitWindowPosition( 0, 0 );
  glutInitWindowSize( 600, 360 );
  glutCreateWindow( "Grafika Meong" );


  OpenGLInit();
  glutDisplayFunc(render);
  glutIdleFunc(render);
  glutReshapeFunc(reshape); 

  // Start the main loop.  glutMainLoop never returns.
  glutMainLoop(  );

  return(0);          // Compiler requires this to be here. (Never reached)
}