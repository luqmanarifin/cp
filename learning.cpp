#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("learning.in","r",stdin); freopen("learning.out","w",stdout)
#define close fclose(stdin); fclose(stdout)

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 5e4 + 5;
const int pol = 1e9;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

vector<pair<int,int> > good, sip;
pair<int,int> cow[N];

#define x first
#define y second

int main(void)
{
	//ios_base::sync_with_stdio(false);
	open;
	int n, a, b, i;
	sf("%d %d %d", &n, &a, &b);
	FORS(i, n) {
		char s[5];
		int w;
		sf("%s %d", s, &w);
		cow[i] = mp(w, strlen(s) == 1);
	}
	sort(cow, cow + n);
	FORS(i, n) {
		if(cow[i].second) {
			if(i == 0) good.push_back(mp(1, cow[i].x));
			else {
				if((cow[i].x + cow[i-1].x) & 1)
					good.push_back(mp((cow[i].x + cow[i-1].x)/2 + 1, cow[i].x));
				else
					good.push_back(mp((cow[i].x + cow[i-1].x)/2, cow[i].x));
			}
			if(i == n-1) good.push_back(mp(cow[i].x, pol));
			else good.push_back(mp(cow[i].x, (cow[i].x + cow[i+1].x)/2));
		}
	}
	
	if(!good.empty()) sort(good.begin(), good.end());
	FORS(i, good.size()) if(i && good[i].x == good[i-1].y) good[i].x++;
	FORS(i, good.size()) if(good[i].x <= good[i].y) sip.push_back(good[i]);
	//FORS(i, sip.size()) pf("%d %d\n", sip[i].x, sip[i].y);
	int pos = inf;
	if(!sip.empty()) pos = lower_bound(sip.begin(), sip.end(), mp(a, a)) - sip.begin();
	if(pos) pos--;
	int sz = (int) sip.size();
	int ans = 0;
	FOR(i, pos, sz - 1) {
		if(sip[i].x > b) break;
		int add = min(b, sip[i].y) - max(a, sip[i].x) + 1;
		if(add < 0) add = 0;
		ans += add;
	}
	cout << ans << endl;
	close;
	return 0;
}