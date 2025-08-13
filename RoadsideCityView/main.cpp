#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

void myDisplay(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(0.529,0.807,0.922);
    glBegin(GL_QUADS);
    glVertex2i(0,320);
    glVertex2i(0,750);
    glVertex2i(1500,750);
    glVertex2i(1500,320);
    glEnd();

    //grass
    glColor3f(0.05,0.8,0.31);
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(0,170);
    glVertex2i(1500,170);
    glVertex2i(1500,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(0,260);
    glVertex2i(0,320);
    glVertex2i(500,320);
    glVertex2i(440,260);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(550,260);
    glVertex2i(600,320);
    glVertex2i(1500,320);
    glVertex2i(1500,260);
    glEnd();

    //road
    glColor3f(0.51,0.51,0.51);
    glBegin(GL_QUADS);
    glVertex2i(0,180);
    glVertex2i(0,250);
    glVertex2i(1500,250);
    glVertex2i(1500,180);

    glBegin(GL_QUADS);
    glVertex2i(930,145);
    glVertex2i(925,180);
    glVertex2i(1325,180);
    glVertex2i(1355,145);

    glBegin(GL_QUADS);
    glVertex2i(433,250);
    glVertex2i(504,320);
    glVertex2i(600,320);
    glVertex2i(547,250);
    glEnd();

    //road side line
    glColor3f(1,1,1);
    glLineWidth(3);
    glBegin(GL_LINES);

    //top
    glVertex2i(0,240);
    glVertex2i(420,240);

    glVertex2i(562,240);
    glVertex2i(1500,240);

    glVertex2i(546,260);
    glVertex2i(595,320);

    glVertex2i(453,260);
    glVertex2i(512,320);

    //bottom
    glVertex2i(0,190);
    glVertex2i(925,190);

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

    //Zebra crossing
    glVertex2i(460,260);
    glVertex2i(475,275);

    glVertex2i(467,260);
    glVertex2i(482,275);

    glVertex2i(474,260);
    glVertex2i(489,275);

    glVertex2i(481,260);
    glVertex2i(496,275);

    glVertex2i(488,260);
    glVertex2i(503,275);

    glVertex2i(495,260);
    glVertex2i(510,275);

    glVertex2i(502,260);
    glVertex2i(517,275);

    glVertex2i(509,260);
    glVertex2i(524,275);

    glVertex2i(516,260);
    glVertex2i(531,275);

    glVertex2i(523,260);
    glVertex2i(538,275);

    glVertex2i(530,260);
    glVertex2i(545,275);

    glVertex2i(537,260);
    glVertex2i(552,275);
    glEnd();//

    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(350,235);
    glVertex2i(390,235);

    glVertex2i(342,230);
    glVertex2i(382,230);

    glVertex2i(334,225);
    glVertex2i(374,225);

    glVertex2i(326,220);
    glVertex2i(366,220);

    glVertex2i(318,215);
    glVertex2i(358,215);

    glVertex2i(310,210);
    glVertex2i(350,210);

    glVertex2i(302,205);
    glVertex2i(342,205);

    glVertex2i(294,200);
    glVertex2i(334,200);

    glVertex2i(286,195);
    glVertex2i(326,195);//

    glVertex2i(575,235);
    glVertex2i(615,235);

    glVertex2i(570,230);
    glVertex2i(610,230);

    glVertex2i(565,225);
    glVertex2i(605,225);

    glVertex2i(560,220);
    glVertex2i(600,220);

    glVertex2i(555,215);
    glVertex2i(595,215);

    glVertex2i(550,210);
    glVertex2i(590,210);

    glVertex2i(545,205);
    glVertex2i(585,205);

    glVertex2i(540,200);
    glVertex2i(580,200);

    glVertex2i(535,195);
    glVertex2i(575,195);
    glEnd();

    //foot path bottom
    glColor3f(1,0.75,0.29);
    glBegin(GL_QUADS);
    glVertex2i(0,170);
    glVertex2i(0,180);
    glVertex2i(925,180);
    glVertex2i(927,170);


    glBegin(GL_QUADS);
    glVertex2i(1333,170);
    glVertex2i(1325,180);
    glVertex2i(1500,180);
    glVertex2i(1500,170);

    //foot path top
    glVertex2i(0,250);
    glVertex2i(0,260);
    glVertex2i(444,260);
    glVertex2i(433,250);

    glVertex2i(426,260);
    glVertex2i(490,320);
    glVertex2i(504,320);
    glVertex2i(443,260);

    glVertex2i(547,250);
    glVertex2i(600,320);
    glVertex2i(615,320);
    glVertex2i(562,250);

    glVertex2i(547,250);
    glVertex2i(554,260);
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

    //Door
    glColor3f(0.28,0.43,0.93);
    glBegin(GL_QUADS);
    glVertex2i(840,260);
    glVertex2i(840,295);
    glVertex2i(866,295);
    glVertex2i(866,260);
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
    glVertex2i(866,260);
    glVertex2i(866,295);
    glEnd();

    glColor3f(0,0,0);
    glLineWidth(0.2);
    glBegin(GL_LINES);
    glVertex2i(625,310);
    glVertex2i(875,310);

    glVertex2i(625,308);
    glVertex2i(875,308);
    glEnd();

    glColor3f(1,1,1);
    glLineWidth(0.2);
    glBegin(GL_LINES);
    glVertex2i(853,295);
    glVertex2i(853,260);
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

    //building2
    glColor3f(0.322,0.318,0.318);
    glBegin(GL_QUADS);
    glVertex2i(125,260);
    glVertex2i(125,410);
    glVertex2i(425,410);
    glVertex2i(425,260);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(425,260);
    glVertex2i(425,410);
    glVertex2i(436,420);
    glVertex2i(436,270);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(135,430);
    glVertex2i(135,440);
    glVertex2i(443,440);
    glVertex2i(430,430);
    glEnd();

    glBegin(GL_QUADS);//...
    glVertex2i(370,410);
    glVertex2i(370,460);
    glVertex2i(420,460);
    glVertex2i(420,410);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(365,460);
    glVertex2i(365,480);
    glVertex2i(425,480);
    glVertex2i(425,460);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(120,410);
    glVertex2i(120,430);
    glVertex2i(430,430);
    glVertex2i(430,410);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(430,410);
    glVertex2i(430,430);
    glVertex2i(443,440);
    glVertex2i(443,420);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(120,430);
    glVertex2i(135,440);
    glVertex2i(135,430);
    glEnd();

    //building 2 borders
    glColor3f(1,1,1);
    glLineWidth(0.2);
    glBegin(GL_LINES);
    glVertex2i(125,310);
    glVertex2i(425,310);

    glVertex2i(125,360);
    glVertex2i(425,360);

    glVertex2i(120,410);
    glVertex2i(430,410);

    glVertex2i(425,260);
    glVertex2i(425,410);

    glVertex2i(125,260);
    glVertex2i(125,410);

    glVertex2i(120,430);
    glVertex2i(430,430);

    glVertex2i(430,410);
    glVertex2i(443,420);

    glVertex2i(443,440);
    glVertex2i(443,420);

    glVertex2i(120,410);
    glVertex2i(120,430);

    glVertex2i(430,410);
    glVertex2i(430,430);

    glVertex2i(425,360);
    glVertex2i(436,370);

    glVertex2i(425,310);
    glVertex2i(436,320);

    glVertex2i(430,430);
    glVertex2i(442,440);

    glVertex2i(365,460);
    glVertex2i(425,460);

    glVertex2i(365,480);
    glVertex2i(425,480);

    glVertex2i(370,430);
    glVertex2i(370,460);

    glVertex2i(420,430);
    glVertex2i(420,460);

    glVertex2i(365,460);
    glVertex2i(365,480);

    glVertex2i(425,460);
    glVertex2i(425,480);

    glVertex2i(135,440);
    glVertex2i(370,440);

    glVertex2i(420,440);
    glVertex2i(443,440);

    glVertex2i(120,430);
    glVertex2i(135,440);

    glVertex2i(135,430);
    glVertex2i(135,440);
    glEnd();

    //Door
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2i(245,260);
    glVertex2i(245,300);
    glVertex2i(305,300);
    glVertex2i(305,260);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(385,430);
    glVertex2i(385,450);
    glVertex2i(405,450);
    glVertex2i(405,430);
    glEnd();

    glColor3f(0,0,0);
    glLineWidth(0.2);
    glBegin(GL_LINES);
    glVertex2i(275,260);
    glVertex2i(275,299);

    glVertex2i(395,431);
    glVertex2i(395,449);
    glEnd();

    //Big windows
    glColor3f(0.28,0.43,0.93);
    glBegin(GL_QUADS);
    glVertex2i(340,272);
    glVertex2i(340,300);
    glVertex2i(400,300);
    glVertex2i(400,272);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(150,272);
    glVertex2i(150,300);
    glVertex2i(210,300);
    glVertex2i(210,272);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(340,322);
    glVertex2i(340,350);
    glVertex2i(400,350);
    glVertex2i(400,322);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(150,322);
    glVertex2i(150,350);
    glVertex2i(210,350);
    glVertex2i(210,322);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(340,372);
    glVertex2i(340,400);
    glVertex2i(400,400);
    glVertex2i(400,372);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(150,372);
    glVertex2i(150,400);
    glVertex2i(210,400);
    glVertex2i(210,372);
    glEnd();

    //Small windows
    glBegin(GL_QUADS);
    glVertex2i(285,325);
    glVertex2i(285,345);
    glVertex2i(300,345);
    glVertex2i(300,325);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(250,325);
    glVertex2i(250,345);
    glVertex2i(265,345);
    glVertex2i(265,325);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(285,375);
    glVertex2i(285,395);
    glVertex2i(300,395);
    glVertex2i(300,375);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(250,375);
    glVertex2i(250,395);
    glVertex2i(265,395);
    glVertex2i(265,375);
    glEnd();

    //Big window shadow
    glColor3f(0.06,0.168,0.6);
    glBegin(GL_TRIANGLES);
    glVertex2i(210,300);
    glVertex2i(210,272);
    glVertex2i(195,272);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(400,300);
    glVertex2i(400,272);
    glVertex2i(385,272);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(210,350);
    glVertex2i(210,322);
    glVertex2i(195,322);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(400,350);
    glVertex2i(400,322);
    glVertex2i(385,322);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(210,400);
    glVertex2i(210,372);
    glVertex2i(195,372);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(400,400);
    glVertex2i(400,372);
    glVertex2i(385,372);
    glEnd();

    //Small windows shadow
    glBegin(GL_TRIANGLES);
    glVertex2i(300,345);
    glVertex2i(300,325);
    glVertex2i(290,325);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(265,345);
    glVertex2i(265,325);
    glVertex2i(255,325);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(300,395);
    glVertex2i(300,375);
    glVertex2i(290,375);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(265,395);
    glVertex2i(265,375);
    glVertex2i(255,375);
    glEnd();

    //building 3
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2i(825,300);
    glVertex2i(825,308);
    glVertex2i(875,308);
    glVertex2i(875,300);
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
