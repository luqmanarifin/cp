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

int y[10]={0,0,0,0,0,0,0,0,0,0};
int n,i;
char a[4],b[4],c[4],d[4];
bool cek = true;

void masuk(char a[4],int *x){
	int i;
	for(i=0; i<4; i++ ){
		switch (a[i]){
		case 1 : *(x+1)+=1; break;
		case 2 : *(x+2)+=1; break;
		case 3 : *(x+3)+=1; break;
		case 4 : *(x+4)+=1; break;
		case 5 : *(x+5)+=1; break;
		case 6 : *(x+6)+=1; break;
		case 7 : *(x+7)+=1; break;
		case 8 : *(x+8)+=1; break;
		case 9 : *(x+9)+=1; break;
		}
	}
}
int main()
{
	cin >> n;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	masuk(a,y); masuk(b,y);masuk(c,y); masuk(d,y);
	for( i=1;i<=9;i++ ){
		if(y[i]>2*n) cek = false;
		cout << y[i] << " ";
	}
	cout << "\n";
	cout << a << " " << b << " " << c << " " << d;
	if(cek) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}