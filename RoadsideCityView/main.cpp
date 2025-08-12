#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

void myDisplay(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(0,750);
    glVertex2i(1500,750);
    glVertex2i(1500,0);
    glEnd();

    //grass
    glColor3f(0.05,0.8,0.31);
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(0,170);
    glVertex2i(1500,170);
    glVertex2i(1500,0);
    glEnd();

    //road
    glColor3f(0.51,0.51,0.51);
    glBegin(GL_QUADS);
    glVertex2i(0,180);
    glVertex2i(0,250);
    glVertex2i(1500,250);
    glVertex2i(1500,180);

    glVertex2i(145,145);
    glVertex2i(175,180);
    glVertex2i(575,180);
    glVertex2i(570,145);

    glVertex2i(930,145);
    glVertex2i(925,180);
    glVertex2i(1325,180);
    glVertex2i(1355,145);
    glEnd();

    //road side line
    glColor3f(1,1,1);
    glLineWidth(3);
    glBegin(GL_LINES);

    glVertex2i(0,190);
    glVertex2i(175,190);

    glVertex2i(575,190);
    glVertex2i(925,190);

    glVertex2i(0,240);
    glVertex2i(1500,240);

    glVertex2i(190,180);
    glVertex2i(560,180);

    glVertex2i(940,180);
    glVertex2i(1310,180);
    glEnd();

    //road inner line
    glColor3f(1,1,1);
    glLineWidth(3);
    glBegin(GL_LINES);

    glVertex2i(25,215);
    glVertex2i(125,215);

    glVertex2i(175,215);
    glVertex2i(275,215);

    glVertex2i(325,215);
    glVertex2i(425,215);

    glVertex2i(475,215);
    glVertex2i(575,215);

    glVertex2i(625,215);
    glVertex2i(725,215);

    glVertex2i(775,215);
    glVertex2i(875,215);

    glVertex2i(925,215);
    glVertex2i(1025,215);

    glVertex2i(1075,215);
    glVertex2i(1175,215);

    glVertex2i(1225,215);
    glVertex2i(1325,215);

    glVertex2i(1375,215);
    glVertex2i(1475,215);
    glEnd();

    //foot path bottom
    glColor3f(1,0.75,0.29);
    glBegin(GL_QUADS);
    glVertex2i(0,170);
    glVertex2i(0,180);
    glVertex2i(175,180);
    glVertex2i(167,170);

    glBegin(GL_QUADS);
    glVertex2i(575,170);
    glVertex2i(575,180);
    glVertex2i(925,180);
    glVertex2i(925,170);

    glBegin(GL_QUADS);
    glVertex2i(1333,170);
    glVertex2i(1325,180);
    glVertex2i(1500,180);
    glVertex2i(1500,170);

    //foot path top
    glVertex2i(0,250);
    glVertex2i(0,260);
    glVertex2i(1500,260);
    glVertex2i(1500,250);
    glEnd();

    //building 1
    glColor3f(0.93,0.88,0.77);
    glBegin(GL_QUADS);
    glVertex2i(625,260);
    glVertex2i(625,410);
    glVertex2i(875,410);
    glVertex2i(875,260);
    glEnd();

    glColor3f(0,0,0);
    glLineWidth(0.2);
    glBegin(GL_LINES);
    glVertex2i(625,310);
    glVertex2i(875,310);

    glVertex2i(625,308);
    glVertex2i(875,308);
    glEnd();

    //Door
    glColor3f(0.28,0.43,0.93);
    glBegin(GL_QUADS);
    glVertex2i(840,260);
    glVertex2i(840,295);
    glVertex2i(865,295);
    glVertex2i(865,260);
    glEnd();

    //Big windows
    glBegin(GL_QUADS);
    glVertex2i(640,272);
    glVertex2i(640,300);
    glVertex2i(820,300);
    glVertex2i(820,272);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(640,325);
    glVertex2i(640,355);
    glVertex2i(820,355);
    glVertex2i(820,325);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(640,380);
    glVertex2i(640,400);
    glVertex2i(820,400);
    glVertex2i(820,380);
    glEnd();

    //Small windows
    glBegin(GL_QUADS);
    glVertex2i(835,380);
    glVertex2i(835,400);
    glVertex2i(845,400);
    glVertex2i(845,380);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(860,380);
    glVertex2i(860,400);
    glVertex2i(870,400);
    glVertex2i(870,380);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(835,330);
    glVertex2i(835,350);
    glVertex2i(845,350);
    glVertex2i(845,330);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(860,330);
    glVertex2i(860,350);
    glVertex2i(870,350);
    glVertex2i(870,330);
    glEnd();

    //Big window shadow
    glColor3f(0.06,0.168,0.6);
    glBegin(GL_TRIANGLES);
    glVertex2i(820,300);
    glVertex2i(820,272);
    glVertex2i(805,272);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(820,355);
    glVertex2i(820,325);
    glVertex2i(805,325);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(820,400);
    glVertex2i(820,380);
    glVertex2i(810,380);
    glEnd();

    //Small windows shadow
    glBegin(GL_TRIANGLES);
    glVertex2i(835,380);
    glVertex2i(845,380);
    glVertex2i(845,400);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(860,380);
    glVertex2i(870,380);
    glVertex2i(870,400);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(835,330);
    glVertex2i(845,330);
    glVertex2i(845,350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(860,330);
    glVertex2i(870,330);
    glVertex2i(870,350);
    glEnd();

    //Door shadow
    glBegin(GL_TRIANGLES);
    glVertex2i(845,260);
    glVertex2i(865,260);
    glVertex2i(865,295);
    glEnd();

    //Roof
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2i(825,300);
    glVertex2i(825,308);
    glVertex2i(875,308);
    glVertex2i(875,300);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(615,410);
    glVertex2i(625,425);
    glVertex2i(875,425);
    glVertex2i(885,410);
    glEnd();

    glFlush();
}
void myInit (void){
    glClearColor(0.0, 0.0,0.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1500.0, 0.0, 750.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1500, 750);
    glutInitWindowPosition (10, 10);
    glutCreateWindow ("Roadside City View");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}
