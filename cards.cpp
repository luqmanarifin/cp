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

long a,b,i,j;
LL ans;

LL f(LL n ) {
	return n*n;
}

int main()
{
	cin >> a >> b;
	if(a >= b) {
		if(b%2) ans = a*a - (b/2+1)*(b/2+1) - (b/2)*(b/2);
		else ans = a*a - 2*(b/2)*(b/2);
		cout << ans; nl;
		FORS(i,b/2) pf("x"); if(b%2) pf("x");
		FORS(i,a) pf("o");
		FORS(i,b/2) pf("x");		
	}
	else {
		long rem = b%(a+1);
		long isi = b/(a+1);
		LL ans = -f(isi+1)*rem + a - f(isi)*(a+1-rem);
		cout << ans; nl;
		FORS(i,rem) {
			FORS(j,isi+1) pf("x"); pf("o");
		}
		FORS(i,a-rem) {
			FORS(j,isi) pf("x"); pf("o");
		}
		FORS(i,isi) pf("x");
	}
	nl;
	return 0;
}