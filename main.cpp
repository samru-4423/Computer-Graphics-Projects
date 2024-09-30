#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int DayNight = 0;  // 0 = day, 1 = night
double cloudPosition1 = 0.0f;
double cloudPosition2 = 0.0f;
double cloudPosition3 = 0.0f;
double cloudPosition4 = 0.0f;
double ambulance = 0.0f;
double car1 = 0.0f;
double truck1 = 0.0f;
double ship = 0.0f;
double plane = 0.0f;
float speed = 0.5f;//Plane speed
float speed1 = 0.0f;//Ambulance speed
float speed2=0.5f;//Ship speed
double sun = 0.0f;
double moon = 0.0f;
char text[] = "HOSPITAL";

void Sprint( float x, float y, char *st)//Text
{
    int l = strlen(st ); // see how many characters are in text string.
    glColor3f(1.0,0.0,0.0);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( int i=0; i < l; i++){ // loop until i is greater then l
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
    }
}

void drawwheel(float x, float y , float rad ){//Wheels
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/180 ;
        float r=rad-0.15;
		float dx = x+r * cos(A);
		float dy = y+r * sin(A);
		glVertex3f(dx,dy,0 );
	}
	glEnd();
}

void drawcloud(float x, float y , float r){//Cloud
	glBegin(GL_POLYGON);
	for(int i=0;i<360;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/180 ;

		float dx = r * cos(A);
		float dy = r * sin(A);
		glVertex2f(x+dx,y+dy );
	}
	glEnd();
}

void circle(float x, float y , float r ){
	glBegin(GL_POLYGON);
	for(int i=0;i<360;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/180 ;

		float dx = r * cos(A);
		float dy = r * sin(A);
		glVertex2f(x+dx,y+dy );
	}
	glEnd();
}

void drawsky(){//Sky
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(0,750);
    glVertex2i(1500,750);
    glVertex2i(1500,0);
    glEnd();
}

void drawwater(){//water
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(0,175);
    glVertex2i(1500,175);
    glVertex2i(1500,0);
    glEnd();
}

void drawroadside(){//roadside
    glBegin(GL_QUADS);
    glVertex2i(0,175);
    glVertex2i(0,190);
    glVertex2i(1500,190);
    glVertex2i(1500,175);

    glVertex2i(0,370);
    glVertex2i(0,385);
    glVertex2i(1500,385);
    glVertex2i(1500,370);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2i(0,155);
    glVertex2i(0,175);
    glVertex2i(1500,175);
    glVertex2i(1500,155);
    glEnd();
}

void drawroad(){//road
    glColor3f(0.204,0.204,0.204);
    glBegin(GL_QUADS);
    glVertex2i(0,190);
    glVertex2i(0,370);
    glVertex2i(1500,370);
    glVertex2i(1500,190);
    glEnd();
}

void drawbridge(){//Wooden bridge beside water
    glBegin(GL_QUADS);
    glVertex2i(265,175);
    glVertex2i(335,175);
    glVertex2i(295,150);
    glVertex2i(225,150);

    glVertex2i(295,150);
    glVertex2i(335,175);
    glVertex2i(375,160);
    glVertex2i(335,135);

    glVertex2i(375,160);
    glVertex2i(600,160);
    glVertex2i(560,135);
    glVertex2i(335,135);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(245,150);
    glVertex2i(285,175);

    glVertex2i(270,150);
    glVertex2i(310,175);

    glVertex2i(295,150);
    glVertex2i(335,175);

    glVertex2i(225,150);
    glVertex2i(295,150);

    glVertex2i(225,150);
    glVertex2i(265,175);

    glVertex2i(315,142);
    glVertex2i(355,167);

    glVertex2i(335,135);
    glVertex2i(375,160);

    glVertex2i(335,135);
    glVertex2i(295,150);

    glVertex2i(348,143);
    glVertex2i(573,143);

    glVertex2i(362,152);
    glVertex2i(587,152);

    glVertex2i(560,135);
    glVertex2i(335,135);

    glVertex2i(600,160);
    glVertex2i(560,135);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glLineWidth(8);
    glBegin(GL_LINES);
    glVertex2i(230,150);
    glVertex2i(230,125);

    glVertex2i(290,150);
    glVertex2i(290,125);

    glVertex2i(340,135);
    glVertex2i(340,125);

    glVertex2i(550,135);
    glVertex2i(550,125);
    glEnd();
}

void drawbridgerailing(){
    //glColor3f(0.902,0.568,0.219);
    glLineWidth(8);
    glBegin(GL_LINES);
    glVertex2i(270,175);
    glVertex2i(270,193);

    glVertex2i(235,152);
    glVertex2i(235,170);

    glVertex2i(290,152);
    glVertex2i(290,170);

    glVertex2i(340,137);
    glVertex2i(340,155);

    glVertex2i(460,137);
    glVertex2i(460,155);
    glEnd();

    //glColor3f(0.902,0.568,0.219);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(270,190);
    glVertex2i(235,167);

    glVertex2i(235,167);
    glVertex2i(290,167);

    glVertex2i(290,167);
    glVertex2i(340,152);

    glVertex2i(340,152);
    glVertex2i(460,152);
    glEnd();
}

void drawbuilding1(){//building 1

    glBegin(GL_QUADS);
    //glColor3f(0.807,0.494,0.0);
    glVertex2i(1300,385);
    glVertex2i(1300,585);
    glVertex2i(1450,585);
    glVertex2i(1450,385);

    glVertex2i(1300,585);
    glVertex2i(1335,605);
    glVertex2i(1485,605);
    glVertex2i(1450,585);

    glVertex2i(1450,385);
    glVertex2i(1450,585);
    glVertex2i(1485,605);
    glVertex2i(1485,405);
    glEnd();

    glColor3f(0.0,0.0,0.0); //building 1 black line
    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2i(1300,585);
    glVertex2i(1450,585);

    glVertex2i(1450,385);
    glVertex2i(1450,585);

    glVertex2i(1450,585);
    glVertex2i(1485,605);
    glEnd();

    glColor3f(0.937,0.937,0.937); //building 1 windows
    glBegin(GL_QUADS);
    glVertex2i(1325,540);//left 3
    glVertex2i(1325,565);
    glVertex2i(1350,565);
    glVertex2i(1350,540);

    glVertex2i(1400,540);//right 3
    glVertex2i(1400,565);
    glVertex2i(1425,565);
    glVertex2i(1425,540);

    glVertex2i(1325,495);//left 2
    glVertex2i(1325,520);
    glVertex2i(1350,520);
    glVertex2i(1350,495);

    glVertex2i(1400,495);//right 2
    glVertex2i(1400,520);
    glVertex2i(1425,520);
    glVertex2i(1425,495);

    glVertex2i(1325,450);//left 1
    glVertex2i(1325,475);
    glVertex2i(1350,475);
    glVertex2i(1350,450);

    glVertex2i(1400,450);//right 1
    glVertex2i(1400,475);
    glVertex2i(1425,475);
    glVertex2i(1425,450);

    glVertex2i(1354,385);//door
    glVertex2i(1354,435);
    glVertex2i(1396,435);
    glVertex2i(1396,385);
    glEnd();

    glColor3f(0.0,0.0,0.0); //building 1 black lines
    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2i(1375,385);//door line
    glVertex2i(1375,435);

    glVertex2i(1300,530);//others
    glVertex2i(1450,530);

    glVertex2i(1485,550);
    glVertex2i(1450,530);

    glVertex2i(1300,485);
    glVertex2i(1450,485);

    glVertex2i(1485,505);
    glVertex2i(1450,485);

    glVertex2i(1300,443);
    glVertex2i(1450,443);

    glVertex2i(1485,463);
    glVertex2i(1450,443);
    glEnd();
}

void drawbuilding2(){//building 2

    //glColor3f(0.082,0.0,0.349);
    glBegin(GL_QUADS);
    glVertex2i(1050,405);
    glVertex2i(1050,605);
    glVertex2i(1200,605);
    glVertex2i(1200,405);

    glVertex2i(1200,405);
    glVertex2i(1200,605);
    glVertex2i(1230,625);
    glVertex2i(1230,425);

    glVertex2i(1050,605);
    glVertex2i(1080,625);
    glVertex2i(1230,625);
    glVertex2i(1200,605);
    glEnd();

    glColor3f(1.0,1.0,1.0); //building 2 white line
    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2i(1050,605);
    glVertex2i(1200,605);

    glVertex2i(1200,605);
    glVertex2i(1230,625);

    glVertex2i(1200,605);
    glVertex2i(1200,405);

    glVertex2i(1050,550);
    glVertex2i(1200,550);

    glVertex2i(1230,570);
    glVertex2i(1200,550);

    glVertex2i(1050,505);
    glVertex2i(1200,505);

    glVertex2i(1230,525);
    glVertex2i(1200,505);

    glVertex2i(1050,463);
    glVertex2i(1200,463);

    glVertex2i(1230,483);
    glVertex2i(1200,463);
    glEnd();

    glColor3f(0.937,0.937,0.937); //building 2 windows

    glBegin(GL_QUADS);//left
    glVertex2i(1075,560);
    glVertex2i(1075,585);
    glVertex2i(1100,585);
    glVertex2i(1100,560);

    glVertex2i(1075,515);
    glVertex2i(1075,540);
    glVertex2i(1100,540);
    glVertex2i(1100,515);

    glVertex2i(1075,470);
    glVertex2i(1075,495);
    glVertex2i(1100,495);
    glVertex2i(1100,470);

    glVertex2i(1150,560);//right
    glVertex2i(1150,585);
    glVertex2i(1175,585);
    glVertex2i(1175,560);

    glVertex2i(1150,515);
    glVertex2i(1150,540);
    glVertex2i(1175,540);
    glVertex2i(1175,515);

    glVertex2i(1150,470);
    glVertex2i(1150,495);
    glVertex2i(1175,495);
    glVertex2i(1175,470);

    glVertex2i(1105,405);//door
    glVertex2i(1105,455);
    glVertex2i(1145,455);
    glVertex2i(1145,405);
    glEnd();

    glColor3f(0.0,0.0,0.0); //building 2 black door line
    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2i(1125,455);
    glVertex2i(1125,405);
    glEnd();

    glColor3f(0.753,0.753,0.753); //building 2 paka rasta
    glBegin(GL_QUADS);
    glVertex2i(1075,385);
    glVertex2i(1105,405);
    glVertex2i(1145,405);
    glVertex2i(1115,385);
    glEnd();
}

