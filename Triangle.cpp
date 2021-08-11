#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;

void init()
{
	glClearColor(1.0, 1.0, 0.0, 1.0);	// change the color of window argumentsTaken(R,G,B,aplha);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,800,0.0,800);
}

void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);	
	glBegin( GL_TRIANGLES );
		glVertex2i( 250,300 );
        	glVertex2i( 450,300 ); 
           	glVertex2i( 350,425 );   
           
       glEnd();
       glFlush();
}


int main(int argc, char** argv)
{
		glutInit(&argc,argv);				
		glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
		
		glutInitWindowPosition(200,100);
		glutInitWindowSize(800,800);
		
		glutCreateWindow("Window 1");
		
		init();
		glutDisplayFunc(display);
		
		
		glutMainLoop();
}
