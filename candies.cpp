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

char a[1000];
int g,s,ans,n,m,i,j,dis[1000];

int main()
{
	sf("%d%d",&n,&m);
	FORS(i,n) {
		sf("%s", &a);
		FORS(j,m) {
			if(a[j] == 'G') g = j;
			if(a[j] == 'S') s = j;
		}
		if(s < g) { cout << -1; nl; return 0; }
		dis[s-g]++;
	}
	FORS(i,1000) if(dis[i]) ans++;
	cout << ans; nl;
	return 0;
}