void drawb2frontwall(){//building 2front wall
    glBegin(GL_QUADS);//1
    glVertex2i(1115,385);
    glVertex2i(1115,435);
    glVertex2i(1250,435);
    glVertex2i(1250,385);

    glVertex2i(1250,385);//2
    glVertex2i(1250,435);
    glVertex2i(1290,460);
    glVertex2i(1290,410);

    glVertex2i(1230,410);//3
    glVertex2i(1230,460);
    glVertex2i(1290,460);
    glVertex2i(1290,410);

    glVertex2i(975,385);//4
    glVertex2i(975,435);
    glVertex2i(1075,435);
    glVertex2i(1075,385);

    glVertex2i(975,385);//5
    glVertex2i(975,435);
    glVertex2i(1025,460);
    glVertex2i(1025,410);

    glVertex2i(1025,410);//6
    glVertex2i(1025,460);
    glVertex2i(1050,460);
    glVertex2i(1050,410);
    glEnd();

    glColor3f(0.0,0.0,0.0); //building 2 black door line
    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2i(1115,435);
    glVertex2i(1250,435);

    glVertex2i(1250,435);
    glVertex2i(1250,385);

    glVertex2i(1290,460);
    glVertex2i(1250,435);

    glVertex2i(975,435);
    glVertex2i(1075,435);

    glVertex2i(975,435);
    glVertex2i(1025,460);

    glVertex2i(1025,460);
    glVertex2i(1050,460);

    glVertex2i(1025,460);
    glVertex2i(1025,435);
    glEnd();
}

void drawb2bulb(){
    glColor3f(0.0,0.0,0.0);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(1250,435);
    glVertex2i(1250,445);

    glVertex2i(1288,460);
    glVertex2i(1288,470);

    glVertex2i(978,435);
    glVertex2i(978,445);

    glVertex2i(1027,460);
    glVertex2i(1027,470);
    glEnd();
}

void drawbuilding3(){//building 3
    //glColor3f(0.239,0.522,0.776);
    glBegin(GL_QUADS);
    glVertex2i(650,405);
    glVertex2i(650,545);
    glVertex2i(840,545);
    glVertex2i(840,405);

    glVertex2i(650,545);
    glVertex2i(680,565);
    glVertex2i(870,565);
    glVertex2i(840,545);

    glVertex2i(840,405);
    glVertex2i(840,545);
    glVertex2i(870,565);
    glVertex2i(870,425);
    glEnd();

    glColor3f(1.0,1.0,1.0); //building 3 white line
    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2i(650,545);
    glVertex2i(840,545);

    glVertex2i(840,545);
    glVertex2i(870,565);

    glVertex2i(840,545);
    glVertex2i(840,405);
    glEnd();

    glColor3f(1.0,0.0,0.0); //hospital logo

    glBegin(GL_QUADS);
    glVertex2i(740,540);
    glVertex2i(740,510);
    glVertex2i(750,510);
    glVertex2i(750,540);

    glVertex2i(725,530);
    glVertex2i(725,520);
    glVertex2i(765,520);
    glVertex2i(765,530);
    glEnd();

    glColor3f(0.0,0.0,0.0); //building 3 black border

    glBegin(GL_QUADS);
    glVertex2i(650,470);
    glVertex2i(650,480);
    glVertex2i(840,480);
    glVertex2i(840,470);

    glVertex2i(840,470);
    glVertex2i(840,480);
    glVertex2i(870,500);
    glVertex2i(870,490);
    glEnd();

    glColor3f(1.0,1.0,1.0);//door

    glBegin(GL_QUADS);
    glVertex2i(720,405);
    glVertex2i(720,450);
    glVertex2i(770,450);
    glVertex2i(770,405);
    glEnd();

    glColor3f(0.0,0.0,0.0); //building 3 black door line
    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2i(745,450);
    glVertex2i(745,405);
    glEnd();

    glColor3f(0.753,0.753,0.753); //paka rasta

    glBegin(GL_QUADS);
    glVertex2i(690,385);
    glVertex2i(720,405);
    glVertex2i(770,405);
    glVertex2i(740,385);
    glEnd();
}

void drawbuilding4(){//building 4
    glBegin(GL_QUADS);
    glVertex2i(180,385);
    glVertex2i(180,585);
    glVertex2i(440,585);
    glVertex2i(440,385);

    glVertex2i(180,585);
    glVertex2i(210,615);
    glVertex2i(470,615);
    glVertex2i(440,585);

    glVertex2i(440,385);
    glVertex2i(440,585);
    glVertex2i(470,615);
    glVertex2i(470,415);
    glEnd();

    glColor3f(1.0,1.0,1.0); //building 4 white line
    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2i(180,585);
    glVertex2i(440,585);

    glVertex2i(440,585);
    glVertex2i(470,615);

    glVertex2i(440,585);
    glVertex2i(440,385);
    glEnd();

    glColor3f(1.0,1.0,1.0); //building 4 windows

    glBegin(GL_QUADS);
    glVertex2i(205,520);//left
    glVertex2i(205,560);
    glVertex2i(245,560);
    glVertex2i(245,520);

    glVertex2i(205,450);
    glVertex2i(205,490);
    glVertex2i(245,490);
    glVertex2i(245,450);

    glVertex2i(375,520);//right
    glVertex2i(375,560);
    glVertex2i(415,560);
    glVertex2i(415,520);

    glVertex2i(375,450);
    glVertex2i(375,490);
    glVertex2i(415,490);
    glVertex2i(415,450);

    glVertex2i(290,460);//stair window
    glVertex2i(290,570);
    glVertex2i(330,570);
    glVertex2i(330,460);
    glEnd();

    glColor3f(1.0,1.0,1.0);//door

    glBegin(GL_QUADS);
    glVertex2i(275,385);
    glVertex2i(275,435);
    glVertex2i(345,435);
    glVertex2i(345,385);
    glEnd();

    glColor3f(1.0,1.0,1.0); //building 4 white line
    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2i(310,435);
    glVertex2i(310,385);

    glVertex2i(180,505);
    glVertex2i(290,505);

    glVertex2i(330,505);
    glVertex2i(440,505);

    glVertex2i(440,505);
    glVertex2i(470,535);

    glVertex2i(180,443);
    glVertex2i(440,443);

    glVertex2i(440,443);
    glVertex2i(470,473);
    glEnd();

    glColor3f(0.0,0.0,0.0); //building 4 black door line
    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2i(310,385);
    glVertex2i(310,435);
    glEnd();
}

void drawtree(){//tree
    glBegin(GL_QUADS);
    glVertex2i(945,405);//1
    glVertex2i(945,490);
    glVertex2i(965,490);
    glVertex2i(965,405);

    glVertex2i(580,395);//2
    glVertex2i(580,480);
    glVertex2i(600,480);
    glVertex2i(600,395);

    glVertex2i(510,440);//3
    glVertex2i(510,490);
    glVertex2i(520,490);
    glVertex2i(520,440);

    glVertex2i(105,395);//4
    glVertex2i(105,490);
    glVertex2i(125,490);
    glVertex2i(125,395);
    glEnd();
}

void drawleaf(){//leaf
    glBegin(GL_TRIANGLES);//1
    glVertex2i(910,475);
    glVertex2i(955,550);
    glVertex2i(1000,475);

    glVertex2i(915,505);//1
    glVertex2i(955,590);
    glVertex2i(995,505);

    glVertex2i(530,465);//2
    glVertex2i(590,560);
    glVertex2i(650,465);

    glVertex2i(535,500);//2
    glVertex2i(590,595);
    glVertex2i(645,500);

    glVertex2i(540,535);//2
    glVertex2i(590,630);
    glVertex2i(640,535);

    glVertex2i(490,475);//3
    glVertex2i(515,520);
    glVertex2i(540,475);

    glVertex2i(493,490);//3
    glVertex2i(515,535);
    glVertex2i(537,490);

    glVertex2i(496,505);//3
    glVertex2i(515,550);
    glVertex2i(534,505);

    glVertex2i(60,470);//4
    glVertex2i(115,570);
    glVertex2i(170,470);

    glVertex2i(65,500);//4
    glVertex2i(115,600);
    glVertex2i(165,500);

    glVertex2i(70,530);//4
    glVertex2i(115,630);
    glVertex2i(160,530);
    glEnd();
}

