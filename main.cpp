#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>
#include <string>



int physWidth = 800, physHeight= 800;
int logWidth = 100, logHeight = 100;
double red[8]={0},green[8]{0},blue[8]={0};
double temp_red[8]={0},temp_green[8]={0},temp_blue[8]={0};
int centerX = logWidth/2, centerY = logHeight/2;
int mouseX=-1,mouseY=-1;
int sqWid=4;
int cx1=97,cy1=95,cx2=92,cy2=95,cx3=87,cy3=95,cx4=82,cy4=95,cx5=77,cy5=95,cx6=72,cy6=95,cx7=67,cy7=95,cx8=62,cy8=95;
int status;
double drawX=-1,drawY=-1;
int rect[10000][5];
int line[10000][5];
double point_x[1000][10000]={0};
double point_y[1000][10000]={0};
int point_color[10000];
int point_width[10000]={0};
double circle[10000][4];
int k=0;
int draw=0;
double text[1000][3];
char text_str[1000][100];
int button_width=10,button_height=4;
int bx1=7,by1=97,bx2=7,by2=90,bx3=20,by3=97,bx4=20,by4=90,bx5=33,by5=97,bx6=33,by6=90,bx7=46,by7=97,bx8=46,by8=90;
int filled=0;
int universal[1000]={0};
double passive_x=0,passive_y=0;







char str[100]="";
char Newstr[2]={0,0};
int a=50,b=50;
void set_color(int status){
if(status==1)
glColor3f(0.0f, 0.0f,0.0f);
else if(status==2)
glColor3f(1.0f, 1.0f, 1.0f);
else if(status==3)
glColor3f(0.8f, 0.0f, 0.6f);
else if(status==4)
glColor3f(1.0f, 0.7f, 0.0f);
else if(status==5)
glColor3f(1.0f, 1.0f, 0.0f);
else if(status==6)
glColor3f(0.0f, 0.0f, 1.0f);
else if(status==7)
glColor3f(0.0f, 1.0f, 0.0f);
else if(status==8)
glColor3f(1.0f, 0.0f, 0.0f);
}


