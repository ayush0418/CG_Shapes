#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int Xstart,Xend,Ystart,Yend;

void init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);	// change the color of window --> argumentsTaken(R,G,B,aplha);
	glMatrixMode(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-300,300,-300,300);
}


void display()
{
	int dx = Xend - Xstart;
	int dy = Yend - Ystart;
	int steps = dx;
	
	if(abs(dy)>abs(dx))
		steps = dy;
	
	double x = 1.0 * Xstart;
	double y = 1.0 * Ystart;
	
	double inc_x = 1.0 * dx/steps;
	double inc_y = 1.0 * dy/steps;
	float theta;
	
	glBegin(GL_POINTS);
		glColor3f(1.0f,1.0f,1.0f);
		glVertex2d(x,y);
		for(int i=1;i<=steps;i++)
		{
			x += inc_x;
			y += inc_y;
			glVertex2d(round(x),round(y));
		}
		for(int i=0;i<360;i++)
		{
			theta = i*3.142/180;
			glVertex2f(150*cos(theta), 150*sin(theta));
		}
		for(int i=0;i<360;i++)
		{
			theta = i*3.142/180;
			glVertex2f(50 - 10*cos(theta), 50 - 10*sin(theta));
		}
		for(int i=0;i<360;i++)
		{
			theta = i*3.142/180;
			glVertex2f(10*cos(theta) - 50, 50 - 10*sin(theta));
		}
		for(int i=210;i<330;i++)
		{
			theta = i*3.142/180;
			glVertex2f(25*cos(theta), 25*sin(theta) - 50);
		}
	glEnd();
	glFlush();
	
	
	
			
}

int main(int argc, char** argv)
{	
	Xend = 0;
	Xstart = 0;
	Yend = 10;
	Ystart = -25;
	
	
		
	glutInit(&argc,argv);				
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
		
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,600);
	
	glutCreateWindow("HAPPY FACE");
	init();
	glutDisplayFunc(display);				
	glutMainLoop();
}


