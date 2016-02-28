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

bool mark[105];
vector<int> langu[105], orang[105];
int join = 0, ans;

void dfs(int wong) {
	if(mark[wong]) return;
	mark[wong] = true;
	int a,b;
	if(orang[wong].size())
		FORS(a,orang[wong].size())
			if(langu[orang[wong][a]].size())
				FORS(b, langu[orang[wong][a]].size())
					dfs(langu[orang[wong][a]][b]);
}

int main(void)
{
	int n, m, i, k, x; bool ada = 0;
	sf("%d %d", &n, &m);
	FOR(i,1,n) {
		sf("%d", &k);
		if(k) ada = 1;
		while(k--) {
			sf("%d", &x);
			langu[x].push_back(i);
			orang[i].push_back(x);
		}
	}
	FOR(i,1,n) {
		if(mark[i]) continue;
		dfs(i);
		join++;
	}
	pf("%d\n", ada? join-1 : join);
	
	return 0;
}