double calculate_distance(int x1,int y1,int x2,int y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));


}
void drawpoint(double x,double y,int status){
set_color(status);

glBegin(GL_POINTS);

glVertex2d(x,y);


glEnd();

}
void drawline(int x1,int y1,int x2,int y2,int status){
set_color(status);

glBegin(GL_LINES);
glVertex2i(x1,y1);
glVertex2i(x2,y2);
glEnd();
}
void printsome(char *str, int x, int y,int status)
{
set_color(status);

 glRasterPos2d(x,y);
 for(int i=0;i<strlen(str);i++)
 {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);
    glFlush();
 }
}
void drawSquares(){
  glColor3f(1.0f, 1.0f, 1.0f); //
  glBegin(GL_POLYGON);
   glVertex2f(0,85); // x, y
   glVertex2f(100,85); // x, y
   glVertex2f(100,100); // x, y
   glVertex2f(0,100); // x, y
  glEnd();
    glColor3f(1.0f, 1.0f, 1.0f); //
  glBegin(GL_POLYGON);
   glVertex2f(0,0); // x, y
   glVertex2f(2,0); // x, y
   glVertex2f(2,85); // x, y
   glVertex2f(0,85); // x, y
  glEnd();
    glBegin(GL_POLYGON);
   glVertex2f(98,0); // x, y
   glVertex2f(100,0); // x, y
   glVertex2f(100,85); // x, y
   glVertex2f(98,85); // x, y
  glEnd();




glColor3f(0.0f, 0.0f,0.0f); //
   glBegin(GL_POLYGON);
   glVertex2f(cx1-sqWid/2,cy1-sqWid/2); // x, y
   glVertex2f(cx1+sqWid/2,cy1-sqWid/2); // x, y
   glVertex2f(cx1+sqWid/2,cy1+sqWid/2); // x, y y
   glVertex2f(cx1-sqWid/2,cy1+sqWid/2); // x, y
  glEnd();
  glBegin(GL_LINE_LOOP);
   glVertex2f(cx1-sqWid/2,cy1-sqWid/2); // x, y
   glVertex2f(cx1+sqWid/2,cy1-sqWid/2); // x, y
   glVertex2f(cx1+sqWid/2,cy1+sqWid/2); // x, y
   glVertex2f(cx1-sqWid/2,cy1+sqWid/2);
  glEnd();

  glColor3f(1.0f, 1.0f, 1.0f); //
  glBegin(GL_POLYGON);
   glVertex2f(cx2-sqWid/2, cy2-sqWid/2); // x, y
   glVertex2f(cx2+sqWid/2, cy2-sqWid/2); // x, y
   glVertex2f(cx2+sqWid/2, cy2+sqWid/2); // x, y
   glVertex2f(cx2-sqWid/2, cy2+sqWid/2); // x, y
  glEnd();
  glColor3f(0.0f, 0.0f,0.0f);
    glBegin(GL_LINE_LOOP);
   glVertex2f(cx2-sqWid/2, cy2-sqWid/2); // x, y
   glVertex2f(cx2+sqWid/2, cy2-sqWid/2); // x, y
   glVertex2f(cx2+sqWid/2, cy2+sqWid/2); // x, y
   glVertex2f(cx2-sqWid/2, cy2+sqWid/2);
  glEnd();

glColor3f(0.8f, 0.0f, 0.6f); //
glBegin(GL_POLYGON);
glVertex2f(cx3-sqWid/2, cy3-sqWid/2); // x, y
glVertex2f(cx3+sqWid/2, cy3-sqWid/2); // x, y
glVertex2f(cx3+sqWid/2, cy3+sqWid/2); // x, y
glVertex2f(cx3-sqWid/2, cy3+sqWid/2); // x,y
glEnd();
  glColor3f(0.0f, 0.0f,0.0f);
    glBegin(GL_LINE_LOOP);
glVertex2f(cx3-sqWid/2, cy3-sqWid/2); // x, y
glVertex2f(cx3+sqWid/2, cy3-sqWid/2); // x, y
glVertex2f(cx3+sqWid/2, cy3+sqWid/2); // x, y
glVertex2f(cx3-sqWid/2, cy3+sqWid/2); // x,y
  glEnd();

glColor3f(1.0f, 0.7f, 0.0f); //
glBegin(GL_POLYGON);
glVertex2f(cx4-sqWid/2, cy4-sqWid/2); // x, y
glVertex2f(cx4+sqWid/2, cy4-sqWid/2); // x, y
glVertex2f(cx4+sqWid/2, cy4+sqWid/2); // x, y
glVertex2f(cx4-sqWid/2, cy4+sqWid/2); // x,y
glEnd();
  glColor3f(0.0f, 0.0f,0.0f);
    glBegin(GL_LINE_LOOP);
glVertex2f(cx4-sqWid/2, cy4-sqWid/2); // x, y
glVertex2f(cx4+sqWid/2, cy4-sqWid/2); // x, y
glVertex2f(cx4+sqWid/2, cy4+sqWid/2); // x, y
glVertex2f(cx4-sqWid/2, cy4+sqWid/2); // x,y
  glEnd();
glColor3f(1.0f, 1.0f, 0.0f); //
glBegin(GL_POLYGON);
glVertex2f(cx5-sqWid/2, cy5-sqWid/2); // x, y
glVertex2f(cx5+sqWid/2, cy5-sqWid/2); // x, y
glVertex2f(cx5+sqWid/2, cy5+sqWid/2); // x, y
glVertex2f(cx5-sqWid/2, cy5+sqWid/2); // x,y
glEnd();
  glColor3f(0.0f, 0.0f,0.0f);
    glBegin(GL_LINE_LOOP);
glVertex2f(cx5-sqWid/2, cy5-sqWid/2); // x, y
glVertex2f(cx5+sqWid/2, cy5-sqWid/2); // x, y
glVertex2f(cx5+sqWid/2, cy5+sqWid/2); // x, y
glVertex2f(cx5-sqWid/2, cy5+sqWid/2); // x,y
  glEnd();
glColor3f(0.0f, 0.0f, 1.0f); //
glBegin(GL_POLYGON);
glVertex2f(cx6-sqWid/2, cy6-sqWid/2); // x, y
glVertex2f(cx6+sqWid/2, cy6-sqWid/2); // x, y
glVertex2f(cx6+sqWid/2, cy6+sqWid/2); // x, y
glVertex2f(cx6-sqWid/2, cy6+sqWid/2); // x,y
glEnd();
  glColor3f(0.0f, 0.0f,0.0f);
    glBegin(GL_LINE_LOOP);
glVertex2f(cx6-sqWid/2, cy6-sqWid/2); // x, y
glVertex2f(cx6+sqWid/2, cy6-sqWid/2); // x, y
glVertex2f(cx6+sqWid/2, cy6+sqWid/2); // x, y
glVertex2f(cx6-sqWid/2, cy6+sqWid/2); // x,y
  glEnd();
glColor3f(0.0f, 1.0f, 0.0f); //
glBegin(GL_POLYGON);
glVertex2f(cx7-sqWid/2, cy7-sqWid/2); // x, y
glVertex2f(cx7+sqWid/2, cy7-sqWid/2); // x, y
glVertex2f(cx7+sqWid/2, cy7+sqWid/2); // x, y
glVertex2f(cx7-sqWid/2, cy7+sqWid/2); // x,y
glEnd();
  glColor3f(0.0f, 0.0f,0.0f);
    glBegin(GL_LINE_LOOP);
glVertex2f(cx7-sqWid/2, cy7-sqWid/2); // x, y
glVertex2f(cx7+sqWid/2, cy7-sqWid/2); // x, y
glVertex2f(cx7+sqWid/2, cy7+sqWid/2); // x, y
glVertex2f(cx7-sqWid/2, cy7+sqWid/2); // x,y
  glEnd();
glColor3f(1.0f, 0.0f, 0.0f); //
glBegin(GL_POLYGON);
glVertex2f(cx8-sqWid/2, cy8-sqWid/2); // x, y
glVertex2f(cx8+sqWid/2, cy8-sqWid/2); // x, y
glVertex2f(cx8+sqWid/2, cy8+sqWid/2); // x, y
glVertex2f(cx8-sqWid/2, cy8+sqWid/2); // x,y
glEnd();
  glColor3f(0.0f, 0.0f,0.0f);
    glBegin(GL_LINE_LOOP);
glVertex2f(cx8-sqWid/2, cy8-sqWid/2); // x, y
glVertex2f(cx8+sqWid/2, cy8-sqWid/2); // x, y
glVertex2f(cx8+sqWid/2, cy8+sqWid/2); // x, y
glVertex2f(cx8-sqWid/2, cy8+sqWid/2); // x,y
  glEnd();





//button1
  glColor3f(red[0],green[0],blue[0]);
    glBegin(GL_POLYGON);
   glVertex2f(bx1-button_width/2,by1-button_height/2); // x, y
   glVertex2f(bx1+button_width/2,by1-button_height/2); // x, y
   glVertex2f(bx1+button_width/2,by1+button_height/2); // x, y y
   glVertex2f(bx1-button_width/2,by1+button_height/2); // x, y
  glEnd();
  glColor3f(0.0f, 0.0f,0.0f); //
   glBegin(GL_LINE_LOOP);
   glVertex2f(bx1-button_width/2,by1-button_height/2); // x, y
   glVertex2f(bx1+button_width/2,by1-button_height/2); // x, y
   glVertex2f(bx1+button_width/2,by1+button_height/2); // x, y y
   glVertex2f(bx1-button_width/2,by1+button_height/2); // x, y
  glEnd();

    //button2
    glColor3f(red[1],green[1],blue[1]);
     glBegin(GL_POLYGON);
   glVertex2f(bx2-button_width/2,by2-button_height/2); // x, y
   glVertex2f(bx2+button_width/2,by2-button_height/2); // x, y
   glVertex2f(bx2+button_width/2,by2+button_height/2); // x, y y
   glVertex2f(bx2-button_width/2,by2+button_height/2); // x, y
  glEnd();
    glColor3f(0.0f, 0.0f,0.0f);
   glBegin(GL_LINE_LOOP);
   glVertex2f(bx2-button_width/2,by2-button_height/2); // x, y
   glVertex2f(bx2+button_width/2,by2-button_height/2); // x, y
   glVertex2f(bx2+button_width/2,by2+button_height/2); // x, y y
   glVertex2f(bx2-button_width/2,by2+button_height/2); // x, y
  glEnd();
  //button3
  glColor3f(red[2],green[2],blue[2]);
  glBegin(GL_POLYGON);
   glVertex2f(bx3-button_width/2,by3-button_height/2); // x, y
   glVertex2f(bx3+button_width/2,by3-button_height/2); // x, y
   glVertex2f(bx3+button_width/2,by3+button_height/2); // x, y y
   glVertex2f(bx3-button_width/2,by3+button_height/2); // x, y
  glEnd();
  glColor3f(0.0f, 0.0f,0.0f);
   glBegin(GL_LINE_LOOP);
   glVertex2f(bx3-button_width/2,by3-button_height/2); // x, y
   glVertex2f(bx3+button_width/2,by3-button_height/2); // x, y
   glVertex2f(bx3+button_width/2,by3+button_height/2); // x, y y
   glVertex2f(bx3-button_width/2,by3+button_height/2); // x, y
  glEnd();
  //button4
   glColor3f(red[3],green[3],blue[3]);
  glBegin(GL_POLYGON);
   glVertex2f(bx4-button_width/2,by4-button_height/2); // x, y
   glVertex2f(bx4+button_width/2,by4-button_height/2); // x, y
   glVertex2f(bx4+button_width/2,by4+button_height/2); // x, y y
   glVertex2f(bx4-button_width/2,by4+button_height/2); // x, y
  glEnd();
  glColor3f(0.0f, 0.0f,0.0f);
   glBegin(GL_LINE_LOOP);
   glVertex2f(bx4-button_width/2,by4-button_height/2); // x, y
   glVertex2f(bx4+button_width/2,by4-button_height/2); // x, y
   glVertex2f(bx4+button_width/2,by4+button_height/2); // x, y y
   glVertex2f(bx4-button_width/2,by4+button_height/2); // x, y
  glEnd();
  //button5
   glColor3f(red[4],green[4],blue[4]);
  glBegin(GL_POLYGON);
   glVertex2f(bx5-button_width/2,by5-button_height/2); // x, y
   glVertex2f(bx5+button_width/2,by5-button_height/2); // x, y
   glVertex2f(bx5+button_width/2,by5+button_height/2); // x, y y
   glVertex2f(bx5-button_width/2,by5+button_height/2); // x, y
  glEnd();
  glColor3f(0.0f, 0.0f,0.0f);
     glBegin(GL_LINE_LOOP);
   glVertex2f(bx5-button_width/2,by5-button_height/2); // x, y
   glVertex2f(bx5+button_width/2,by5-button_height/2); // x, y
   glVertex2f(bx5+button_width/2,by5+button_height/2); // x, y y
   glVertex2f(bx5-button_width/2,by5+button_height/2); // x, y
  glEnd();
  //button6
   glColor3f(red[5],green[5],blue[5]);
  glBegin(GL_POLYGON);
   glVertex2f(bx6-button_width/2,by6-button_height/2); // x, y
   glVertex2f(bx6+button_width/2,by6-button_height/2); // x, y
   glVertex2f(bx6+button_width/2,by6+button_height/2); // x, y y
   glVertex2f(bx6-button_width/2,by6+button_height/2); // x, y
  glEnd();
  glColor3f(0.0f, 0.0f,0.0f);
     glBegin(GL_LINE_LOOP);
   glVertex2f(bx6-button_width/2,by6-button_height/2); // x, y
   glVertex2f(bx6+button_width/2,by6-button_height/2); // x, y
   glVertex2f(bx6+button_width/2,by6+button_height/2); // x, y y
   glVertex2f(bx6-button_width/2,by6+button_height/2); // x, y
  glEnd();
  //button7
   glColor3f(red[6],green[6],blue[6]);
  glBegin(GL_POLYGON);
   glVertex2f(bx7-button_width/2,by7-button_height/2); // x, y
   glVertex2f(bx7+button_width/2,by7-button_height/2); // x, y
   glVertex2f(bx7+button_width/2,by7+button_height/2); // x, y y
   glVertex2f(bx7-button_width/2,by7+button_height/2); // x, y
  glEnd();
  glColor3f(0.0f, 0.0f,0.0f);
       glBegin(GL_LINE_LOOP);
   glVertex2f(bx7-button_width/2,by7-button_height/2); // x, y
   glVertex2f(bx7+button_width/2,by7-button_height/2); // x, y
   glVertex2f(bx7+button_width/2,by7+button_height/2); // x, y y
   glVertex2f(bx7-button_width/2,by7+button_height/2); // x, y
  glEnd();
  //button8
   glColor3f(red[7],green[7],blue[7]);
  glBegin(GL_POLYGON);
   glVertex2f(bx8-button_width/2,by8-button_height/2); // x, y
   glVertex2f(bx8+button_width/2,by8-button_height/2); // x, y
   glVertex2f(bx8+button_width/2,by8+button_height/2); // x, y y
   glVertex2f(bx8-button_width/2,by8+button_height/2); // x, y
  glEnd();
  glColor3f(0.0f, 0.0f,0.0f);
       glBegin(GL_LINE_LOOP);
   glVertex2f(bx8-button_width/2,by8-button_height/2); // x, y
   glVertex2f(bx8+button_width/2,by8-button_height/2); // x, y
   glVertex2f(bx8+button_width/2,by8+button_height/2); // x, y y
   glVertex2f(bx8-button_width/2,by8+button_height/2); // x, y
  glEnd();
  printsome("Line",bx1-2,by1-1,1);
  printsome("Pen",bx2-2,by2-1,1);
  printsome("Rect",bx3-3,by3-1,1);
  printsome("Text",bx4-3,by4-1,1);
  printsome("Circle",bx5-3,by5-1,1);
  printsome("Undo",bx6-3,by6-1,1);
  printsome("Fill",bx7-2,by7-1,1);
  printsome("No Fill",bx8-4,by8-1,1);
     glBegin(GL_LINE_LOOP);
   glVertex2f(2,0); // x, y
   glVertex2f(98,0); // x, y
   glVertex2f(98,85); // x, y y
   glVertex2f(2,85); // x, y
  glEnd();






}





