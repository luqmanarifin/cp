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

int main()
{
	int n, m, i;
	sf("%d %d", &n, &m);
	if(n*2+2 < m || n > m + 1) pf("-1");
	else if(n == m+1) { FORS(i,m) pf("01"); pf("0"); }
	else if(n*2 > m){
		int dob = m - n;
		FORS(i,dob) pf("110");
		m -= 2*dob; n -= dob;
		int maks = max(n,m);
		FORS(i, maks) {
			if(m) { pf("1"); m--; }
			if(n) { pf("0"); n--; }
		}
	}
	else {
		FORS(i,n) pf("110");
		FORS(i,m-2*n) pf("1");
	}
	nl;
	
	return 0;
}