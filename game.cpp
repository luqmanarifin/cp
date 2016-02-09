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
#include <utility>
#include <functional>

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
#define mp make_pair

const int N = 1e9;

int gcd(int a, int b) {
	while (a > 0 && b > 0)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

int lcm(int a, int b) {
	return a*b / gcd(a,b);
}

LL a,b,mod,i,j;
bool win;

int digit (LL x) {
	if(!x) return 0;
	return 1 + digit(x/10);
}

int main()
{
	cin >> a >> b >> mod;
	LL rem;
	FOR(i,1,min(mod,a)) {
		rem = i*N% mod;
		if((mod - rem)%mod > b) {
			pf("1 ");
			FORS(j,9-digit(i)) pf("0");
			cout << i; nl;
			return 0;
		}
	}
	pf("2"); nl;
	return 0;
}