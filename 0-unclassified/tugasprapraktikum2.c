

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "point.h"

typedef point 
{
float x;
float y;};

function makepoint ( x,y : float) : point;
makepoint : (x,y);

function GetAbsis (P:point) : real;
{real x;
return P.y;}

function GetOrdinat(P:point) : real;
{
real y;
return P.y;
}

void setabsis(point *p,float newx)
{
(*p).x = newx;
}

void setordinat(point *p,float newy)
{
(*p).y = newy;
}

point BacaPoint(point *p,float x,y )
{
printf("masukkan absis");
scanf(&f, x);
printf("masukkan ordinat");
scanf(&f, y);
p = makepoint(x,y);
}

point tulispoint (point *p)
{real x,y;
printf(%f,%f,x,y);
}

bool eq (point p1,p2)
{
bool temp;
if(p1.x==p2.x&&p1.y&&p2.y)
 {
 temp=true;
 }
else
 {temp=false;
 }
return temp;
}

bool neq(point p1,p2)
{
bool temp;
if(p1.x != p2.x && p1.y != p2.y)
temp = true;
else
temp = false;
return temp;
}

bool isorigin (point p)
{
bool temp;
if (p.y==0&&p.x==0)
temp = true;
else
temp = false;
return temp;
}

bool isonsbx (point p);
{ 
bool temp;
if (p.x==0)
temp = true;
else
temp = false;
retun temp;
}

bool isonsby (point p);
{bool temp;
if (p.y==0)
temp = true;
else
temp = false;
retun temp;
}

int kuadran (point p);
{
int kuad;
if (p.x>0&&p.y!=0){
if (p.y >0)
kuad =1;
else 
kuad =4;
} else {
if (p.x<0&&p.y!=0){
if(p.y>0)
kuad=2;
} else
kuad =3;
}
return (kuad);
}

point nextx(point p)
{
p.x++;
return p;
}

point nexty(point p)
{
p.y++;
return p;
}
point plusdelta(point p,int deltax,int deltay)
{
p.x+=deltax;
p.y+=deltay;

return(p);
}

point mirrorof (point P, bool sbx)
{
if(sbx==true) 
{P.x = -P.x;
tulispoint(P);
} else 
{
P.y = -P.y;
tulispoint(p);
}
}

float jarak0(point p)
{

float temp;
p.x = p.x * p.x;
p.y = p.y * p.y;
temp = p.x + p.y;
temp = sqrt(temp);

return temp;
}

float panjang (point p1,p2)
{
float satu,dua,temp;
satu =(p1.x*p1.x)-(p2.x*p2.x));
dua = (p1.y*p1.y)-(p2.y*p2.y);
temp = sqrt(satu+dua);
return temp;
}

void geserpoint(point *p,int deltax,int deltay)
{
(*p).x+=deltax;
(*p).y+=deltay;
}

void geserpointkesbx(point *p)
{
(*p).y=0;

}

void geserpointkesby(point *p)
{
(*p).x=0;
}

void mirrorpoint(point *p,bool sbx,bool sby)
{
{
if (sbx == true){
if(sby == true){
(*p).x=-(*p).x;
tulispoint(*p);
(*p).x=-(*p).x;
(*p).y=-(*p).y;
tulispoint(*p);
}else{
(*p).y=-(*p).y;
tulispoint(*p);}}
else{if (sby == true){
(*p).x=-(*p).x;
tulispoint(*p);
}else{
tulispoint(*p);}
}
}
}

void putarpoint(point *p,float sudut)
{

float temp_sudut;
temp_sudut = (asin((*p).x / jarak0(*p))) + (sudut * 3.14 / 180);

(*p).x = jarak0(*p) * sin(temp_sudut);
(*p).y = jarak0(*p) * cos(temp_sudut);
}