void drawwhitemid(){
    glColor3f(1.0, 1.0, 1.0); //white in mid road

    //upper
    glBegin(GL_QUADS);//1
    glVertex2i(50,328);
    glVertex2i(50,333);
    glVertex2i(125,333);
    glVertex2i(125,328);

    glVertex2i(175,328);//2
    glVertex2i(175,333);
    glVertex2i(250,333);
    glVertex2i(250,328);

    glVertex2i(300,328);//3
    glVertex2i(300,333);
    glVertex2i(375,333);
    glVertex2i(375,328);

    glVertex2i(425,328);//4
    glVertex2i(425,333);
    glVertex2i(500,333);
    glVertex2i(500,328);

    glVertex2i(550,328);//5
    glVertex2i(550,333);
    glVertex2i(625,333);
    glVertex2i(625,328);

    glVertex2i(675,328);//6
    glVertex2i(675,333);
    glVertex2i(750,333);
    glVertex2i(750,328);

    glVertex2i(800,328);//7
    glVertex2i(800,333);
    glVertex2i(875,333);
    glVertex2i(875,328);

    glVertex2i(925,328);//8
    glVertex2i(925,333);
    glVertex2i(1000,333);
    glVertex2i(1000,328);

    glVertex2i(1050,328);//9
    glVertex2i(1050,333);
    glVertex2i(1125,333);
    glVertex2i(1125,328);

    glVertex2i(1175,328);//10
    glVertex2i(1175,333);
    glVertex2i(1250,333);
    glVertex2i(1250,328);

    glVertex2i(1300,328);//11
    glVertex2i(1300,333);
    glVertex2i(1375,333);
    glVertex2i(1375,328);

    glVertex2i(1425,328);//12
    glVertex2i(1425,333);
    glVertex2i(1490,333);
    glVertex2i(1490,328);
    glEnd();

    //lower
    glBegin(GL_QUADS);
    glVertex2i(50,233);//1
    glVertex2i(50,238);
    glVertex2i(125,238);
    glVertex2i(125,233);

    glVertex2i(175,233);//2
    glVertex2i(175,238);
    glVertex2i(250,238);
    glVertex2i(250,233);

    glVertex2i(300,233);//3
    glVertex2i(300,238);
    glVertex2i(375,238);
    glVertex2i(375,233);

    glVertex2i(425,233);//4
    glVertex2i(425,238);
    glVertex2i(500,238);
    glVertex2i(500,233);

    glVertex2i(550,233);//5
    glVertex2i(550,238);
    glVertex2i(625,238);
    glVertex2i(625,233);

    glVertex2i(675,233);//6
    glVertex2i(675,238);
    glVertex2i(750,238);
    glVertex2i(750,233);

    glVertex2i(800,233);//7
    glVertex2i(800,238);
    glVertex2i(875,238);
    glVertex2i(875,233);

    glVertex2i(925,233);//8
    glVertex2i(925,238);
    glVertex2i(1000,238);
    glVertex2i(1000,233);

    glVertex2i(1050,233);//9
    glVertex2i(1050,238);
    glVertex2i(1125,238);
    glVertex2i(1125,233);

    glVertex2i(1175,233);//10
    glVertex2i(1175,238);
    glVertex2i(1250,238);
    glVertex2i(1250,233);

    glVertex2i(1300,233);//11
    glVertex2i(1300,238);
    glVertex2i(1375,238);
    glVertex2i(1375,233);

    glVertex2i(1425,233);//12
    glVertex2i(1425,238);
    glVertex2i(1490,238);
    glVertex2i(1490,233);
    glEnd();
}

void drawgrass(){//Grass
    glBegin(GL_QUADS);
    glVertex2i(0,275);
    glVertex2i(0,285);
    glVertex2i(1500,285);
    glVertex2i(1500,275);

    glBegin(GL_QUADS);
    glVertex2i(0,385);
    glVertex2i(0,460);
    glVertex2i(1500,460);
    glVertex2i(1500,385);
    glEnd();
}

void drawambulance(){//Ambulance
    glBegin(GL_POLYGON);
    glVertex2i(550,370);
    glVertex2i(550,430);
    glVertex2i(650,430);
    glVertex2i(651,429);
    glVertex2i(652,428);
    glVertex2i(685,400);
    glVertex2i(685,370);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);//Ambulance wheels
    drawwheel(575.0,370.0,14.0);
    drawwheel(665.0,370.0,14.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    drawwheel(575.0,370.0,7.0);
    drawwheel(665.0,370.0,7.0);
    glEnd();

    glColor3f(0.66,0.8,0.84);//Ambulance windows

    glBegin(GL_QUADS);
    glVertex2i(555,400);
    glVertex2i(555,425);
    glVertex2i(625,425);
    glVertex2i(625,400);

    glBegin(GL_QUADS);
    glVertex2i(635,400);
    glVertex2i(635,425);
    glVertex2i(647,425);
    glVertex2i(678,400);
    glEnd();

    glColor3f(1.0,0.0,0.0); //Ambulance back light
    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2i(550,425);
    glVertex2i(550,400);
    glEnd();

    glColor3f(1.0,0.851,0.4); //Ambulance front light

    glBegin(GL_QUADS);//1
    glVertex2i(675,385);
    glVertex2i(675,395);
    glVertex2i(685,395);
    glVertex2i(685,385);
    glEnd();

    glColor3f(0.0,0.0,0.0); //Ambulance ges
    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2i(630,428);
    glVertex2i(630,372);

    glVertex2i(635,395);
    glVertex2i(643,395);

    glVertex2i(625,395);
    glVertex2i(617,395);
    glEnd();
}

void drawtruck1(){//Truck 1
    glBegin(GL_QUADS);//1 front
    glVertex2i(425,370);
    glVertex2i(455,370);
    glVertex2i(455,310);
    glVertex2i(425,310);

    glBegin(GL_QUADS);
    glVertex2i(455,310);
    glVertex2i(455,370);
    glVertex2i(485,345);
    glVertex2i(485,310);
    glEnd();

    glColor3f(0.67,0.67,0.67);
    glBegin(GL_QUADS);//1 cargo
    glVertex2i(260,310);
    glVertex2i(260,380);
    glVertex2i(425,380);
    glVertex2i(425,310);
    glEnd();
}

