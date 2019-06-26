#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static int year = 10, day = 100;
float rx=0.5,ry=0.5;
double x=8.0,y=10.0;
void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);

}

void display(void)
{

   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);

   glPushMatrix();
      glColor3f (1.0, 0.0, 0.0);
   glutWireSphere(1.0, 40, 32);   /* draw sun */
   glRotatef ((GLfloat) year, 0.0, 0.5, 0.0);
   glTranslatef (2.0, 0.0, 0.0);
   glRotatef ((GLfloat) day, 0.0, 0.0, 1.0);
      glColor3f (1.0, 1.0, 55.0);
      glutWireSphere(0.6, 10, 8);
      glRotatef ((GLfloat) year, 0.0, 0.0, 0.5);
      glColor3f (100.0, 110.0, 55.0);
   glPopMatrix();
   glutSwapBuffers();

}
void reshape (int w, int h)
{

   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
      glFrustum(2.0,2.0,2.0,2.0,2.0,2.0);
}


void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 'd':
         day = (day + 10) % 360;
         glutPostRedisplay();
         break;
      case 'D':
         day = (day - 10) % 360;
         glutPostRedisplay();
                  break;
      case 'y':
         year = (year + 5) % 360;
         glutPostRedisplay();
         break;
      case 'Y':
         year = (year - 5) % 360;
         glutPostRedisplay();
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{

   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
      glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}