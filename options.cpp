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
#include <stdlib.h>

using namespace std;

#define nl cout << endl
#define LL long long
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORM(i,a,b) for( i=b; i>=a; i--)
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

char a[15];
int t;

bool cek(int m, int n) {
	int j;
	for(j = m-1; j < 12; j += n)
		if (a[j] == 'O')
			return false;
	return true;
}

bool g,b,c,d,e,f;
int ans;

int main()
{
	sf("%d", &t);
	int i,j;
	FORS(i,t) {
		ans = 0;
		sf("%s", &a);
		g = 0; b = 0; c = 0; d = 0; e = 0; f = 0;
		FOR(j,1,12) if(cek(j,12)) { g = 1; break; }
		FOR(j,1,6) if(cek(j,6)) { b = 1; break; }
		FOR(j,1,4) if(cek(j,4)) { c = 1; break; }
		FOR(j,1,3) if(cek(j,3)) { d = 1; break; }
		FOR(j,1,2) if(cek(j,2)) { e = 1; break; }
		FOR(j,1,1) if(cek(j,1)) { f = 1; break; }
		if(g) ans++; if(b) ans++; if(c) ans++;
		if(d) ans++; if(e) ans++; if(f) ans++;
		// pf("%s\n",a);
		pf("%d ", ans);
		if (g) pf("1x12 ");
		if (b) pf("2x6 ");
		if (c) pf("3x4 ");
		if (d) pf("4x3 ");
		if (e) pf("6x2 ");
		if (f) pf("12x1 ");
		nl;
	}
	return 0;
}