void truck1ges(){
    glColor3f(0.0, 0.0, 0.0);//Truck 1 wheels
    drawwheel(310.0,310.0,17.0);
    drawwheel(455.0,310.0,17.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    drawwheel(310.0,310.0,9.0);
    drawwheel(455.0,310.0,9.0);
    glEnd();

    glColor3f(0.66,0.8,0.84);//Truck windows

    glBegin(GL_QUADS);
    glVertex2i(430,365);
    glVertex2i(452,365);
    glVertex2i(476,345);
    glVertex2i(430,345);
    glEnd();

    glColor3f(0.0,0.0,0.0); //Truck ges
    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2i(430,340);//1
    glVertex2i(440,340);
    glEnd();

    glColor3f(1.0,0.851,0.4); //Truck light

    glBegin(GL_QUADS);//1
    glVertex2i(475,330);
    glVertex2i(475,340);
    glVertex2i(485,340);
    glVertex2i(485,330);
    glEnd();
}

void drawtruck2(){//Truck 2
    glBegin(GL_QUADS);//2 front
    glVertex2i(1205,215);
    glVertex2i(1205,275);
    glVertex2i(1235,275);
    glVertex2i(1235,215);

    glBegin(GL_QUADS);
    glVertex2i(1175,215);
    glVertex2i(1175,250);
    glVertex2i(1205,275);
    glVertex2i(1205,215);
    glEnd();

    glColor3f(0.67,0.67,0.67);
    glBegin(GL_QUADS);//2 cargo
    glVertex2i(1235,215);
    glVertex2i(1235,285);
    glVertex2i(1400,285);
    glVertex2i(1400,215);
    glEnd();
}

void truck2ges(){
    glColor3f(0.0, 0.0, 0.0);//Truck 2 wheels
    drawwheel(1205.0,215.0,17.0);
    drawwheel(1350.0,215.0,17.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    drawwheel(1205.0,215.0,9.0);
    drawwheel(1350.0,215.0,9.0);
    glEnd();

    glColor3f(0.66,0.8,0.84);//Truck windows
    glBegin(GL_QUADS);
    glVertex2i(1184,250);
    glVertex2i(1207,270);
    glVertex2i(1230,270);
    glVertex2i(1230,250);
    glEnd();

    glColor3f(0.0,0.0,0.0); //Truck ges
    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2i(1220,245);//2
    glVertex2i(1230,245);
    glEnd();

    glColor3f(1.0,0.851,0.4); //Truck light

    glBegin(GL_QUADS);//2
    glVertex2i(1175,235);
    glVertex2i(1175,245);
    glVertex2i(1185,245);
    glVertex2i(1185,235);
    glEnd();
}

void drawcar1(){//Car 1
    glBegin(GL_POLYGON);//1 center
    glVertex2i(915,353);
    glVertex2i(915,378);
    glVertex2i(940,400);
    glVertex2i(1000,400);
    glVertex2i(1025,378);
    glVertex2i(1025,353);

    glBegin(GL_POLYGON);//1 front
    glVertex2i(1025,353);
    glVertex2i(1025,378);
    glVertex2i(1050,378);
    glVertex2i(1065,366);
    glVertex2i(1070,353);

    glBegin(GL_POLYGON);//1 back
    glVertex2i(900,353);
    glVertex2i(900,370);
    glVertex2i(905,378);
    glVertex2i(915,378);
    glVertex2i(915,353);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);//Car 1 wheels
    drawwheel(925.0,353.0,14.0);
    drawwheel(1027.0,353.0,14.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    drawwheel(925.0,353.0,7.0);
    drawwheel(1027.0,353.0,7.0);
    glEnd();

    glColor3f(0.0,0.0,0.0);//Car windows

    glBegin(GL_QUADS);//1
    glVertex2i(923,378);
    glVertex2i(942,395);
    glVertex2i(965,395);
    glVertex2i(965,378);

    glBegin(GL_QUADS);//1
    glVertex2i(975,378);
    glVertex2i(975,395);
    glVertex2i(998,395);
    glVertex2i(1017,378);
    glEnd();

    glColor3f(0.0,0.0,0.0); //Car ges
    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2i(970,398);//1
    glVertex2i(970,355);

    glVertex2i(975,375);//1
    glVertex2i(985,375);

    glVertex2i(923,375);//1
    glVertex2i(933,375);
    glEnd();

    glColor3f(1.0,0.0,0.0); //Car back light
    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2i(900,370);//1
    glVertex2i(905,378);
    glEnd();

    glColor3f(1.0,1.0,1.0);//Car front light

    glBegin(GL_TRIANGLES);//1
    glVertex2i(1050,378);
    glVertex2i(1055,370);
    glVertex2i(1065,366);
    glEnd();
}

void drawcar2(){//Car 2
    glBegin(GL_POLYGON);//2 center
    glVertex2i(715,258);
    glVertex2i(715,283);
    glVertex2i(740,305);
    glVertex2i(800,305);
    glVertex2i(825,283);
    glVertex2i(825,258);

    glBegin(GL_POLYGON);//2 front
    glVertex2i(670,258);
    glVertex2i(675,271);
    glVertex2i(690,283);
    glVertex2i(715,283);
    glVertex2i(715,258);

    glBegin(GL_POLYGON);//2 back
    glVertex2i(825,258);
    glVertex2i(825,283);
    glVertex2i(835,283);
    glVertex2i(840,275);
    glVertex2i(840,258);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);//Car 2 wheels
    drawwheel(815.0,258.0,14.0);
    drawwheel(713.0,258.0,14.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    drawwheel(815.0,258.0,7.0);
    drawwheel(713.0,258.0,7.0);
    glEnd();

    glColor3f(0.0,0.0,0.0);//Car windows

    glBegin(GL_QUADS);//2
    glVertex2i(723,283);
    glVertex2i(742,300);
    glVertex2i(765,300);
    glVertex2i(765,283);

    glBegin(GL_QUADS);//2
    glVertex2i(775,283);
    glVertex2i(775,300);
    glVertex2i(798,300);
    glVertex2i(817,283);
    glEnd();

    glColor3f(0.0,0.0,0.0); //Car ges
    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2i(770,303);//2
    glVertex2i(770,260);

    glVertex2i(755,280);//2
    glVertex2i(765,280);

    glVertex2i(805,280);//2
    glVertex2i(815,280);
    glEnd();

    glColor3f(1.0,0.0,0.0); //Car back light
    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2i(835,283);//2
    glVertex2i(840,275);
    glEnd();

    glColor3f(1.0,1.0,1.0);//Car front light

    glBegin(GL_TRIANGLES);//2
    glVertex2i(675,271);
    glVertex2i(685,275);
    glVertex2i(690,283);
    glEnd();
}

void drawplane(){//Plane
    glBegin(GL_POLYGON);
    glVertex2i(232,705);
    glVertex2i(445,705);
    glVertex2i(451,704);
    glVertex2i(452,703);
    glVertex2i(453,702);
    glVertex2i(456,700);
    glVertex2i(459,698);
    glVertex2i(462,696);
    glVertex2i(465,694);
    glVertex2i(468,692);
    glVertex2i(471,690);
    glVertex2i(474,688);
    glVertex2i(477,686);
    glVertex2i(480,684);
    glVertex2i(483,682);
    glVertex2i(486,680);
    glVertex2i(485,679);
    glVertex2i(484,678);
    glVertex2i(483,677);
    glVertex2i(482,676);
    glVertex2i(280,676);//
    glVertex2i(278,678);
    glVertex2i(276,680);
    glVertex2i(274,682);
    glVertex2i(272,684);
    glVertex2i(270,686);
    glVertex2i(268,688);
    glVertex2i(266,690);
    glVertex2i(264,691);
    glVertex2i(262,692);
    glVertex2i(260,693);
    glVertex2i(258,694);
    glVertex2i(256,695);
    glVertex2i(253,696);
    glVertex2i(250,697);
    glVertex2i(247,698);
    glVertex2i(246,699);
    glVertex2i(243,700);
    glVertex2i(240,701);
    glVertex2i(237,702);
    glVertex2i(234,703);
    glVertex2i(232,704);
    glVertex2i(232,705);
    glEnd();
}

void planewings(){//Plane wings
    glBegin(GL_QUADS);
    glVertex2i(370,685);
    glVertex2i(430,685);
    glVertex2i(360,655);
    glVertex2i(320,655);

    glVertex2i(355,705);
    glVertex2i(405,705);
    glVertex2i(360,725);
    glVertex2i(320,725);

    glVertex2i(232,705);
    glVertex2i(232,740);
    glVertex2i(240,740);
    glVertex2i(265,705);

    glVertex2i(240,702);
    glVertex2i(260,702);
    glVertex2i(235,687);
    glVertex2i(222,687);
    glEnd();

    glColor3f(0.66,0.8,0.84);//Plane front window

    glBegin(GL_QUADS);
    glVertex2i(443,699);
    glVertex2i(458,699);
    glVertex2i(471,690);
    glVertex2i(443,690);
    glEnd();

    glColor3f(0.66,0.8,0.84);
    glPointSize(8);
    glBegin(GL_POINTS);

    glVertex2i(300,692);
    glVertex2i(315,692);
    glVertex2i(330,692);
    glVertex2i(345,692);
    glVertex2i(360,692);
    glVertex2i(375,692);
    glVertex2i(390,692);
    glVertex2i(405,692);
    glVertex2i(420,692);
    glEnd();
}

void drawship(){//Ship
    glBegin(GL_QUADS);//body
    glVertex2i(520,110);
    glVertex2i(530,170);
    glVertex2i(875,170);
    glVertex2i(800,110);
    glEnd();

    glColor3f(0.584,0.584,0.584);

    glBegin(GL_QUADS);
    glVertex2i(560,170);
    glVertex2i(570,210);
    glVertex2i(820,210);
    glVertex2i(840,170);
    glEnd();

    glColor3f(0.74,0.74,0.74);
    glBegin(GL_QUADS);
    glVertex2i(620,210);
    glVertex2i(630,250);
    glVertex2i(800,250);
    glVertex2i(820,210);
    glEnd();

    glColor3f(1.0,1.0,1.0);//windows
    glBegin(GL_QUADS);
    glVertex2i(600,180);//lower 4
    glVertex2i(600,200);
    glVertex2i(620,200);
    glVertex2i(620,180);

    glVertex2i(660,180);
    glVertex2i(660,200);
    glVertex2i(680,200);
    glVertex2i(680,180);

    glVertex2i(720,180);
    glVertex2i(720,200);
    glVertex2i(740,200);
    glVertex2i(740,180);

    glVertex2i(780,180);
    glVertex2i(780,200);
    glVertex2i(800,200);
    glVertex2i(800,180);

    glVertex2i(650,220);//upper 3
    glVertex2i(650,240);
    glVertex2i(670,240);
    glVertex2i(670,220);

    glVertex2i(710,220);
    glVertex2i(710,240);
    glVertex2i(730,240);
    glVertex2i(730,220);

    glVertex2i(770,220);
    glVertex2i(770,240);
    glVertex2i(790,240);
    glVertex2i(790,220);
    glEnd();

    glColor3f(0.0,0.0,0.0); //ship black line
    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2i(530,180);
    glVertex2i(875,180);

    glVertex2i(530,170);
    glVertex2i(530,180);

    glVertex2i(599,170);
    glVertex2i(599,180);

    glVertex2i(668,170);
    glVertex2i(668,180);

    glVertex2i(737,170);
    glVertex2i(737,180);

    glVertex2i(806,170);
    glVertex2i(806,180);

    glVertex2i(875,170);
    glVertex2i(875,180);
    glEnd();
}

void drawstreetlight1(){//upper Street light
    //glColor3f(0.74,0.74,0.74);
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2i(1275,385);
    glVertex2i(1275,520);

    glVertex2i(900,385);
    glVertex2i(900,520);

    glVertex2i(500,385);
    glVertex2i(500,520);
    glEnd();

    glLineWidth(6.5);
    glBegin(GL_LINES);
    glVertex2i(1275,500);
    glVertex2i(1250,530);

    glVertex2i(900,500);
    glVertex2i(875,530);

    glVertex2i(500,500);
    glVertex2i(475,530);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2i(1229,528);
    glVertex2i(1249,528);

    glVertex2i(854,528);
    glVertex2i(874,528);

    glVertex2i(454,528);
    glVertex2i(474,528);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2i(1229,524);
    glVertex2i(1249,524);

    glVertex2i(854,524);
    glVertex2i(874,524);

    glVertex2i(454,524);
    glVertex2i(474,524);
    glEnd();
}

void drawstreetlight2(){//middle Street light
    //glColor3f(0.74,0.74,0.74);
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2i(300,280);
    glVertex2i(300,430);

    glVertex2i(700,280);
    glVertex2i(700,430);

    glVertex2i(1100,280);
    glVertex2i(1100,430);
    glEnd();

    glLineWidth(6.5);
    glBegin(GL_LINES);
    glVertex2i(300,410);
    glVertex2i(265,445);

    glVertex2i(300,410);
    glVertex2i(335,445);

    glVertex2i(700,410);
    glVertex2i(665,445);

    glVertex2i(700,410);
    glVertex2i(735,445);

    glVertex2i(1100,410);
    glVertex2i(1065,445);

    glVertex2i(1100,410);
    glVertex2i(1135,445);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2i(265,446);
    glVertex2i(245,446);

    glVertex2i(335,446);
    glVertex2i(355,446);

    glVertex2i(665,446);
    glVertex2i(645,446);

    glVertex2i(735,446);
    glVertex2i(755,446);

    glVertex2i(1065,446);
    glVertex2i(1045,446);

    glVertex2i(1135,446);
    glVertex2i(1155,446);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2i(265,442);
    glVertex2i(245,442);

    glVertex2i(335,442);
    glVertex2i(355,442);

    glVertex2i(665,442);
    glVertex2i(645,442);

    glVertex2i(735,442);
    glVertex2i(755,442);

    glVertex2i(1065,442);
    glVertex2i(1045,442);

    glVertex2i(1135,442);
    glVertex2i(1155,442);
    glEnd();
}

void drawstreetlight3(){//bottom Street light
    //glColor3f(0.74,0.74,0.74);
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2i(100,180);
    glVertex2i(100,315);

    glVertex2i(500,180);
    glVertex2i(500,315);

    glVertex2i(900,180);
    glVertex2i(900,315);

    glVertex2i(1300,180);
    glVertex2i(1300,315);
    glEnd();

    glLineWidth(6.5);
    glBegin(GL_LINES);
    glVertex2i(100,295);
    glVertex2i(125,325);

    glVertex2i(500,295);
    glVertex2i(525,325);

    glVertex2i(900,295);
    glVertex2i(925,325);

    glVertex2i(1300,295);
    glVertex2i(1325,325);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2i(124,323);
    glVertex2i(144,323);

    glVertex2i(524,323);
    glVertex2i(544,323);

    glVertex2i(924,323);
    glVertex2i(944,323);

    glVertex2i(1324,323);
    glVertex2i(1344,323);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2i(124,319);
    glVertex2i(144,319);

    glVertex2i(524,319);
    glVertex2i(544,319);

    glVertex2i(924,319);
    glVertex2i(944,319);

    glVertex2i(1324,319);
    glVertex2i(1344,319);
    glEnd();
}

void drawbush(){//Bush
    //glColor3f(0.0,0.6,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(25,435);
    glVertex2i(15,450);
    glVertex2i(27,445);
    glVertex2i(34,460);
    glVertex2i(44,446);
    glVertex2i(51,460);
    glVertex2i(58,445);
    glVertex2i(70,450);
    glVertex2i(60,435);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(881,445);
    glVertex2i(871,460);
    glVertex2i(883,455);
    glVertex2i(890,470);
    glVertex2i(900,456);
    glVertex2i(907,470);
    glVertex2i(915,455);
    glVertex2i(926,460);
    glVertex2i(916,445);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(521,415);
    glVertex2i(511,430);
    glVertex2i(523,425);
    glVertex2i(530,440);
    glVertex2i(540,426);
    glVertex2i(547,440);
    glVertex2i(554,425);
    glVertex2i(566,430);
    glVertex2i(556,415);
    glEnd();
}

void myDisplay(void){
    glClear (GL_COLOR_BUFFER_BIT);

    if(DayNight==0){ //for day time

        glPushMatrix();//Sky
        glColor3f(0.53,0.807,0.922);
        drawsky();
        glPopMatrix();

        glPushMatrix();// Sun
        glTranslatef(sun+30,sun-20,0.0);
        //glTranslatef(-sun-80,-sun+10,0.0);
        glColor3f(1.0f, 0.851f, 0.4f);
        circle(200.0, 685.0, 50.0);
        glPopMatrix();

        glPushMatrix();// Cloud 1
        glTranslatef(cloudPosition1,0,0);
        glColor3f(1.0, 1.0, 1.0);// white

        drawcloud(115.0, 680.0, 28.0);//1
        drawcloud(145.0, 695.0, 30.0);
        drawcloud(170.0, 695.0, 30.0);
        drawcloud(170.0, 665.0, 30.0);
        drawcloud(145.0, 665.0, 30.0);
        drawcloud(200.0, 680.0, 28.0);
        glPopMatrix();

        glPushMatrix();// Cloud 2
        glTranslatef(cloudPosition2,0,0);
        glColor3f(1.0, 1.0, 1.0);// white

        drawcloud(555.0, 640.0, 23.0);//2
        drawcloud(585.0, 653.0, 24.0);
        drawcloud(620.0, 653.0, 24.0);
        drawcloud(620.0, 622.0, 24.0);
        drawcloud(585.0, 622.0, 24.0);
        drawcloud(650.0, 640.0, 23.0);
        glPopMatrix();

        glPushMatrix();// Cloud 3
        glTranslatef(cloudPosition3,0,0);
        glColor3f(1.0, 1.0, 1.0);// white
        drawcloud(900.0, 680.0, 28.0);//3
        drawcloud(935.0, 695.0, 30.0);
        //drawcloud(960.0, 695.0, 30.0);
        //drawcloud(960.0, 665.0, 30.0);
        drawcloud(935.0, 665.0, 30.0);
        drawcloud(970.0, 680.0, 28.0);
        glPopMatrix();

        glPushMatrix();// Cloud 4
        glTranslatef(cloudPosition4,0,0);
        glColor3f(1.0, 1.0, 1.0);// white

        drawcloud(1255.0, 640.0, 23.0);//4
        drawcloud(1285.0, 653.0, 24.0);
        drawcloud(1320.0, 653.0, 24.0);
        drawcloud(1320.0, 622.0, 24.0);
        drawcloud(1285.0, 622.0, 24.0);
        drawcloud(1350.0, 640.0, 23.0);
        glPopMatrix();

        glPushMatrix();//Plane
        glTranslatef(plane,0.0,0.0);
        //glColor3f(0.737,0.737,0.737);
        glColor3f(0.93,0.93,0.93);
        drawplane();
        glColor3f(0.313,0.576,0.815);
        planewings();
        glPopMatrix();

        glPushMatrix();//Water
        glColor3f(0.058,0.368,0.612);//blue
        drawwater();
        glPopMatrix();

        glPushMatrix();//Roadside
        glColor3f(0.965,0.843,0.69);
        drawroadside();
        glPopMatrix();

        glPushMatrix();//Wooden bridge
        glColor3f(0.35,0.35,0.35);//Silver
        drawbridge();
        glPopMatrix();

        glPushMatrix();//Bridge railing
        glColor3f(0.902,0.568,0.219);
        drawbridgerailing();
        glPopMatrix();

        glPushMatrix();//Road
        drawroad();
        glPopMatrix();

        glPushMatrix();//grass
        glColor3f(0.317,1.0,0.317);
        drawgrass();
        glPopMatrix();

        glPushMatrix();//white in mid road
        drawwhitemid();
        glPopMatrix();

        glPushMatrix();//Building 1
        glColor3f(0.807,0.494,0.0);
        drawbuilding1();
        glPopMatrix();

        glPushMatrix();//Building 2
        glColor3f(0.153,0.0,0.698);
        drawbuilding2();
        glColor3f(1.0,0.0,0.0);
        drawb2frontwall();
        drawb2bulb();
        glColor3f(1.0,1.0,1.0);
        circle(1248.5,453.0,12.0);
        circle(976.5,453.0,12.0);
        circle(1286.5,477.0,12.0);
        circle(1025.5,477.0,12.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();//Building 3 (Hospital)
        glColor3f(0.435,0.658,0.863);
        drawbuilding3();
        Sprint(705,490,text);
        glPopMatrix();

        glPushMatrix();//Building 4
        glColor3f(0.6,0.0,0.0);
        drawbuilding4();
        glPopMatrix();

        glPushMatrix();//Tree
        glColor3f(0.769,0.392,0.0);
        drawtree();
        glPopMatrix();

        glPushMatrix();//Leaf
        glColor3f(0.16,0.49,0.1);
        drawleaf();
        glPopMatrix();

        glPushMatrix();//Bush
        glColor3f(0.0,0.6,0.0);
        drawbush();
        glPopMatrix();

        glPushMatrix();//Street light upper
        glColor3f(0.74,0.74,0.74);
        drawstreetlight1();
        glPopMatrix();

        glPushMatrix();//Roadside border upper
        glColor3f(0.0,0.0,0.0);//black
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2i(255,370);
        glVertex2i(255,395);

        glVertex2i(150,370);
        glVertex2i(150,395);

        glVertex2i(50,370);
        glVertex2i(50,395);

        glVertex2i(365,370);
        glVertex2i(365,395);

        glVertex2i(465,370);
        glVertex2i(465,395);

        glVertex2i(565,370);
        glVertex2i(565,395);

        glVertex2i(665,370);
        glVertex2i(665,395);

        glVertex2i(565,370);
        glVertex2i(565,395);

        glVertex2i(760,370);
        glVertex2i(760,395);

        glVertex2i(860,370);
        glVertex2i(860,395);

        glVertex2i(960,370);
        glVertex2i(960,395);

        glVertex2i(1055,370);
        glVertex2i(1055,395);

        glVertex2i(1135,370);
        glVertex2i(1135,395);

        glVertex2i(1235,370);
        glVertex2i(1235,395);

        glVertex2i(1335,370);
        glVertex2i(1335,395);

        glVertex2i(1415,370);
        glVertex2i(1415,395);
        glEnd();

        glColor3f(0.6,0.6,0.6);//silver
        glLineWidth(4);
        glBegin(GL_LINES);
        glVertex2i(0,395);
        glVertex2i(260,395);

        glVertex2i(0,388);
        glVertex2i(260,388);

        glVertex2i(360,395);
        glVertex2i(675,395);

        glVertex2i(360,388);
        glVertex2i(675,388);

        glVertex2i(755,395);
        glVertex2i(1060,395);

        glVertex2i(755,388);
        glVertex2i(1060,388);

        glVertex2i(1130,395);
        glVertex2i(1340,395);

        glVertex2i(1130,388);
        glVertex2i(1340,388);

        glVertex2i(1410,395);
        glVertex2i(1500,395);

        glVertex2i(1410,388);
        glVertex2i(1500,388);
        glEnd();
        glPopMatrix();

        glPushMatrix();//Ambulance
        glTranslatef(ambulance,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        drawambulance();
        glPopMatrix();

        glPushMatrix();//Car 1
        glTranslatef(car1,0.0,0.0);
        glColor3f(0.435,0.658,0.863);
        drawcar1();
        glPopMatrix();

        glPushMatrix();//Truck 1
        glTranslatef(truck1,0.0,0.0);
        glColor3f(0.902,0.568,0.219);
        drawtruck1();
        truck1ges();
        glPopMatrix();

        glPushMatrix();//Street light middle
        glColor3f(0.74,0.74,0.74);
        drawstreetlight2();
        glPopMatrix();

        glPushMatrix();//Roadside border mid
        glColor3f(0.0,0.0,0.0);//black
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2i(50,280);
        glVertex2i(50,300);

        glVertex2i(150,280);
        glVertex2i(150,300);

        glVertex2i(250,280);
        glVertex2i(250,300);

        glVertex2i(350,280);
        glVertex2i(350,300);

        glVertex2i(450,280);
        glVertex2i(450,300);

        glVertex2i(550,280);
        glVertex2i(550,300);

        glVertex2i(650,280);
        glVertex2i(650,300);

        glVertex2i(750,280);
        glVertex2i(750,300);

        glVertex2i(850,280);
        glVertex2i(850,300);

        glVertex2i(950,280);
        glVertex2i(950,300);

        glVertex2i(1050,280);
        glVertex2i(1050,300);

        glVertex2i(1150,280);
        glVertex2i(1150,300);

        glVertex2i(1250,280);
        glVertex2i(1250,300);

        glVertex2i(1350,280);
        glVertex2i(1350,300);

        glVertex2i(1450,280);
        glVertex2i(1450,300);
        glEnd();

        glColor3f(0.6,0.6,0.6);//silver
        glLineWidth(4);
        glBegin(GL_LINES);
        glVertex2i(0,300);
        glVertex2i(1500,300);

        glVertex2i(0,293);
        glVertex2i(1500,293);
        glEnd();
        glPopMatrix();

        glPushMatrix();//Car 2
        glTranslatef(-car1,0.0,0.0);
        glColor3f(0.522,0.439,0.768);
        drawcar2();
        glPopMatrix();

        glPushMatrix();//Truck 2
        glTranslatef(-truck1,0.0,0.0);
        glColor3f(0.416,0.658,0.309);
        drawtruck2();
        truck2ges();
        glPopMatrix();

        glPushMatrix();//Roadside border bottom
        glColor3f(0.0,0.0,0.0);//black
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2i(50,185);
        glVertex2i(50,212);

        glVertex2i(150,185);
        glVertex2i(150,212);

        glVertex2i(250,185);
        glVertex2i(250,212);

        glVertex2i(350,185);
        glVertex2i(350,212);

        glVertex2i(450,185);
        glVertex2i(450,212);

        glVertex2i(550,185);
        glVertex2i(550,212);

        glVertex2i(650,185);
        glVertex2i(650,212);

        glVertex2i(750,185);
        glVertex2i(750,212);

        glVertex2i(850,185);
        glVertex2i(850,212);

        glVertex2i(950,185);
        glVertex2i(950,212);

        glVertex2i(1050,185);
        glVertex2i(1050,212);

        glVertex2i(1150,185);
        glVertex2i(1150,212);

        glVertex2i(1250,185);
        glVertex2i(1250,212);

        glVertex2i(1350,185);
        glVertex2i(1350,212);

        glVertex2i(1450,185);
        glVertex2i(1450,212);
        glEnd();

        glColor3f(0.6,0.6,0.6);//silver
        glLineWidth(4);
        glBegin(GL_LINES);
        glVertex2i(0,212);
        glVertex2i(260,212);

        glVertex2i(340,212);
        glVertex2i(1500,212);

        glVertex2i(0,205);
        glVertex2i(260,205);

        glVertex2i(340,205);
        glVertex2i(1500,205);
        glEnd();
        glPopMatrix();

        glPushMatrix();//Street light bottom
        glColor3f(0.74,0.74,0.74);
        drawstreetlight3();
        glPopMatrix();

        glPushMatrix();//Private Ship
        glTranslatef(ship,0.0,0.0);
        glColor3f(1.0,1.0,1.0);
        drawship();
        glPopMatrix();
        glutSwapBuffers();
    }
    else{
        glPushMatrix();//Sky
        glColor3f(0.0,0.0,0.2);
        drawsky();
        glPopMatrix();

        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glPointSize(3);
        glBegin(GL_POINTS);
        glVertex2i(25,600);
        glVertex2i(50,700);
        glVertex2i(250,640);
        glVertex2i(430,725);
        glVertex2i(500,650);
        glVertex2i(750,700);
        glVertex2i(800,600);
        glVertex2i(1150,680);
        glVertex2i(1450,650);
        glVertex2i(600,720);
        glVertex2i(1000,610);
        glVertex2i(1050,710);
        glEnd();
        glPopMatrix();

        glPushMatrix();//Moon
        glTranslatef(moon+30,moon-20,0.0);
        glColor3f(0.855, 0.851, 0.843);//light silver
        circle(200.0, 685.0, 50.0);
        glPopMatrix();

        glPushMatrix();// Cloud 1
        glColor3f(0.529,0.533,0.612);// silver
        glTranslatef(cloudPosition1,0,0);
        drawcloud(115.0, 680.0, 28.0);//1
        drawcloud(145.0, 695.0, 30.0);
        drawcloud(170.0, 695.0, 30.0);
        drawcloud(170.0, 665.0, 30.0);
        drawcloud(145.0, 665.0, 30.0);
        drawcloud(200.0, 680.0, 28.0);
        glPopMatrix();

        glPushMatrix();// Cloud 2
        glTranslatef(cloudPosition2,0,0);
        drawcloud(555.0, 640.0, 23.0);//2
        drawcloud(585.0, 653.0, 24.0);
        drawcloud(620.0, 653.0, 24.0);
        drawcloud(620.0, 622.0, 24.0);
        drawcloud(585.0, 622.0, 24.0);
        drawcloud(650.0, 640.0, 23.0);
        glPopMatrix();

        glPushMatrix();// Cloud 3
        glTranslatef(cloudPosition3,0,0);
        drawcloud(900.0, 680.0, 28.0);//3
        drawcloud(935.0, 695.0, 30.0);
        drawcloud(935.0, 665.0, 30.0);
        drawcloud(970.0, 680.0, 28.0);
        glPopMatrix();

        glPushMatrix();// Cloud 4
        glTranslatef(cloudPosition4,0,0);
        drawcloud(1255.0, 640.0, 23.0);//4
        drawcloud(1285.0, 653.0, 24.0);
        drawcloud(1320.0, 653.0, 24.0);
        drawcloud(1320.0, 622.0, 24.0);
        drawcloud(1285.0, 622.0, 24.0);
        drawcloud(1350.0, 640.0, 23.0);
        glPopMatrix();

        glPushMatrix();//Plane
        //glColor3f(0.9,0.9,0.9);

        glTranslatef(plane,0.0,0.0);
        glColor3f(0.737,0.737,0.737);
        drawplane();
        glColor3f(0.043,0.325,0.58);
        planewings();
        glPopMatrix();

        glPushMatrix();//Water
        glColor3f(0.0, 0.0, 0.4);// Dark blue
        drawwater();
        glPopMatrix();

        glPushMatrix();//Roadside
        glColor3f(0.72,0.63,0.38);
        drawroadside();
        glPopMatrix();

        glPushMatrix();//Wooden bridge
        glColor3f(0.267,0.267,0.267);//Silver
        drawbridge();
        glPopMatrix();

        glPushMatrix();//Bridge railing
        glColor3f(0.7,0.37,0.024);
        drawbridgerailing();
        glPopMatrix();

        glPushMatrix();//Road
        drawroad();
        glPopMatrix();

        glPushMatrix();//grass
        glColor3f(0.0, 0.25, 0.0);// night green
        drawgrass();
        glPopMatrix();

        glPushMatrix();//white in mid road
        drawwhitemid();
        glPopMatrix();

        glPushMatrix();//Building 1
        glColor3f(0.592,0.36,0.0);
        drawbuilding1();
        glColor3f(1.0,1.0,0.0);//yellow light in night mode
        glBegin(GL_QUADS);
        glVertex2i(1325,540);//left 3
        glVertex2i(1325,565);
        glVertex2i(1350,565);
        glVertex2i(1350,540);

        glVertex2i(1400,495);//right 2
        glVertex2i(1400,520);
        glVertex2i(1425,520);
        glVertex2i(1425,495);

        glVertex2i(1325,450);//left 1
        glVertex2i(1325,475);
        glVertex2i(1350,475);
        glVertex2i(1350,450);

        glVertex2i(1400,450);//right 1
        glVertex2i(1400,475);
        glVertex2i(1425,475);
        glVertex2i(1425,450);
        glEnd();

        glColor3f(0.0,0.0,0.0);//black light in night mode
        glBegin(GL_QUADS);
        glVertex2i(1400,540);//right 3
        glVertex2i(1400,565);
        glVertex2i(1425,565);
        glVertex2i(1425,540);

        glVertex2i(1325,495);//left 2
        glVertex2i(1325,520);
        glVertex2i(1350,520);
        glVertex2i(1350,495);
        glEnd();
        glPopMatrix();

        glPushMatrix();//Building 2
        glColor3f(0.078,0.0,0.353);
        drawbuilding2();
        glColor3f(0.678,0.0,0.0);
        drawb2frontwall();
        glColor3f(1.0,1.0,0.0);//yellow light in night mode
        glBegin(GL_QUADS);
        glVertex2i(1075,560);
        glVertex2i(1075,585);
        glVertex2i(1100,585);
        glVertex2i(1100,560);

        glVertex2i(1075,515);
        glVertex2i(1075,540);
        glVertex2i(1100,540);
        glVertex2i(1100,515);

        glVertex2i(1075,470);
        glVertex2i(1075,495);
        glVertex2i(1100,495);
        glVertex2i(1100,470);

        glVertex2i(1150,560);//right
        glVertex2i(1150,585);
        glVertex2i(1175,585);
        glVertex2i(1175,560);

        glVertex2i(1150,515);
        glVertex2i(1150,540);
        glVertex2i(1175,540);
        glVertex2i(1175,515);

        glVertex2i(1150,470);
        glVertex2i(1150,495);
        glVertex2i(1175,495);
        glVertex2i(1175,470);
        glEnd();
        drawb2bulb();
        glColor3f(1.0,1.0,0.0);
        circle(1248.5,453.0,12.0);
        circle(976.5,453.0,12.0);
        circle(1286.5,477.0,12.0);
        circle(1025.5,477.0,12.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();//Building 3 (Hospital)
        glColor3f(0.051,0.267,0.458);
        drawbuilding3();
        Sprint(705,490,text);
        glPopMatrix();

        glPushMatrix();//Building 4
        glColor3f(0.4,0.0,0.0);
        drawbuilding4();
        glColor3f(1.0,1.0,0.0);//yellow light in night mode
        glBegin(GL_QUADS);
        glVertex2i(205,520);//left
        glVertex2i(205,560);
        glVertex2i(245,560);
        glVertex2i(245,520);

        glVertex2i(205,450);
        glVertex2i(205,490);
        glVertex2i(245,490);
        glVertex2i(245,450);

        glVertex2i(375,450);//right
        glVertex2i(375,490);
        glVertex2i(415,490);
        glVertex2i(415,450);

        glVertex2i(290,460);//stair window
        glVertex2i(290,570);
        glVertex2i(330,570);
        glVertex2i(330,460);
        glEnd();

        glColor3f(0.0,0.0,0.0);//black light in night mode
        glBegin(GL_QUADS);
        glVertex2i(375,520);//right
        glVertex2i(375,560);
        glVertex2i(415,560);
        glVertex2i(415,520);
        glEnd();
        glPopMatrix();

        glPushMatrix();//Tree
        glColor3f(0.34,0.17,0.0);
        drawtree();
        glPopMatrix();

        glPushMatrix();//Leaf
        glColor3f(0.0,0.15,0.0);
        drawleaf();
        glPopMatrix();

        glPushMatrix();//Bush
        glColor3f(0.0,0.2,0.0);
        drawbush();
        glPopMatrix();

        glPushMatrix();//Street light upper
        glColor3f(0.267,0.267,0.267);
        drawstreetlight1();
        glColor3f(1.0,1.0,0.0);//Yellowish light
        glLineWidth(4);
        glBegin(GL_LINES);
        glVertex2i(1229,524);
        glVertex2i(1249,524);

        glVertex2i(854,524);
        glVertex2i(874,524);

        glVertex2i(454,524);
        glVertex2i(474,524);
        glPopMatrix();

        glPushMatrix();//Roadside border upper
        glColor3f(0.0,0.0,0.0);//black
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2i(255,370);
        glVertex2i(255,395);

        glVertex2i(150,370);
        glVertex2i(150,395);

        glVertex2i(50,370);
        glVertex2i(50,395);

        glVertex2i(365,370);
        glVertex2i(365,395);

        glVertex2i(465,370);
        glVertex2i(465,395);

        glVertex2i(565,370);
        glVertex2i(565,395);

        glVertex2i(665,370);
        glVertex2i(665,395);

        glVertex2i(565,370);
        glVertex2i(565,395);

        glVertex2i(760,370);
        glVertex2i(760,395);

        glVertex2i(860,370);
        glVertex2i(860,395);

        glVertex2i(960,370);
        glVertex2i(960,395);

        glVertex2i(1055,370);
        glVertex2i(1055,395);

        glVertex2i(1135,370);
        glVertex2i(1135,395);

        glVertex2i(1235,370);
        glVertex2i(1235,395);

        glVertex2i(1335,370);
        glVertex2i(1335,395);

        glVertex2i(1415,370);
        glVertex2i(1415,395);
        glEnd();

        glColor3f(0.6,0.6,0.6);//silver
        glLineWidth(4);
        glBegin(GL_LINES);
        glVertex2i(0,395);
        glVertex2i(260,395);

        glVertex2i(0,388);
        glVertex2i(260,388);

        glVertex2i(360,395);
        glVertex2i(675,395);

        glVertex2i(360,388);
        glVertex2i(675,388);

        glVertex2i(755,395);
        glVertex2i(1060,395);

        glVertex2i(755,388);
        glVertex2i(1060,388);

        glVertex2i(1130,395);
        glVertex2i(1340,395);

        glVertex2i(1130,388);
        glVertex2i(1340,388);

        glVertex2i(1410,395);
        glVertex2i(1500,395);

        glVertex2i(1410,388);
        glVertex2i(1500,388);
        glEnd();
        glPopMatrix();

        glPushMatrix();//Ambulance
        glTranslatef(ambulance,0.0,0.0);
        glColor3f(0.85,0.85,0.85);
        drawambulance();
        glColor3f(1.0,0.95,0.8);//Night light
        glBegin(GL_QUADS);
        glVertex2i(685,385);
        glVertex2i(685,395);
        glVertex2i(810,360);
        glVertex2i(730,360);
        glEnd();
        glPopMatrix();

        glPushMatrix();//Car 1
        glTranslatef(car1,0.0,0.0);
        glColor3f(0.04,0.33,0.58);
        drawcar1();
        glColor3f(1.0,0.95,0.8);
        glBegin(GL_QUADS);
        glVertex2i(1065,366);
        glVertex2i(1050,378);
        glVertex2i(1190,350);
        glVertex2i(1110,350);
        glEnd();
        glPopMatrix();

        glPushMatrix();//Truck 1
        glTranslatef(truck1,0.0,0.0);
        glColor3f(0.706,0.373,0.023);
        drawtruck1();
        glColor3f(1.0,0.95,0.8);
        glBegin(GL_QUADS);
        glVertex2i(485,330);
        glVertex2i(485,340);
        glVertex2i(610,300);
        glVertex2i(530,300);
        glEnd();
        truck1ges();
        glPopMatrix();

        glPushMatrix();//Street light middle
        glColor3f(0.267,0.267,0.267);
        drawstreetlight2();
        glColor3f(1.0,1.0,0.0);//Yellowish light
        glLineWidth(4);
        glBegin(GL_LINES);
        glVertex2i(265,442);
        glVertex2i(245,442);

        glVertex2i(335,442);
        glVertex2i(355,442);

        glVertex2i(665,442);
        glVertex2i(645,442);

        glVertex2i(735,442);
        glVertex2i(755,442);

        glVertex2i(1065,442);
        glVertex2i(1045,442);

        glVertex2i(1135,442);
        glVertex2i(1155,442);
        glPopMatrix();

        glPushMatrix();//Roadside border mid
        glColor3f(0.0,0.0,0.0);//black
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2i(50,280);
        glVertex2i(50,300);

        glVertex2i(150,280);
        glVertex2i(150,300);

        glVertex2i(250,280);
        glVertex2i(250,300);

        glVertex2i(350,280);
        glVertex2i(350,300);

        glVertex2i(450,280);
        glVertex2i(450,300);

        glVertex2i(550,280);
        glVertex2i(550,300);

        glVertex2i(650,280);
        glVertex2i(650,300);

        glVertex2i(750,280);
        glVertex2i(750,300);

        glVertex2i(850,280);
        glVertex2i(850,300);

        glVertex2i(950,280);
        glVertex2i(950,300);

        glVertex2i(1050,280);
        glVertex2i(1050,300);

        glVertex2i(1150,280);
        glVertex2i(1150,300);

        glVertex2i(1250,280);
        glVertex2i(1250,300);

        glVertex2i(1350,280);
        glVertex2i(1350,300);

        glVertex2i(1450,280);
        glVertex2i(1450,300);
        glEnd();

        glColor3f(0.6,0.6,0.6);//silver
        glLineWidth(4);
        glBegin(GL_LINES);
        glVertex2i(0,300);
        glVertex2i(1500,300);

        glVertex2i(0,293);
        glVertex2i(1500,293);
        glEnd();
        glPopMatrix();

        glPushMatrix();//Car 2
        glTranslatef(-car1,0.0,0.0);
        glColor3f(0.24,0.15,0.47);
        drawcar2();
        glColor3f(1.0,0.95,0.8);
        glBegin(GL_QUADS);
        glVertex2i(675,271);
        glVertex2i(690,283);
        glVertex2i(550,255);
        glVertex2i(630,255);
        glEnd();
        glPopMatrix();

        glPushMatrix();//Truck 2
        glTranslatef(-truck1,0.0,0.0);
        glColor3f(0.219,0.463,0.114);
        drawtruck2();
        glColor3f(1.0,0.95,0.8);
        glBegin(GL_QUADS);
        glVertex2i(1175,235);
        glVertex2i(1175,245);
        glVertex2i(1050,210);
        glVertex2i(1130,210);
        glEnd();
        truck2ges();
        glPopMatrix();

        glPushMatrix();//Roadside border bottom
        glColor3f(0.0,0.0,0.0);//black
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2i(50,185);
        glVertex2i(50,212);

        glVertex2i(150,185);
        glVertex2i(150,212);

        glVertex2i(250,185);
        glVertex2i(250,212);

        glVertex2i(350,185);
        glVertex2i(350,212);

        glVertex2i(450,185);
        glVertex2i(450,212);

        glVertex2i(550,185);
        glVertex2i(550,212);

        glVertex2i(650,185);
        glVertex2i(650,212);

        glVertex2i(750,185);
        glVertex2i(750,212);

        glVertex2i(850,185);
        glVertex2i(850,212);

        glVertex2i(950,185);
        glVertex2i(950,212);

        glVertex2i(1050,185);
        glVertex2i(1050,212);

        glVertex2i(1150,185);
        glVertex2i(1150,212);

        glVertex2i(1250,185);
        glVertex2i(1250,212);

        glVertex2i(1350,185);
        glVertex2i(1350,212);

        glVertex2i(1450,185);
        glVertex2i(1450,212);
        glEnd();

        glColor3f(0.6,0.6,0.6);//silver
        glLineWidth(4);
        glBegin(GL_LINES);
        glVertex2i(0,212);
        glVertex2i(260,212);

        glVertex2i(340,212);
        glVertex2i(1500,212);

        glVertex2i(0,205);
        glVertex2i(260,205);

        glVertex2i(340,205);
        glVertex2i(1500,205);
        glEnd();
        glPopMatrix();

        glPushMatrix();//Street light bottom
        glColor3f(0.267,0.267,0.267);
        drawstreetlight3();
        glColor3f(1.0,1.0,0.0);//Yellowish light
        glLineWidth(4);
        glBegin(GL_LINES);
        glVertex2i(124,319);
        glVertex2i(144,319);

        glVertex2i(524,319);
        glVertex2i(544,319);

        glVertex2i(924,319);
        glVertex2i(944,319);

        glVertex2i(1324,319);
        glVertex2i(1344,319);
        glEnd();
        glPopMatrix();

        glPushMatrix();//Private Ship
        //glTranslatef(ship,0.0,0.0);
        glColor3f(0.73,0.73,0.73);
        drawship();
        glColor3f(0.0,0.0,0.0);//windows
        glBegin(GL_QUADS);
        glVertex2i(600,180);//lower 4
        glVertex2i(600,200);
        glVertex2i(620,200);
        glVertex2i(620,180);

        glVertex2i(660,180);
        glVertex2i(660,200);
        glVertex2i(680,200);
        glVertex2i(680,180);

        glVertex2i(720,180);
        glVertex2i(720,200);
        glVertex2i(740,200);
        glVertex2i(740,180);

        glVertex2i(780,180);
        glVertex2i(780,200);
        glVertex2i(800,200);
        glVertex2i(800,180);

        glVertex2i(650,220);//upper 3
        glVertex2i(650,240);
        glVertex2i(670,240);
        glVertex2i(670,220);

        glVertex2i(710,220);
        glVertex2i(710,240);
        glVertex2i(730,240);
        glVertex2i(730,220);

        glVertex2i(770,220);
        glVertex2i(770,240);
        glVertex2i(790,240);
        glVertex2i(790,220);
        glEnd();
        glPopMatrix();
        glutSwapBuffers();
    }
}

//Cloud Animation
void update1(int value){// Update cloud position
    cloudPosition1 += 1.5f; // Adjust speed as needed

    if (cloudPosition1 > 1400.0f){
        cloudPosition1 = -1700.0f; // Wrap to the left side
    }

    if (cloudPosition1 < -1450.0f){
        cloudPosition1 = -300.0f; // Wrap to the right side
    }

    glutPostRedisplay(); // Notify GLUT that the display has changed
    glutTimerFunc(25, update1, 0); // Notify GLUT to call update again in 25 milliseconds
    glutSwapBuffers();
}

void update2(int value){// Update cloud position
    cloudPosition2 += 1.5f;// Adjust speed as needed

    if (cloudPosition2 > 1050.0f){
        cloudPosition2 = -1700.0f; // Wrap to the left side
    }

    if (cloudPosition2 < -1450.0f){
        cloudPosition2 = -650.0f; // Wrap to the right side
    }

    glutPostRedisplay(); // Notify GLUT that the display has changed
    glutTimerFunc(25, update2, 0); // Notify GLUT to call update again in 25 milliseconds
    glutSwapBuffers();
}

void update3(int value){// Update cloud position
    cloudPosition3 += 1.5f; // Adjust speed as needed

    if (cloudPosition3 > 700.0f){
        cloudPosition3 = -1700.0f; // Wrap to the left side
    }

    if (cloudPosition3 < -1450.0f){
        cloudPosition3 = -1000.0f; // Wrap to the right side
    }

    glutPostRedisplay(); // Notify GLUT that the display has changed
    glutTimerFunc(25, update3, 0); // Notify GLUT to call update again in 25 milliseconds
    glutSwapBuffers();
}

void update4(int value){// Update cloud position
    cloudPosition4 += 1.5f;// Adjust speed as needed

    if (cloudPosition4 > 350.0f){
        cloudPosition4 = -1700.0f; // Wrap to the left side
    }

    if (cloudPosition4 < -1450.0f){
        cloudPosition4 = -1350.0f; // Wrap to the right side
    }

    glutPostRedisplay(); // Notify GLUT that the display has changed
    glutTimerFunc(25, update4, 0); // Notify GLUT to call update again in 25 milliseconds
    glutSwapBuffers();
}
float sunspeed=0.5f;
float moonspeed=0.5f;

void moonAnimation(int value){//Moon Animation
    moon += 0.5f;
    if(moon>150.0f){
        moon = -270.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(25, moonAnimation, 0);
    glutSwapBuffers();
}

void sunAnimation(int value){//Sun Animation
    sun += 0.5f;
    if(sun>150.0f){
        sun = -270.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(25, sunAnimation, 0);
    glutSwapBuffers();
}

void ambulanceAnimation(int value){//Ambulance Animation
    ambulance += speed1;
    if(ambulance>960.0f){
        ambulance = -1200.0f;
    }
    /*if(ambulance<-1210.0f){
        ambulance=+950.0f;
    }*/
    glutPostRedisplay();
    glutTimerFunc(25, ambulanceAnimation, 0);
    glutSwapBuffers();
}

void carAnimation(int value){//Car Animation
    car1 += 3.0f;
    if(car1>860.0f){
        car1 = -1200.0f;
    }
    /*if(car1<-1210.0f){
        car1=+850.0f;
    }*/
    glutPostRedisplay();
    glutTimerFunc(25, carAnimation, 0);
    glutSwapBuffers();
}

void truckAnimation(int value){//Truck Animation
    truck1 += 5.0f;
    if(truck1>1400.0f){
        truck1 = -1120.0f;
    }
    /*if(truck1<-1130.0f){
        truck1=+1350.0f;
    }*/
    glutPostRedisplay();
    glutTimerFunc(25, truckAnimation, 0);
    glutSwapBuffers();
}

void shipAnimation(int value){//Ship Animation
    ship += speed2;
    if(ship>1400.0f){
        ship = -1120.0f;
    }
    /*if(ship<-1130.0f){
        ship=+1350.0f;
    }*/
    glutPostRedisplay();
    glutTimerFunc(25, shipAnimation, 0);
    glutSwapBuffers();
}

void planeAnimation(int value){//Plane Animation
    plane += speed;
    if(plane>1400.0f){
        plane = -1050.0f;
    }
    /*if(plane<-1130.0f){
        plane=+1350.0f;
    }*/
    glutPostRedisplay();
    glutTimerFunc(25, planeAnimation, 0);
    glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            speed+=0.05f;
            planeAnimation(0);
            //shipAnimation(0);
            break;
        case GLUT_KEY_DOWN:
            speed-=0.05f;
            planeAnimation(0);
            break;
    }
}

void handleKeypress(unsigned char key, int x, int y) {
    switch(key){
    case 100: //d  Switch to day mode
        DayNight=0;
        break;
    case 110: //n  Switch to night mode
        DayNight=1;
        break;
    case 114: //r  Ship speed increase
        speed2+=0.05f;
        shipAnimation(0);
        break;
    case 102: //f  Ship speed decrease
        speed2-=0.05f;
        shipAnimation(0);
        break;
    case 119: //w  Ambulance speed increase
        speed1+=0.05f;
        ambulanceAnimation(0);
        break;
    case 115: //s  Ambulance speed decrease
        speed1-=0.05f;
        ambulanceAnimation(0);
        break;
    }
    /*if (key == 'd') {
        DayNight = 0;  // Switch to day mode
    }
    else if (key == 'n') {
        DayNight = 1;  // Switch to night mode
    }
    else if(key=='r'){//Ship moving
        speed2+=0.05f;
        shipAnimation(0);
    }
    else if(key=='f'){//Ship moving
        speed2-=0.05f;
        shipAnimation(0);
    }
    else if(key=='q'){//Ambulance can only move at day
        if(DayNight==0){
        speed1+=0.05f;
        ambulanceAnimation(0);}
    }
    else if(key=='a'){//Ambulance can only move at day
        if(DayNight==0){
        speed1-=0.05f;
        ambulanceAnimation(0);}
    }
    else if(key == 'w'){//Ambulance moving
        //if(DayNight==1){
        speed1+=0.05f;
        ambulanceAnimation(0);
    }
    else if(key == 's'){//Ambulance moving
        //if(DayNight==1){
        speed1-=0.05f;
        ambulanceAnimation(0);
    }*/
    glutPostRedisplay();  // updated mode
    glutSwapBuffers();
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
    glutCreateWindow ("City View Project");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(25,update1,0);//Cloud 1
    glutTimerFunc(25,update2,0);//Cloud 2
    glutTimerFunc(25,update3,0);//Cloud 3
    glutTimerFunc(25,update4,0);//Cloud 4
    glutTimerFunc(25,ambulanceAnimation,0);//Ambulance
    glutTimerFunc(25,planeAnimation,0);//Plane
    glutTimerFunc(25,carAnimation,0);//Car
    glutTimerFunc(25,truckAnimation,0);//Truck
    glutTimerFunc(25,shipAnimation,0);//Ship
    glutTimerFunc(25,sunAnimation,0);//Sun
    glutTimerFunc(25,moonAnimation,0);//Moon
    glutSpecialFunc(specialKeys);
    myInit ();
    glutMainLoop();
}
