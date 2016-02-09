#include <bits/stdc++.h>

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

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool solve(vector<int> p) {
	int i, j, n = p.size();
	if(p[0] & 1) {
		for(i = 0; i < n - 1 - i; i++)
			swap(p[i], p[n - 1 - i]);
	}
	int where[n];
	FORS(i, n) where[p[i]] = i;
	
	int limit = n / 2 - 6;
	if(limit*2 <= (n + 1)/2) {
		FORS(i, n-1)
			FOR(j, i+1, n-1) {
				int need = 2*p[j] - p[i];
				if(0 <= need && need < n && where[need] > j)
					return true;
			}
		return false;
	}
	
	FORS(i, limit) {
		if(p[i] & 1)
			return true;
		if(p[n - 1 - i] % 2 == 0)
			return true;
	}
	FOR(i, limit, n - 1 - limit)
		FOR(j, i + 1, n - 1 - limit) {
			int need = 2*p[j] - p[i];
			if(0 <= need && need < n && where[need] > j)
				return true;
			need = 2*p[i] - p[j];
			if(0 <= need && need < n && where[need] < i)
				return true;
			}
	vector<int> odd, even;
	FORS(i, n) {
		int now = p[i] >> 1;
		if(p[i] & 1)
			odd.push_back(now);
		else
			even.push_back(now);
	}
	return (solve(odd) || solve(even));
}

int main(void)
{
	vector<int> v;
	int i, junk;
	sf("%d", &junk);
	FORS(i, junk) {
		int x;
		sf("%d", &x);
		v.push_back(x - 1);
	}
	puts(solve(v)? "YES" : "NO");
	return 0;
}
