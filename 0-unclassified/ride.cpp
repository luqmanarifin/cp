/*
ID: l.arifi1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <cstdlib>
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
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

#define LL long long
#define DB double
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORD(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORM(i,n) FORD(i, 0, n-1)
#define mp make_pair
#define open freopen("ride.in","r",stdin); freopen("ride.out","w",stdout)
#define close fclose(stdin); fclose(stdout)

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int main(void)
{
	ios_base::sync_with_stdio(false);
	 open;
	char a[10], b[10];
	sf("%s %s", a, b);
	int lena = strlen(a), lenb = strlen(b), i;
	LL aa = 1, bb = 1;
	FORS(i, lena) aa *= a[i]-'A'+ 1;
	FORS(i, lenb) bb *= b[i]-'A'+ 1;
	if(aa % 47 == bb % 47) puts("GO");
	else puts("STAY");
	
	close;
	return 0;
}