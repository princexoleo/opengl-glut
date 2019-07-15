#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
float Red=0.0;
float Green =0.0;
float Blue = 0.0;

void display();
void reshape(int,int);
void timer(int);

void init()
{
    //this will make windows background default to Black
    glClearColor(0.0,0.0,0.0,1.0); //r=1.0 g=1.0, blue=0.0 alpha=1.1



}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
     //double buffer display mode: Two buffer(FrontBuffer->swap in front after drawing, BackBuffer-draw,memory)
     //Back = Front
     //Front = Back these are Swaping Each other

    //set glut windows position/coordinate x=200, y=100
    glutInitWindowPosition(200,100);

    //set window size width=600 pixel height=600 pixel
    glutInitWindowSize(600,600);

    //create window with title
    glutCreateWindow("GLUT Animation ");


    glutDisplayFunc(display); //first time need to drawn and this is callback function
    glutReshapeFunc(reshape); //reshape function is callback function, this function call when window change shape or reshape windows

    //this call display function in millisceonds again and again
    glutTimerFunc(1000,timer,0); //this function need for animations. take 3 parameter(miliseconds, timer callback, int)

    init();
    glutMainLoop(); // This loop terminate then our program also terminated and this loop hold the window
}

float x_position = -10.0;
int state =1;

void display()
{
    //always have to clear first
    //clear all pixels in frameBuffer
    glClear(GL_COLOR_BUFFER_BIT); //it clears any type of pixel but we use flag to specification
    glLoadIdentity();//reset matrix transformation
    // begin drawing staffs


    glBegin(GL_QUADS) ; // this is for creating  triangle
    //change color
    Red = 1.0;
    glColor3f(Red,Green,Blue); //

    glVertex2f(x_position, 2.0);
    glVertex2f(x_position, -2.0);
    glVertex2f(x_position+2.0, -2.0);
    glVertex2f(x_position+2.0 , 2.0);

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

void timer(int)
{
    glutPostRedisplay(); //again call display function . redisplay fun called 60 times in 1 seconds
    glutTimerFunc(1000/60, timer, 0); //60fps means per seconds 60 frame rate
    //1 seconds = 1000 milli=seconds , in 1 seconds this function call 60 time
    //now to change x position with small value for animations
    switch(state)
    {
        case 1:
            if(x_position <8)
            {
                x_position+=0.15 ; // x coordinate move by 0.15 in every display function call
                //this moving position makes animation to us
                Green = 0.0;
                Red = 1.0;
            }
            else
            {
              state =-1;
            }
            break;

        case -1:
                if(x_position>-10)
                {
                  x_position-=0.15 ;
                  Red =0.0;
                  Green =1.0;
                }
                else
                {
                    state = 1;
                }

    }
}