void DrawCircle_solid(float cx, float cy, float r, int num_segments,int status)
{
set_color(status);

glBegin(GL_POLYGON);
for (int i = 0; i < num_segments; i++) {
float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle
float x = r * cosf(theta);//calculate the x component
float y = r * sinf(theta);//calculate the y component
glVertex2f(x + cx, y + cy);//output vertex
}
glEnd();
}


void DrawCircle(float cx, float cy, float r, int num_segments,int status) {
set_color(status);

glBegin(GL_LINE_LOOP);
for (int i = 0; i < num_segments; i++) {
float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); //get the current angle in radians
float x = r * cosf(theta);//calculate the x component
float y = r * sinf(theta);//calculate the y component
glVertex2f(x + cx, y + cy);//output vertex
}
glEnd();
}
void drawsquare_empty(int x0, int y0,int x1,int y1,int status ){

set_color(status);

glBegin(GL_LINE_LOOP);
 glVertex2f (x0,y0);
 glVertex2f (x1,y0);
 glVertex2f (x1,y1);
 glVertex2f (x0,y1);
 glEnd();
}

void drawsquare(int x0, int y0,int x1,int y1,int status )
{
set_color(status);

 glBegin(GL_POLYGON);
 glVertex2f (x0,y0);
 glVertex2f (x1,y0);
 glVertex2f (x1,y1);
 glVertex2f (x0,y1);
 glEnd();
}
void Keyboard(unsigned char key,int x,int y)
{
 if(key==char(8)){
    strcpy(str,"");
 }
if(key==char(13))
{
    text[k][0]=mouseX;
    text[k][1]=mouseY;
    text[k][2]=status;
    strcpy(text_str[k],str);
    k++;
    universal[k]=6;
       strcpy(str,"");
}

 Newstr[0]=key;
 strcat(str,Newstr);
 glutPostRedisplay();
}

