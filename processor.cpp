#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const int N = 1000010;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int main(void)
{
	int n,m,k,i,j;
	sf("%d %d %d", &n, &m, &k);
	int map[105][105], cell[105], ans[105]; bool locked[105];
	FOR(i,1,n) FOR(j,1,m) sf("%d", &map[i][j]);
	FOR(i,1,m) {
		memset(cell,0,sizeof(cell));
		FOR(j,1,n) 
			if(!ans[j])
				cell[map[j][i]]++;
		FOR(j,1,n) {
			if(locked[map[j][i]] && !ans[j])
				ans[j] = i;
			else if(cell[map[j][i]] > 1 && !ans[j] && map[j][i]) {
				ans[j] = i;
				locked[map[j][i]] = 1;
			}
			//pf("%d %d %d\n",j,i,locked[map[j][i]]);
		}
	}
	FOR(i,1,n) pf("%d\n", ans[i]);
	
	return 0;
}