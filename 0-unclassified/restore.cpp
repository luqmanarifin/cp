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
#define db (double)

const int N = 1000010;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

#define mulih { puts("-1"); return 0; }

map < int, vector<int> > path;
vector<int> before, after;
vector < pair <int, int> > ans;
int n, q, i, k, prev, now, maxi, tmp;

int main()
{
	sf("%d %d", &n, &k);
	FOR(i,1,n) {
		sf("%d", &tmp);
		maxi = max(maxi, tmp);
		path[tmp].push_back(i);
	}
	
	if(path[0].size() != 1) mulih
	now = 1; prev = 0;
	while(path[now].size()) {
		before = path[now-1];
		after = path[now]; 
		if((LL) before.size()*k < (LL) after.size()) mulih
		
		FORS(i,after.size()) 
			ans.push_back( mp(before[i/k], after[i]) );
		
		if(!prev) k--;
		prev++; now++;
	}
	
	if(now <= maxi) mulih
	pf("%d", ans.size()); nl;
	random_shuffle(&ans[0], &ans[ans.size()]);
	FORS(i,ans.size()) 
		pf("%d %d\n", ans[i].first, ans[i].second);
	
	return 0;
}