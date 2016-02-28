#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 3e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int ans[N];

int main(void)
{
	int n, m, i;
	sf("%d %d", &n, &m);
	set<int> alive;
	FOR(i, 1, n) 
		alive.insert(i);
		
	while(m--) {
		int l, r, x;
		sf("%d %d %d", &l, &r, &x);
		set<int>::iterator it = alive.lower_bound(l);
		vector<int> toErase;
		while(it != alive.end()) {
			int cur = *it;
			if(cur > r) break;
			if(cur != x) {
				toErase.push_back(cur);
				ans[cur] = x;
			}
			it++;
		}
		FORS(i, toErase.size())
			alive.erase(toErase[i]);
	}
	
	FOR(i, 1, n) pf("%d ", ans[i]); nl;
	
	return 0;
}
