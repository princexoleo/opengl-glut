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

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
     //double buffer display mode: Two buffer(FrontBuffer->swap in front after drawing, BackBuffer-draw,memory)
     //Back = Front
     //Front = Back these are swaping eachother

    //set glut windows position/coordinate x=200, y=100
    glutInitWindowPosition(200,100);

    //set window size width=600 pixel height=600 pixel
    glutInitWindowSize(600,600);

    //create window with title
    glutCreateWindow("GLUT Animation ");


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


    glBegin(GL_POLYGON) ; // this is for creating  triangle

    glVertex2f(0.0,5.0); //p1
    glVertex2f(-4.0,-3.0); //p2
    glVertex2f(4.0,-3.0); //p3
    glVertex2f(5.0,-2.0); //p4

    glEnd(); //and now openGL start drawing


   // glFlush(); //after drawing finish we have to call Flush
   glutSwapBuffers(); // this function will swap back and front buffer
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
