/*
ID: l.arifi1
PROG: test
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
#define open freopen("g1.in","r",stdin); freopen("g1.txt","w",stdout)
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
	int t; sf("%d", &t);
	while(t--) {
		char s[(int) 1e5 + 5];
		int i, n, now = 0; sf("%d", &n);
		sf("%s", s);
		FORS(i, n) if(s[i]-'0') now++;
		int awal, ans;
		FORS(awal, n)
			if(s[awal] == '0')
				break;
		int bel = now - awal;
		if((awal == 2 && bel == 1) || (awal == 0 && bel%2 == 0) || (awal&1 && bel == 0))
			puts("Betka");
		else 
			puts("Adam");
	}
	
	close;
	return 0;
}