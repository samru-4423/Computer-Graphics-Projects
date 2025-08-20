#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

void Sprint( float x, float y, char *st)//Text
{
    int l = strlen(st ); // see how many characters are in text string.
    //glColor3f(1.0,0.0,0.0);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( int i=0; i < l; i++){ // loop until i is greater then l
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, st[i]);
    }
}

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
    glVertex2i(0,145);
    glVertex2i(0,170);
    glVertex2i(1500,170);
    glVertex2i(1500,145);
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
    glVertex2i(930,150);
    glVertex2i(925,180);
    glVertex2i(1325,180);
    glVertex2i(1355,150);

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

    //foot path for walk
    glColor3f(0.75,0.78,0.75);
    glBegin(GL_QUADS);
    glVertex2i(0,115);
    glVertex2i(0,145);
    glVertex2i(1500,145);
    glVertex2i(1500,115);
    glEnd();

    glColor3f(0.314,0.329,0.349);
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glVertex2i(0,135);
    glVertex2i(1500,135);

    glVertex2i(0,125);
    glVertex2i(1500,125);
    glEnd();

    //side relling
    glColor3f(0.36,0.35,0.35);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2i(0,130);
    glVertex2i(1200,130);

    glVertex2i(1300,130);
    glVertex2i(1500,130);

    glVertex2i(40,115);//
    glVertex2i(40,130);

    glVertex2i(80,115);
    glVertex2i(80,130);

    glVertex2i(120,115);
    glVertex2i(120,130);

    glVertex2i(160,115);
    glVertex2i(160,130);

    glVertex2i(200,115);
    glVertex2i(200,130);

    glVertex2i(240,115);
    glVertex2i(240,130);

    glVertex2i(280,115);
    glVertex2i(280,130);

    glVertex2i(320,115);
    glVertex2i(320,130);

    glVertex2i(360,115);
    glVertex2i(360,130);

    glVertex2i(400,115);
    glVertex2i(400,130);

    glVertex2i(440,115);
    glVertex2i(440,130);

    glVertex2i(480,115);
    glVertex2i(480,130);

    glVertex2i(520,115);
    glVertex2i(520,130);

    glVertex2i(560,115);
    glVertex2i(560,130);

    glVertex2i(600,115);
    glVertex2i(600,130);

    glVertex2i(640,115);
    glVertex2i(640,130);

    glVertex2i(680,115);
    glVertex2i(680,130);

    glVertex2i(720,115);
    glVertex2i(720,130);

    glVertex2i(760,115);
    glVertex2i(760,130);

    glVertex2i(800,115);
    glVertex2i(800,130);

    glVertex2i(840,115);
    glVertex2i(840,130);

    glVertex2i(880,115);
    glVertex2i(880,130);

    glVertex2i(920,115);
    glVertex2i(920,130);

    glVertex2i(960,115);
    glVertex2i(960,130);

    glVertex2i(1000,115);
    glVertex2i(1000,130);

    glVertex2i(1040,115);
    glVertex2i(1040,130);

    glVertex2i(1080,115);
    glVertex2i(1080,130);

    glVertex2i(1120,115);
    glVertex2i(1120,130);

    glVertex2i(1160,115);
    glVertex2i(1160,130);

    glVertex2i(1197,115);
    glVertex2i(1197,130);

    glVertex2i(1303,115);
    glVertex2i(1303,130);

    glVertex2i(1340,115);
    glVertex2i(1340,130);

    glVertex2i(1380,115);
    glVertex2i(1380,130);

    glVertex2i(1420,115);
    glVertex2i(1420,130);

    glVertex2i(1460,115);
    glVertex2i(1460,130);
    glEnd();

    //side seat
    glBegin(GL_QUADS);//1
    glVertex2i(730,150);
    glVertex2i(730,160);
    glVertex2i(770,160);
    glVertex2i(770,150);
    glEnd();

    glBegin(GL_QUADS);//2
    glVertex2i(430,150);
    glVertex2i(430,160);
    glVertex2i(470,160);
    glVertex2i(470,150);
    glEnd();

    glBegin(GL_QUADS);//3
    glVertex2i(130,150);
    glVertex2i(130,160);
    glVertex2i(170,160);
    glVertex2i(170,150);
    glEnd();

    glBegin(GL_QUADS);//4
    glVertex2i(1380,150);
    glVertex2i(1380,160);
    glVertex2i(1420,160);
    glVertex2i(1420,150);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(735,150);//1
    glVertex2i(735,145);

    glVertex2i(765,150);
    glVertex2i(765,145);

    glVertex2i(435,150);//2
    glVertex2i(435,145);

    glVertex2i(465,150);
    glVertex2i(465,145);

    glVertex2i(135,150);//3
    glVertex2i(135,145);

    glVertex2i(165,150);
    glVertex2i(165,145);

    glVertex2i(1385,150);//4
    glVertex2i(1385,145);

    glVertex2i(1415,150);
    glVertex2i(1415,145);
    glEnd();

    //water
    glColor3f(0.165,0.478,0.722);
    glBegin(GL_QUADS);
    glVertex2i(0,90);
    glVertex2i(0,0);
    glVertex2i(1500,0);
    glVertex2i(1500,90);
    glEnd();

    //building 1 //Center back House
    glColor3f(0.69,0.69,0.498);//body
    glBegin(GL_QUADS);
    glVertex2i(615,310);
    glVertex2i(615,620);
    glVertex2i(740,665);
    glVertex2i(740,310);
    glEnd();

    glColor3f(0.902,0.902,0.68);//top
    glBegin(GL_QUADS);
    glVertex2i(615,620);
    glVertex2i(740,665);
    glVertex2i(625,690);
    glVertex2i(660,657);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(625,425);
    glVertex2i(625,615);
    glVertex2i(730,615);
    glVertex2i(730,425);
    glEnd();

    glColor3f(0.329,0.329,0.212);
    glBegin(GL_TRIANGLES);
    glVertex2i(625,628);
    glVertex2i(660,657);
    glVertex2i(625,690);
    glEnd();

    //Windows
    glColor3f(0.28,0.43,0.93);
    glBegin(GL_QUADS);
    glVertex2i(628,595);
    glVertex2i(628,608);
    glVertex2i(665,608);
    glVertex2i(665,595);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(675,595);
    glVertex2i(675,608);
    glVertex2i(727,608);
    glVertex2i(727,595);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(628,575);
    glVertex2i(628,588);
    glVertex2i(665,588);
    glVertex2i(665,575);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(675,575);
    glVertex2i(675,588);
    glVertex2i(727,588);
    glVertex2i(727,575);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(628,555);
    glVertex2i(628,568);
    glVertex2i(665,568);
    glVertex2i(665,555);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(675,555);
    glVertex2i(675,568);
    glVertex2i(727,568);
    glVertex2i(727,555);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(628,535);
    glVertex2i(628,548);
    glVertex2i(665,548);
    glVertex2i(665,535);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(675,535);
    glVertex2i(675,548);
    glVertex2i(727,548);
    glVertex2i(727,535);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(628,515);
    glVertex2i(628,528);
    glVertex2i(665,528);
    glVertex2i(665,515);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(675,515);
    glVertex2i(675,528);
    glVertex2i(727,528);
    glVertex2i(727,515);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(628,495);
    glVertex2i(628,508);
    glVertex2i(665,508);
    glVertex2i(665,495);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(675,495);
    glVertex2i(675,508);
    glVertex2i(727,508);
    glVertex2i(727,495);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(628,475);
    glVertex2i(628,488);
    glVertex2i(665,488);
    glVertex2i(665,475);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(675,475);
    glVertex2i(675,488);
    glVertex2i(727,488);
    glVertex2i(727,475);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(628,455);
    glVertex2i(628,468);
    glVertex2i(665,468);
    glVertex2i(665,455);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(675,455);
    glVertex2i(675,468);
    glVertex2i(727,468);
    glVertex2i(727,455);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(628,435);
    glVertex2i(628,448);
    glVertex2i(665,448);
    glVertex2i(665,435);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(675,435);
    glVertex2i(675,448);
    glVertex2i(727,448);
    glVertex2i(727,435);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(628,415);
    glVertex2i(628,428);
    glVertex2i(665,428);
    glVertex2i(665,415);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(675,415);
    glVertex2i(675,428);
    glVertex2i(727,428);
    glVertex2i(727,415);
    glEnd();

    //building 2 //Center-Right house
    glColor3f(0.788,0.76,0.6);
    glBegin(GL_QUADS);
    glVertex2i(880,275);
    glVertex2i(880,650);
    glVertex2i(1050,650);
    glVertex2i(1050,275);
    glEnd();

    glColor3f(0.31,0.29,0.18);
    glBegin(GL_QUADS);
    glVertex2i(870,650);
    glVertex2i(870,660);
    glVertex2i(1060,660);
    glVertex2i(1060,650);
    glEnd();

    //Door
    glColor3f(0.28,0.43,0.93);
    glBegin(GL_QUADS);
    glVertex2i(933,275);
    glVertex2i(933,310);
    glVertex2i(997,310);
    glVertex2i(997,275);
    glEnd();

    //Windows
    glBegin(GL_QUADS);//center
    glVertex2i(940,320);
    glVertex2i(940,650);
    glVertex2i(990,650);
    glVertex2i(990,320);
    glEnd();

    glBegin(GL_QUADS);//two sides
    glVertex2i(890,340);
    glVertex2i(890,360);
    glVertex2i(930,360);
    glVertex2i(930,340);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1000,340);
    glVertex2i(1000,360);
    glVertex2i(1040,360);
    glVertex2i(1040,340);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(890,375);
    glVertex2i(890,395);
    glVertex2i(930,395);
    glVertex2i(930,375);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1000,375);
    glVertex2i(1000,395);
    glVertex2i(1040,395);
    glVertex2i(1040,375);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(890,410);
    glVertex2i(890,430);
    glVertex2i(930,430);
    glVertex2i(930,410);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1000,410);
    glVertex2i(1000,430);
    glVertex2i(1040,430);
    glVertex2i(1040,410);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(890,445);
    glVertex2i(890,465);
    glVertex2i(930,465);
    glVertex2i(930,445);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1000,445);
    glVertex2i(1000,465);
    glVertex2i(1040,465);
    glVertex2i(1040,445);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(890,480);
    glVertex2i(890,500);
    glVertex2i(930,500);
    glVertex2i(930,480);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1000,480);
    glVertex2i(1000,500);
    glVertex2i(1040,500);
    glVertex2i(1040,480);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(890,515);
    glVertex2i(890,535);
    glVertex2i(930,535);
    glVertex2i(930,515);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1000,515);
    glVertex2i(1000,535);
    glVertex2i(1040,535);
    glVertex2i(1040,515);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(890,550);
    glVertex2i(890,570);
    glVertex2i(930,570);
    glVertex2i(930,550);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1000,550);
    glVertex2i(1000,570);
    glVertex2i(1040,570);
    glVertex2i(1040,550);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(890,585);
    glVertex2i(890,605);
    glVertex2i(930,605);
    glVertex2i(930,585);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1000,585);
    glVertex2i(1000,605);
    glVertex2i(1040,605);
    glVertex2i(1040,585);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(890,620);
    glVertex2i(890,640);
    glVertex2i(930,640);
    glVertex2i(930,620);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1000,620);
    glVertex2i(1000,640);
    glVertex2i(1040,640);
    glVertex2i(1040,620);
    glEnd();

    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(965,320);
    glVertex2i(965,650);

    glVertex2i(970,320);
    glVertex2i(970,650);

    glVertex2i(960,320);
    glVertex2i(960,650);

    glVertex2i(965,275);
    glVertex2i(965,310);
    glEnd();

    //street for building 2
    glColor3f(0.76,0.76,0.76);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2i(933,272);
    glVertex2i(960,272);

    glVertex2i(970,272);
    glVertex2i(997,272);

    glVertex2i(933,269);
    glVertex2i(943,269);

    glVertex2i(953,269);
    glVertex2i(977,269);

    glVertex2i(987,269);
    glVertex2i(997,269);

    glVertex2i(933,266);
    glVertex2i(960,266);

    glVertex2i(970,266);
    glVertex2i(997,266);

    glVertex2i(933,263);
    glVertex2i(943,263);

    glVertex2i(953,263);
    glVertex2i(977,263);

    glVertex2i(987,263);
    glVertex2i(997,263);

    glEnd();

    //building 3 //Center front house
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

    //building 4 (Left back house)
    glColor3f(0.86,0.86,0.86);
    glBegin(GL_QUADS);
    glVertex2i(40,285);
    glVertex2i(40,625);
    glVertex2i(445,625);
    glVertex2i(445,285);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(445,285);
    glVertex2i(445,625);
    glVertex2i(465,630);
    glVertex2i(465,305);
    glEnd();

    glColor3f(0.26,0.26,0.26);
    glBegin(GL_POLYGON);
    glVertex2i(35,625);
    glVertex2i(35,645);
    glVertex2i(470,645);
    glVertex2i(470,630);
    glVertex2i(445,625);
    glEnd();

    glColor3f(0,0,0);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2i(41,590);
    glVertex2i(444,590);

    glVertex2i(41,555);
    glVertex2i(444,555);

    glVertex2i(41,520);
    glVertex2i(444,520);

    glVertex2i(41,485);
    glVertex2i(444,485);

    glVertex2i(41,450);
    glVertex2i(444,450);

    glVertex2i(41,415);
    glVertex2i(444,415);

    glVertex2i(41,380);
    glVertex2i(444,380);

    glVertex2i(41,345);
    glVertex2i(444,345);

    glVertex2i(41,310);
    glVertex2i(444,310);

    glVertex2i(445,625);//front deco style
    glVertex2i(464,598);

    glVertex2i(446,555);
    glVertex2i(464,598);

    glVertex2i(446,555);
    glVertex2i(464,528);

    glVertex2i(446,485);
    glVertex2i(464,528);

    glVertex2i(446,485);
    glVertex2i(464,458);

    glVertex2i(446,415);
    glVertex2i(464,458);

    glVertex2i(446,415);
    glVertex2i(464,388);

    glVertex2i(446,345);
    glVertex2i(464,388);

    glVertex2i(445,620);//
    glVertex2i(460,598);

    glVertex2i(445,562);
    glVertex2i(460,598);

    glVertex2i(445,550);
    glVertex2i(460,528);

    glVertex2i(445,492);
    glVertex2i(460,528);

    glVertex2i(445,480);
    glVertex2i(460,458);

    glVertex2i(445,422);
    glVertex2i(460,458);

    glVertex2i(445,410);
    glVertex2i(460,388);

    glVertex2i(445,352);
    glVertex2i(460,388);

    glVertex2i(445,345);
    glVertex2i(465,360);

    glVertex2i(445,340);
    glVertex2i(465,355);

    glVertex2i(445,335);
    glVertex2i(465,350);

    glVertex2i(445,345);
    glVertex2i(465,360);
    glEnd();

    glColor3f(1,1,1);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2i(445,645);
    glVertex2i(445,285);

    glVertex2i(35,625);
    glVertex2i(445,625);

    glVertex2i(445,625);
    glVertex2i(470,630);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(165,285);
    glVertex2i(165,625);
    glVertex2i(185,625);
    glVertex2i(185,285);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(300,285);
    glVertex2i(300,625);
    glVertex2i(320,625);
    glVertex2i(320,285);
    glEnd();

    glColor3f(0.15,0.44,0.3);//Window back border
    glBegin(GL_QUADS);
    glVertex2i(45,595);
    glVertex2i(45,620);
    glVertex2i(160,620);
    glVertex2i(160,595);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(190,595);
    glVertex2i(190,620);
    glVertex2i(295,620);
    glVertex2i(295,595);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(325,595);
    glVertex2i(325,620);
    glVertex2i(440,620);
    glVertex2i(440,595);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(45,560);
    glVertex2i(45,585);
    glVertex2i(160,585);
    glVertex2i(160,560);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(190,560);
    glVertex2i(190,585);
    glVertex2i(295,585);
    glVertex2i(295,560);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(325,560);
    glVertex2i(325,585);
    glVertex2i(440,585);
    glVertex2i(440,560);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(45,525);
    glVertex2i(45,550);
    glVertex2i(160,550);
    glVertex2i(160,525);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(190,525);
    glVertex2i(190,550);
    glVertex2i(295,550);
    glVertex2i(295,525);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(325,525);
    glVertex2i(325,550);
    glVertex2i(440,550);
    glVertex2i(440,525);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(45,490);
    glVertex2i(45,515);
    glVertex2i(160,515);
    glVertex2i(160,490);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(190,490);
    glVertex2i(190,515);
    glVertex2i(295,515);
    glVertex2i(295,490);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(325,490);
    glVertex2i(325,515);
    glVertex2i(440,515);
    glVertex2i(440,490);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(45,455);
    glVertex2i(45,480);
    glVertex2i(160,480);
    glVertex2i(160,455);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(190,455);
    glVertex2i(190,480);
    glVertex2i(295,480);
    glVertex2i(295,455);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(325,455);
    glVertex2i(325,480);
    glVertex2i(440,480);
    glVertex2i(440,455);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(45,420);
    glVertex2i(45,445);
    glVertex2i(160,445);
    glVertex2i(160,420);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(190,420);
    glVertex2i(190,445);
    glVertex2i(295,445);
    glVertex2i(295,420);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(325,420);
    glVertex2i(325,445);
    glVertex2i(440,445);
    glVertex2i(440,420);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(45,385);
    glVertex2i(45,410);
    glVertex2i(160,410);
    glVertex2i(160,385);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(190,385);
    glVertex2i(190,410);
    glVertex2i(295,410);
    glVertex2i(295,385);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(325,385);
    glVertex2i(325,410);
    glVertex2i(440,410);
    glVertex2i(440,385);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(45,350);
    glVertex2i(45,375);
    glVertex2i(160,375);
    glVertex2i(160,350);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(190,350);
    glVertex2i(190,375);
    glVertex2i(295,375);
    glVertex2i(295,350);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(325,350);
    glVertex2i(325,375);
    glVertex2i(440,375);
    glVertex2i(440,350);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(45,315);
    glVertex2i(45,340);
    glVertex2i(160,340);
    glVertex2i(160,315);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(190,315);
    glVertex2i(190,340);
    glVertex2i(295,340);
    glVertex2i(295,315);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(325,315);
    glVertex2i(325,340);
    glVertex2i(440,340);
    glVertex2i(440,315);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(45,287);
    glVertex2i(45,305);
    glVertex2i(160,305);
    glVertex2i(160,287);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(190,287);
    glVertex2i(190,305);
    glVertex2i(295,305);
    glVertex2i(295,287);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(325,287);
    glVertex2i(325,305);
    glVertex2i(440,305);
    glVertex2i(440,287);
    glEnd();

    glColor3f(0.28,0.43,0.93);// Door
    glBegin(GL_QUADS);
    glVertex2i(448,288);
    glVertex2i(448,320);
    glVertex2i(462,330);
    glVertex2i(462,303);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(48,598);
    glVertex2i(48,617);
    glVertex2i(157,617);
    glVertex2i(157,598);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(193,598);
    glVertex2i(193,617);
    glVertex2i(292,617);
    glVertex2i(292,598);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(328,598);
    glVertex2i(328,617);
    glVertex2i(437,617);
    glVertex2i(437,598);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(48,563);
    glVertex2i(48,582);
    glVertex2i(157,582);
    glVertex2i(157,563);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(193,563);
    glVertex2i(193,582);
    glVertex2i(292,582);
    glVertex2i(292,563);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(328,563);
    glVertex2i(328,582);
    glVertex2i(437,582);
    glVertex2i(437,563);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(48,528);
    glVertex2i(48,547);
    glVertex2i(157,547);
    glVertex2i(157,528);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(193,528);
    glVertex2i(193,547);
    glVertex2i(292,547);
    glVertex2i(292,528);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(328,528);
    glVertex2i(328,547);
    glVertex2i(437,547);
    glVertex2i(437,528);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(48,493);
    glVertex2i(48,512);
    glVertex2i(157,512);
    glVertex2i(157,493);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(193,493);
    glVertex2i(193,512);
    glVertex2i(292,512);
    glVertex2i(292,493);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(328,493);
    glVertex2i(328,512);
    glVertex2i(437,512);
    glVertex2i(437,493);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(48,458);
    glVertex2i(48,477);
    glVertex2i(157,477);
    glVertex2i(157,458);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(193,458);
    glVertex2i(193,477);
    glVertex2i(292,477);
    glVertex2i(292,458);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(328,458);
    glVertex2i(328,477);
    glVertex2i(437,477);
    glVertex2i(437,458);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(48,423);
    glVertex2i(48,442);
    glVertex2i(157,442);
    glVertex2i(157,423);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(193,423);
    glVertex2i(193,442);
    glVertex2i(292,442);
    glVertex2i(292,423);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(328,423);
    glVertex2i(328,442);
    glVertex2i(437,442);
    glVertex2i(437,423);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(48,388);
    glVertex2i(48,407);
    glVertex2i(157,407);
    glVertex2i(157,388);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(193,388);
    glVertex2i(193,407);
    glVertex2i(292,407);
    glVertex2i(292,388);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(328,388);
    glVertex2i(328,407);
    glVertex2i(437,407);
    glVertex2i(437,388);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(48,353);
    glVertex2i(48,372);
    glVertex2i(157,372);
    glVertex2i(157,353);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(193,353);
    glVertex2i(193,372);
    glVertex2i(292,372);
    glVertex2i(292,353);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(328,353);
    glVertex2i(328,372);
    glVertex2i(437,372);
    glVertex2i(437,353);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(48,318);
    glVertex2i(48,337);
    glVertex2i(157,337);
    glVertex2i(157,318);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(193,318);
    glVertex2i(193,337);
    glVertex2i(292,337);
    glVertex2i(292,318);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(328,318);
    glVertex2i(328,337);
    glVertex2i(437,337);
    glVertex2i(437,318);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(48,289);
    glVertex2i(48,303);
    glVertex2i(157,303);
    glVertex2i(157,289);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(193,289);
    glVertex2i(193,303);
    glVertex2i(292,303);
    glVertex2i(292,289);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(328,289);
    glVertex2i(328,303);
    glVertex2i(437,303);
    glVertex2i(437,289);
    glEnd();

    glColor3f(0,0,0);
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glVertex2i(455,323);
    glVertex2i(455,295);
    glEnd();

    glColor3f(1,1,1);
    char text1[]="Mascot Industries Limited";
    Sprint(180,632,text1);
    glEnd();

    //building 5 //Black House Left
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

    //building 4 borders
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

    //building 6 (Hospital)
    glColor3f(0.96,0.96,0.96);//white
    glBegin(GL_QUADS);
    glVertex2i(1100,315);
    glVertex2i(1100,425);
    glVertex2i(1400,425);
    glVertex2i(1400,315);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1100,315);
    glVertex2i(1100,425);
    glVertex2i(1090,435);
    glVertex2i(1090,325);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1090,435);
    glVertex2i(1100,425);
    glVertex2i(1400,425);
    glVertex2i(1390,435);
    glEnd();

    glColor3f(0.6,0.753,0.8);//bottom floor
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2i(1100,315);
    glVertex2i(1100,425);

    glVertex2i(1090,435);
    glVertex2i(1100,425);

    glVertex2i(1100,425);
    glVertex2i(1400,425);
    glEnd();

    //glColor3f(0.6,0.753,0.8);
    glBegin(GL_QUADS);
    glVertex2i(1115,270);
    glVertex2i(1115,315);
    glVertex2i(1385,315);
    glVertex2i(1385,270);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1105,280);
    glVertex2i(1115,270);
    glVertex2i(1115,315);
    glVertex2i(1105,315);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1125,325);
    glVertex2i(1125,410);
    glVertex2i(1375,410);
    glVertex2i(1375,325);
    glEnd();

    glColor3f(0.141,0.58,0.709);//Door section
    glBegin(GL_QUADS);
    glVertex2i(1210,265);
    glVertex2i(1210,370);
    glVertex2i(1290,370);
    glVertex2i(1290,265);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1200,270);
    glVertex2i(1210,265);
    glVertex2i(1210,370);
    glVertex2i(1200,375);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(1210,390);
    glVertex2i(1210,370);
    glVertex2i(1200,375);
    glEnd();

    glColor3f(0.6,0.753,0.8);
    glBegin(GL_QUADS);
    glVertex2i(1220,270);
    glVertex2i(1220,350);
    glVertex2i(1280,350);
    glVertex2i(1280,270);
    glEnd();

    glColor3f(1,1,1);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(1115,315);
    glVertex2i(1115,270);

    glVertex2i(1210,265);
    glVertex2i(1210,370);

    glVertex2i(1210,370);
    glVertex2i(1200,375);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2i(1135,330);
    glVertex2i(1200,330);

    glVertex2i(1135,330);
    glVertex2i(1135,395);

    glVertex2i(1135,395);
    glVertex2i(1365,395);

    glVertex2i(1365,395);
    glVertex2i(1365,330);

    glVertex2i(1290,330);
    glVertex2i(1365,330);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(1250,368);
    glVertex2i(1250,352);

    glVertex2i(1241,360);
    glVertex2i(1258,360);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1210,370);
    glVertex2i(1210,390);
    glVertex2i(1290,390);
    glVertex2i(1290,370);
    glEnd();

    glBegin(GL_QUADS);//Main Door
    glVertex2i(1230,270);
    glVertex2i(1230,310);
    glVertex2i(1270,310);
    glVertex2i(1270,270);
    glEnd();

    glColor3f(0,0,0);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(1250,309);
    glVertex2i(1250,271);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_QUADS);//Window background
    glVertex2i(1123,278);
    glVertex2i(1123,307);
    glVertex2i(1192,307);
    glVertex2i(1192,278);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1298,278);
    glVertex2i(1298,307);
    glVertex2i(1377,307);
    glVertex2i(1377,278);
    glEnd();

    glBegin(GL_QUADS);//left two
    glVertex2i(1140,390);
    glVertex2i(1140,367);
    glVertex2i(1195,367);
    glVertex2i(1195,390);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1140,335);
    glVertex2i(1140,358);
    glVertex2i(1195,358);
    glVertex2i(1195,335);
    glEnd();

    glBegin(GL_QUADS);//right two
    glVertex2i(1300,390);
    glVertex2i(1300,367);
    glVertex2i(1360,367);
    glVertex2i(1360,390);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1300,335);
    glVertex2i(1300,358);
    glVertex2i(1360,358);
    glVertex2i(1360,335);
    glEnd();

    glColor3f(0.28,0.43,0.93);//Windows
    glBegin(GL_QUADS);
    glVertex2i(1125,280);
    glVertex2i(1125,305);
    glVertex2i(1190,305);
    glVertex2i(1190,280);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1300,280);
    glVertex2i(1300,305);
    glVertex2i(1375,305);
    glVertex2i(1375,280);
    glEnd();

    glBegin(GL_QUADS);//left two
    glVertex2i(1142,388);
    glVertex2i(1142,369);
    glVertex2i(1193,369);
    glVertex2i(1193,388);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1142,337);
    glVertex2i(1142,356);
    glVertex2i(1193,356);
    glVertex2i(1193,337);
    glEnd();

    glBegin(GL_QUADS);//right two
    glVertex2i(1302,388);
    glVertex2i(1302,369);
    glVertex2i(1358,369);
    glVertex2i(1358,388);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1302,337);
    glVertex2i(1302,356);
    glVertex2i(1358,356);
    glVertex2i(1358,337);
    glEnd();

    glColor3f(1,0,0);
    char text[] = "HOSPITAL";
    Sprint(1225,377,text);
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
