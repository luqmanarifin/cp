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

int a,b,c,d,ans;
float ab, bc, cd, cim;

int main()
{
	cin >> a >> b >> c >> d;
	ab = a/b; bc = b/c; cd = c/d; cim = d*b/a;
	if(b - a == c - b && c - b == d - c) ans = d + b - a;
	else if (ab == bc && bc == cd && cim == floor(cim)) ans = d*b/a;
	else ans = 42; cout << ans << endl;
	return 0;
}