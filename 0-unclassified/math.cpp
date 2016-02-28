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

int w[170][170], i,j,n;
double a[170][170], b[170][170];

int main()
{
	sf("%d",&n);
	FORS(i,n) FORS(j,n) sf("%d",&w[i][j]);
	FORS(i,n) {
		FORS(j,n) {
			a[i][j] = ((double)w[i][j]+w[j][i])/2;
			b[i][j] = ((double)w[i][j]-w[j][i])/2;
			pf("%.5f ",a[i][j]);
		}
		pf("\n");
	}
	FORS(i,n) { FORS(j,n) pf("%.5f ",b[i][j]); pf("\n"); }
	return 0;
}