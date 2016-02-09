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

int n,i,x,y;;
bool ada;
int a[101],b[101];

int main()
{
	sf("%d",&n);
	FOR(i,1,n) { sf("%d%d",&x,&y); a[x] = 1; b[y] = 1; }
	x = 0; y = 0;
	FORS(i,101) { x += a[i]; y += b[i]; }
	if(x > y) cout << y << endl;
	else cout << x << endl;

	return 0;
}