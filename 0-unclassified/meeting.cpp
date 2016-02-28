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

int xa,xb,ya,yb,ans=0,i,j,n;
int x[1005], y[1005], r[1005];
bool okay;

int f(int x) {
	return x*x;
}

int main()
{
	sf("%d%d%d%d%d",&xa,&ya,&xb,&yb,&n);
	FOR(i,1,n) sf("%d%d%d",&x[i],&y[i],&r[i]);
	FOR(i,min(ya,yb),max(ya,yb)) {
		okay = 0; j = 1;
		while(!okay && j<=n) {
			if(f(xa-x[j]) + f(i-y[j]) <= f(r[j])) okay = 1;
			else j++;
		}
		if(okay) continue;
		ans++;
	}
	FOR(i,min(ya,yb),max(ya,yb)) {
		okay = 0; j = 1;
		while(!okay && j<=n) {
			if(f(xb-x[j]) + f(i-y[j]) <= f(r[j])) okay = 1;
			else j++;
		}
		if(okay) continue;
		ans++;
	}
	FOR(i,min(xa,xb)+1,max(xa,xb)-1) {
		okay = 0; j = 1;
		while(!okay && j<=n) {
			if(f(i-x[j]) + f(yb-y[j]) <= f(r[j])) okay = 1;
			else j++;
		}
		if(okay) continue;
		ans++;
	}
	FOR(i,min(xa,xb)+1,max(xa,xb)-1) {
		okay = 0; j = 1;
		while(!okay && j<=n) {
			if(f(i-x[j]) + f(ya-y[j]) <= f(r[j])) okay = 1;
			else j++;
		}
		if(okay) continue;
		ans++;
	}
	cout << ans << endl;
	return 0;
}