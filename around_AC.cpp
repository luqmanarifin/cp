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
#define FORD(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORM(i,n) FORM(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define db double

const int N = 1000010;
const LL mod = 1e9 + 7;
const LL M = 1e7;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

LL ans[M+5];

int main(void)
{
	memset(ans, 0, sizeof(ans));
	int i;
	ans[1] = 1; ans[2] = 2; ans[3] = 4;
	FOR(i, 4, M) 
		ans[i] = (ans[i-1] + ans[i-2] + ans[i-3])%mod;

	int n;
	sf("%d", &n);
	LL t;
	while(n--) {
		sf("%lld", &t);
		pf("%lld\n", ans[t]);
	}
	
	//FOR(i,1,10) pf("%lld ", ans[i]);
	
	return 0;
}