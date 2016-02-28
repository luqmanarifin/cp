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
#define FORM(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORD(i,n) FORM(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define x first
#define y second
#define db (double)

const int N = 1000010;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

double a, d, x, y, now;
int n;

int main()
{
	cin >> a >> d >> n;
	x = 0; y = 0;
	while(n--) {
		now += d;
		int temp = (int) now/(4*a);
		now -= temp*4*a;
		if (now > 4*a) now -= 4*a;
		x = 0; y = 0;
		if(now < a) {
			x = now;
		} else if(now < 2*a) {vc
			x = a;
			y = now - a;
		} else if(now < 3*a) {
			x = 3*a - now;
			y = a;
		} else {
			y = 4*a - now;
		}
		pf("%.5f %.5f\n",x,y);
	}
	return 0;
}