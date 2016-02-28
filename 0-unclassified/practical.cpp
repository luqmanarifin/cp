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

const int N = 1000010;
const int inf = 16513376;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

long n, i, a, mini, maks;
long atas=0, bawah=0, bawah2=0, bawah3, c[5010];

void take (long n){
	open;
	sf("%d", &n);
	memset(c, 0, sizeof(c));
	FOR(i,1,n) { sf("%d", &a); c[a]++; }
	FOR(i,1,5000)
		if(c[i]) { mini = i; break; }
	FORM(i,1,5000)
		if(c[i]) { maks = i; break; }
}

void process (long n){
	bawah3 = c[maks];
	FOR(i,2*mini+1,5000)
		atas += c[i];
	if(maks%2) {
		FORM(i,1,maks/2) {
			bawah2 += c[i];
			if(i != maks/2) bawah3 += c[i];
		} bawah = inf;
	} else {
		FORM(i,1,maks/2-1) bawah += c[i];
		bawah2 = inf; bawah3 = inf;
	}
	a = min(min(atas, bawah), min(bawah2, bawah3));
	pf("%d\n", a);
}

int main()
{
	take(n);
	process(n);
	close;
	return 0;
}