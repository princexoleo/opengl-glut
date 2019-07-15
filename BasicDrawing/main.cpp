#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
float Red=0.0;
float Green =0.0;
float Blue = 0.0;

void display();
void reshape(int,int);

void init()
{
    //this will make windows background default to Black
    glClearColor(Red,Green,Blue,1.0); //r=1.0 g=1.0, blue=0.0 alpha=1.1

}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    //set glut windows position/coordinate x=200, y=100
    glutInitWindowPosition(200,100);

    //set window size width=600 pixel height=600 pixel
    glutInitWindowSize(600,600);

    //create window with title
    glutCreateWindow("Basic GLUT ");


    glutDisplayFunc(display); //first time need to drawn and this is callback function
    glutReshapeFunc(reshape); //reshape function is callback function, this function call when window change shape or reshape windows
    init();
    glutMainLoop(); // This loop terminate then our program also terminated and this loop hold the window
}

void display()
{
    //always have to clear first
    //clear all pixels in frameBuffer
    glClear(GL_COLOR_BUFFER_BIT); //it clears any type of pixel but we use flag to specification
    glLoadIdentity();//reset matrix transformation
    // begin drawing staffs

    //change size of point 10 pixel
    glPointSize(10.0);

    // glBegin(GL_POINT); // this only for creating point

    glBegin(GL_TRIANGLES) ; // this is for creating  triangle
    //for creating triangle we need 3 points
    //group of 3 point will be create triangle
    glVertex2f(0.0, 0.5); //point 1
    glVertex2f(4.0, -3.0); //point 2
    glVertex2f(-4.0,-3.0);//point 3


    //vertex
    //glVertex2f(-5.0,-5.0); // this will create a point at (-5.0,-5.0)
    //glVertex2f(5.0,5.0);// this will create a point at (5.0,5.0)
    //

    //
    glEnd(); //and now openGL start drawing


    glFlush(); //after drawing finish we have to call Flush
}

void reshape(int w, int h) //w=width h=height
{
    //reshape window and now clip window its new reshape size
    //ViewPort means its small size of window and everything will be shown if it is in viewport
    //shown area
    glViewport(0,0,(GLsizei)w,(GLsizei)h); //needs 1 point(x,y) and width and height

    //Projection Matrix
    glMatrixMode(GL_PROJECTION) ;//switch to projection matrix. when we need to change projection then we use it

    glLoadIdentity();//reset matrix transformation

    //new projection: orthogonal projection 2D
    gluOrtho2D(-10,10,-10,10 ) ;//left=-10 , right=10 bottom=-10 , top=10

    //Model View Matrix
    glMatrixMode(GL_MODELVIEW); // normally we draw staffs in modelView matrix mode always



}


