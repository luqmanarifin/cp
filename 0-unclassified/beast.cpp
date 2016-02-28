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

const int N = 1000010;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

struct num {
	int dig;
	int three;
};

num a[100010];

int main()
{
	int i, j, t;
	memset(a, 0, sizeof(a));
	a[3].dig = a[5].dig = 1;
	a[3].three = 1;
	FOR(i,3,100000)
		if(a[i].dig) {
			if(a[i].dig + 1 > a[i+3].dig) {
				a[i+3].dig = a[i].dig + 1;
				a[i+3].three = a[i].three + 1;
			}
			if(a[i].dig + 1 > a[i+5].dig) {
				a[i+5].dig = a[i].dig + 1;
				a[i+5].three = a[i].three;
			}
		}
	sf("%d", &t);
	while(t--) {
		int tmp;
		sf("%d", &tmp);
		if(!a[tmp].dig) { puts("-1"); continue; }
		FORS(j, a[tmp].three*3) pf("5");
		FORS(j, (a[tmp].dig-a[tmp].three)*5) pf("3");
		nl;
	}

	return 0;
}