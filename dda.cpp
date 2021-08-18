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
	gluOrtho2D(0,600,0,600);
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
	
	glBegin(GL_POINTS);
		glColor3f(1.0f,1.0f,1.0f);
		glVertex2d(x,y);
		for(int i=1;i<=steps;i++)
		{
			x += inc_x;
			y += inc_y;
			glVertex2d(round(x),round(y));
		}
	glEnd();
	glFlush();
			
}

int main(int argc, char** argv)
{	
	printf("Enter First Point: ");
	scanf("%d %d",&Xstart,&Ystart);
	
	printf("Enter Second Point: ");
	scanf("%d %d",&Xend,&Yend);
	
		
	glutInit(&argc,argv);				
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
		
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,600);
	
	glutCreateWindow("DDA Algorithm");
	init();
	glutDisplayFunc(display);				
	glutMainLoop();
}


