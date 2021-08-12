#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);	// change the color of window --> argumentsTaken(R,G,B,aplha);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-10.0,10.0,-10.0,10.0);
}

float x_position = 0.0;
int state = 1;

void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);	
	glBegin( GL_POLYGON );
		glColor3f(1,0,0); 		// change the color of the shape  --> argumentsTaken(R,G,B);
		glVertex2f( x_position-1.0,1.0 );
        	glVertex2f( x_position-1.0,-1.0 ); 
           	glVertex2f( x_position+1.0,-1.0 );
        	glVertex2f( x_position+1.0,1.0 );  
           
       glEnd();
       glutSwapBuffers();
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000/60,timer,0);
	
	switch(state)
	{
		case 1:
			if(x_position < 9)
				x_position += 0.1;
			else
				state = -1;
			break;
		
		case -1:
			if(x_position > -9)
				x_position -= 0.1;
			else
				state = 1;
			break;
	}
}

int main(int argc, char** argv)
{
		glutInit(&argc,argv);				
		glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
		
		glutInitWindowPosition(200,100);
		glutInitWindowSize(800,800);
		
		glutCreateWindow("Window 2");
		
		init();
		glutDisplayFunc(display);
		glutTimerFunc(0,timer,0);
		
		
		glutMainLoop();
}
