
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<math.h>



void handleResize(int w, int h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective

	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
		(double)w / (double)h, //The width-to-height ratio
		1.0,                   //The near z clipping coordinate
		200.0);                //The far z clipping coordinate
}



void drawShape(){
    glPushMatrix();
    for(int i=5;i<=10;i++){
       glTranslated(20.0f,15.0f,0.0f);
        float angle=180.0/i;
        float x = 10 * cos(angle*3.14159265/180.0);
        float y = 10 * sin(angle*3.14159265/180.0);
        for(int j=0;j<i;j++){
            glRotatef(360.0/i ,0.0f,0.0f,1.0f);
            switch(i){
                case 5 : glColor3f(1.0,0.0,0.0f); break;
                case 6 : glColor3f(0.0,1.0,0.0f); break;
                case 7 : glColor3f(0.0,0.0,1.0f); break;
                case 8 : glColor3f(1.0,1.0,0.0f); break;
                case 9 : glColor3f(0.0,1.0,1.0f); break;
                case 10 :glColor3f(1.0,0.0,1.0f); break;

            }
            glBegin(GL_TRIANGLES);
            glVertex3f(x,y,-150.0f);
            glVertex3f(x,-1*y,-150.0f);
            glVertex3f(0,0,-150.0f);
            glEnd();


        }

    }

     glPopMatrix();

}
static void display(void)
{
    glTranslated(-70.f,-55.0f,0.0f);
    drawShape();

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

    }

    glutPostRedisplay();
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");


    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutReshapeFunc(handleResize);

    glutMainLoop();

    return EXIT_SUCCESS;
}
