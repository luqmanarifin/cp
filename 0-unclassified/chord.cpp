#include <iostream>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>

using namespace std;

#define LL long long
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORS(i,n) FOR(i,0,n-1)
#define FORD(i,n) for( i=n-1; i>=0; i--)

const int N = 1000010;

int gcd(int a, int b) {
	while (a > 0 && b > 0)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

int lcm(int a, int b) {
	return a*b / gcd(a,b);
}

void swap(int *a,int *b){
	int temp;
	temp=*a; *a=*b; *b=temp;
}

string a,b,c;
int x,y,z;

int main()
{
	map<string,int> number;
	number["C"] = 1; //y
	number["C#"] = 2;
	number["D"] = 3; 
	number["D#"] = 4;
	number["E"] = 5; 
	number["F"] = 6;
	number["F#"] = 7;
	number["G"] = 8; 
	number["G#"] = 9;
	number["A"] = 10;//z
	number["B"] = 11;
	number["H"] = 12;//x

	cin>>a>>b>>c;
	x=number[a]; y=number[b]; z=number[c];
	if((abs(x-z)!=5)&&(abs(x-z)!=7)) swap(y,z);
	if((abs(x-z)!=5)&&(abs(x-z)!=7))swap(x,y);

	if(((z>x)&&(z-x==5))||((z<x)&&(x-z==7)))swap(x,z);
	if(((z>y)&&(z-y==7))||((z<y)&&(y-z==5)))swap(x,y);
	
	if(((abs(z-y)==3)||(abs(z-y)==9))&&((abs(x-y)==4)||(abs(x-y)==8))&&((abs(z-x)==5)||(abs(z-x)==7))) cout<<"major\n";
	else if(((abs(z-y)==4)||(abs(z-y)==8))&&((abs(x-y)==3)||(abs(x-y)==9))&&((abs(x-z)==7)||(abs(x-z)==5))) cout<<"minor\n";
	else cout<<"strange\n";

	return 0;
}