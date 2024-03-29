#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display();

void init()
{
    //this will make windows background default to YELLOW
    glClearColor(1.0,1.0,0.0,1.0); //r=1.0 g=1.0, blue=0.0 alpha=1.1

}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    //set glut windows position/coordinate x=200, y=100
    glutInitWindowPosition(200,100);

    //set window size width=500 pixel height=600 pixel
    glutInitWindowSize(500,600);

    //create window with title
    glutCreateWindow("Basic GLUT ");


    glutDisplayFunc(display); //first time need to drawn and this is callback function
    init();
    glutMainLoop(); // This loop terminate then our programe also terminated and this loop hold the window
}

void display()
{
    //always have to clear first
    //clear all pixels in frameBuffer
    glClear(GL_COLOR_BUFFER_BIT); //it clears any type of pixel but we use flag to specification
    glLoadIdentity();//reset matrix transformation
    //draw
    glFlush(); //after drawing finish we have to call Flush
}


