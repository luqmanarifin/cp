#include <iostream>
#include <fstream>
#include <cstdlib>
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
#include <utility>
#include <functional>

using namespace std;

#define LL long long
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORD(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORM(i,n) FORM(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define db (double)

const int N = 1000010;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int main(void)
{
	int r1, r2, c1, c2, d1, d2;
	sf("%d %d %d %d %d %d", &r1, &r2, &c1, &c2, &d1, &d2);
	int a = c1 + r1 - d2;
	int b = r1 - c1 + d2;
	int c = d2 - r1 + c1;
	int d = c2 + r2 - d2;
	bool inas 		= (a%2)||(b%2)||(c%2)||(d%2);
	bool nuha 		= (a>18)||(b>18)||(c>18)||(d>18)||(a<2)||(b<2)||(c<2)||(d<2);
	bool ghaliyah 	= (a==b)||(a==c)||(a==d)||(b==c)||(b==d)||(c==d);
	if(inas || nuha || ghaliyah) puts("-1");
	else {
		pf("%d %d\n", a/2, b/2);
		pf("%d %d\n", c/2, d/2);
	}
	
	return 0;
}