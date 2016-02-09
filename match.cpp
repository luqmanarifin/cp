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
#define close fclose(stdin); fclose(stdout)
#define db (double)

const int N = 1010;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int mark[N][N], caps[N][N];

int main(void)
{
	int n, m, i, j;
	memset(mark, 0, sizeof(mark));
	memset(caps, 0, sizeof(caps));
	sf("%d %d", &n, &m);
	int temp;
	while(n--) {
		int a, b;
		sf("%d %d", &a, &b);
		mark[b][a]++;
	}
	while(m--) {
		int a, b;
		sf("%d %d", &a, &b);
		caps[b][a]++;
	}
	int u = 0, v = 0;
	FOR(i,1,1000) {
		n = 0; int tot = 0;
		FOR(j,1,1000) {
			n += caps[i][j];
			tot += mark[i][j];
			v += min(caps[i][j],mark[i][j]);
		}
		u += min(n, tot);
	}
	pf("%d %d\n", u, v);
	
	return 0;
}