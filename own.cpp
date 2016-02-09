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

bool a[101];
int n,i,j,l,r,ans,p,q;

int main()
{
	sf("%d",&n);
	sf("%d%d",&p,&q);
	FOR(i,p,q-1) a[i] = 1;
	FORS(i,n-1) {
		sf("%d%d",&l,&r);
		j = l;
		while(j <= r-1 && j <= q-1) {
			a[j] = 0;
			j++;
		}
	}
	FORS(i,101) if (a[i]) ans++; cout << ans; nl;
	return 0;
}