void mouseClick(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
    mouseX = x;
    mouseX=0.5+1.0*mouseX*logWidth/physWidth;
    mouseY = physHeight- y;
    mouseY=0.5+1.0*mouseY*logHeight/physHeight;
    drawX=mouseX,drawY=mouseY;
        if( mouseX>=(cx1-sqWid/2) && mouseX<=(cx1+sqWid/2) && mouseY >=(cy1-sqWid/2) && mouseY <=(cy1+sqWid/2))
    {
        status=1;
    }
    if( mouseX>=(cx2-sqWid/2) && mouseX<=(cx2+sqWid/2) && mouseY >=(cy2-sqWid/2) && mouseY <=(cy2+sqWid/2))
    {
        status=2;
    }
    if( mouseX>=(cx3-sqWid/2) && mouseX<=(cx3+sqWid/2) && mouseY >=(cy3-sqWid/2) && mouseY <=(cy3+sqWid/2))
    {
        status=3;
    }
    if( mouseX>=(cx4-sqWid/2) && mouseX<=(cx4+sqWid/2) && mouseY >=(cy4-sqWid/2) && mouseY <=(cy4+sqWid/2))
    {
        status=4;
    }
     if( mouseX>=(cx5-sqWid/2) && mouseX<=(cx5+sqWid/2) && mouseY >=(cy5-sqWid/2) && mouseY <=(cy5+sqWid/2))
    {
        status=5;
    }
     if( mouseX>=(cx6-sqWid/2) && mouseX<=(cx6+sqWid/2) && mouseY >=(cy6-sqWid/2) && mouseY <=(cy6+sqWid/2))
    {
        status=6;
    }
      if( mouseX>=(cx7-sqWid/2) && mouseX<=(cx7+sqWid/2) && mouseY >=(cy7-sqWid/2) && mouseY <=(cy7+sqWid/2))
    {
        status=7;
    }
      if( mouseX>=(cx8-sqWid/2) && mouseX<=(cx8+sqWid/2) && mouseY >=(cy8-sqWid/2) && mouseY <=(cy8+sqWid/2))
    {
        status=8;
    }
    if( mouseX>=(bx7-button_width/2) && mouseX<=(bx7+button_width/2) && mouseY >=(by7-button_height/2) && mouseY <=(by7+button_height/2))
    {
        temp_red[7]=temp_green[7]=temp_blue[7]=1;
        temp_red[6]=temp_green[6]=temp_blue[6]=.95;
        filled=1;
        if(filled &&universal[k]==2)
            universal[k]=1;
        if(filled&&universal[k]==4)
            universal[k]=3;
    }
    if( mouseX>=(bx8-button_width/2) && mouseX<=(bx8+button_width/2) && mouseY >=(by8-button_height/2) && mouseY <=(by8+button_height/2))
    {
        temp_red[6]=temp_green[6]=temp_blue[6]=1;
        temp_red[7]=temp_green[7]=temp_blue[7]=.95;
        filled=0;
        if(!filled &&universal[k]==1)
            universal[k]=2;
        if(!filled&&universal[k]==3)
            universal[k]=4;
    }
       if( mouseX>=(bx3-button_width/2) && mouseX<=(bx3+button_width/2) && mouseY >=(by3-button_height/2) && mouseY <=(by3+button_height/2))
    {
        for (int i=0;i<6;i++){
        temp_red[i]=temp_green[i]=temp_blue[i]=1;
    }
        temp_red[2]=temp_green[2]=temp_blue[2]=.95;
        if(filled)
            universal[k]=3;
        else
            universal[k]=4;

    }
    if( mouseX>=(bx5-button_width/2) && mouseX<=(bx5+button_width/2) && mouseY >=(by5-button_height/2) && mouseY <=(by5+button_height/2))
    {
        for (int i=0;i<6;i++){
        temp_red[i]=temp_green[i]=temp_blue[i]=1;
    }
        temp_red[4]=temp_green[4]=temp_blue[4]=.95;
        if(filled)
            universal[k]=1;
        else
            universal[k]=2;
    }
       if( mouseX>=(bx6-button_width/2) && mouseX<=(bx6+button_width/2) && mouseY >=(by6-button_height/2) && mouseY <=(by6+button_height/2))
    {
        if(k-1>=0)
            k--;

        point_width[k]=0;
        rect[k][2]=rect[k][0];
        rect[k][3]=rect[k][1];
        circle[k][2]=0;
        line[k][0]=line[k][1]=line[k][2]=line[k][3]=0;
        strcpy(text_str[k],"");



    }
    if( mouseX>=(bx1-button_width/2) && mouseX<=(bx1+button_width/2) && mouseY >=(by1-button_height/2) && mouseY <=(by1+button_height/2))
    {
        universal[k]=5;
        for (int i=0;i<6;i++){
        temp_red[i]=temp_green[i]=temp_blue[i]=1;
    }
        temp_red[0]=temp_green[0]=temp_blue[0]=.95;


    }
    if( mouseX>=(bx4-button_width/2) && mouseX<=(bx4+button_width/2) && mouseY >=(by4-button_height/2) && mouseY <=(by4+button_height/2))
    {
        universal[k]=6;
        for (int i=0;i<6;i++){
        temp_red[i]=temp_green[i]=temp_blue[i]=1;
    }
        temp_red[3]=temp_green[3]=temp_blue[3]=.95;
    }
     if( mouseX>=(bx2-button_width/2) && mouseX<=(bx2+button_width/2) && mouseY >=(by2-button_height/2) && mouseY <=(by2+button_height/2))
    {

        universal[k]=7;
        for (int i=0;i<6;i++){
        temp_red[i]=temp_green[i]=temp_blue[i]=1;
    }
        temp_red[1]=temp_green[1]=temp_blue[1]=.95;
    }






    }

    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    {
        exit(1);
    }
     glutPostRedisplay();
}
void MMouse (int x,int y){
    draw=1;
    if(universal[k]==3||universal[k]==4){
    rect[k][0]=mouseX;
        rect[k][1]=mouseY;
        rect[k][2]=drawX;
        rect[k][3]=drawY;
        rect[k][4]=status;
}

    if(universal[k]==1||universal[k]==2){
    circle[k][0]=mouseX;
    circle[k][1]=mouseY;
    circle[k][2]=calculate_distance(mouseX,mouseY,drawX,drawY);
    circle[k][3]=status;
    }
    if(universal[k]==5){
    line[k][0]=mouseX;
    line[k][1]=mouseY;
    line[k][2]=drawX;
    line[k][3]=drawY;
    line[k][4]=status;
    }
    if(universal[k]==7){

    point_x[k][point_width[k]]=drawX;
    point_y[k][point_width[k]]=drawY;
    point_color[k]=status;
    point_width[k]+=1;
    }

    drawX = x;
    drawX=0.5+1.0*drawX*logWidth/physWidth;
    drawY = physHeight- y;
    drawY=0.5+1.0*drawY*logHeight/physHeight;
    glutPostRedisplay();

}
void passiveMouse (int x,int y){
    passive_x = x;
    passive_x=0.5+1.0*passive_x*logWidth/physWidth;
    passive_y = physHeight- y;
    passive_y=0.5+1.0*passive_y*logHeight/physHeight;
      if( passive_x>=(bx2-button_width/2) && passive_x<=(bx2+button_width/2) && passive_y >=(by2-button_height/2) && passive_y <=(by2+button_height/2))
        red[1]=green[1]=blue[1]=.8;
    else
    red[1]=green[1]=blue[1]=temp_red[1];

          if( passive_x>=(bx1-button_width/2) && passive_x<=(bx1+button_width/2) && passive_y >=(by1-button_height/2) && passive_y <=(by1+button_height/2))
        red[0]=green[0]=blue[0]=.8;
    else
    red[0]=green[0]=blue[0]=temp_red[0];
    if( passive_x>=(bx3-button_width/2) && passive_x<=(bx3+button_width/2) && passive_y >=(by3-button_height/2) && passive_y <=(by3+button_height/2))
        red[2]=green[2]=blue[2]=.8;
    else
    red[2]=green[2]=blue[2]=temp_red[2];
    if( passive_x>=(bx4-button_width/2) && passive_x<=(bx4+button_width/2) && passive_y >=(by4-button_height/2) && passive_y <=(by4+button_height/2))
        red[3]=green[3]=blue[3]=.8;
    else
    red[3]=green[3]=blue[3]=temp_red[3];
    if( passive_x>=(bx5-button_width/2) && passive_x<=(bx5+button_width/2) && passive_y >=(by5-button_height/2) && passive_y <=(by5+button_height/2))
        red[4]=green[4]=blue[4]=.8;
    else
    red[4]=green[4]=blue[4]=temp_red[4];
    if( passive_x>=(bx6-button_width/2) && passive_x<=(bx6+button_width/2) && passive_y >=(by6-button_height/2) && passive_y <=(by6+button_height/2))
        red[5]=green[5]=blue[5]=.8;
    else
    red[5]=green[5]=blue[5]=temp_red[5];
     if( passive_x>=(bx7-button_width/2) && passive_x<=(bx7+button_width/2) && passive_y >=(by7-button_height/2) && passive_y <=(by7+button_height/2))
        red[6]=green[6]=blue[6]=.8;
    else
    red[6]=green[6]=blue[6]=temp_red[6];
     if( passive_x>=(bx8-button_width/2) && passive_x<=(bx8+button_width/2) && passive_y >=(by8-button_height/2) && passive_y <=(by8+button_height/2))
        red[7]=green[7]=blue[7]=.8;
    else
    red[7]=green[7]=blue[7]=temp_red[7];











    if(draw&&universal[k]!=0)
    {


        k++;
        universal[k]=universal[k-1];
        draw=0;
        mouseX=0,mouseY=0,drawX=mouseX,drawY=mouseY;

    }




glutPostRedisplay();
}
void drawer(){
for (int i=0;i<=k;i++){
    if(universal[i]==1)
        DrawCircle_solid(circle[i][0],circle[i][1],circle[i][2],400,circle[i][3]);
    else if(universal[i]==2)
        DrawCircle(circle[i][0],circle[i][1],circle[i][2],400,circle[i][3]);
    else if(universal[i]==3)
        drawsquare(rect[i][0],rect[i][1],rect[i][2],rect[i][3],rect[i][4]);
    else if(universal[i]==4)
        drawsquare_empty(rect[i][0],rect[i][1],rect[i][2],rect[i][3],rect[i][4]);
    else if(universal[i]==5)
        drawline(line[i][0],line[i][1],line[i][2],line[i][3],line[i][4]);
    else if(universal[i]==6)
    {
        printsome(str,mouseX,mouseY,status);
        printsome(text_str[i],text[i][0],text[i][1],text[i][2]);
    }
    else if(universal[i]==7){
            for (int j=0;j<point_width[i];j++)
        DrawCircle_solid(point_x[i][j],point_y[i][j],.8,200,point_color[i]);

    }

}

}

void init2D(float r, float g, float b)
{
    glClearColor(r,g,b,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,logWidth,0.0,logHeight);
}

void display(void)
{


glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 0.0, 0.0);
drawSquares();
drawer();
drawSquares();
glutSwapBuffers();
glFlush();
}

int main(int argc, char *argv[])
{
    for (int i=0;i<8;i++){
        red[i]=green[i]=blue[i]=1;
        temp_red[i]=temp_green[i]=temp_blue[i]=1;
    }
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(physWidth,physHeight);
    glutInitWindowPosition(logWidth,logHeight);
    glutCreateWindow("Paint App Seif elkateb");
    init2D(1.0,1.0,1.0);
    glutDisplayFunc(display);
    glutKeyboardFunc(Keyboard);
    glutMouseFunc(mouseClick);
    glutPassiveMotionFunc(passiveMouse);
    glutMotionFunc(MMouse);

    glutMainLoop();
}
