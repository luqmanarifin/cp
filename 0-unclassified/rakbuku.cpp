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

int solve(vector<int> a) {
	if(a.size() <= 2) return 0;
	int i, pos = -1;
	FORS(i, a.size()) pf("%d ", a[i]); nl;
	for(i = 1; i < a.size(); i++) {
		if(i == a.size() - 1 && i & 1) continue;
		if(a[i] < a[pos]) pos = i;
	}
	vector<int> next;
	int bmove = 0;
	for(i = 0; i < a.size(); i++) {
		if(i + 1 == pos) {
			next.push_back(a[i] + (i+2 < a.size()? a[i+2] : 0));
			if(pos & 1) bmove = a[pos];
			else next[0] += a[pos];
			i += 2;
			continue;
		}
		next.push_back(a[i]);
	}
	if(bmove) {
		if(next.size() & 1) next.push_back(bmove);
		else next.back() += bmove;
	}
	return a[pos] + solve(next);
}

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		char s[105];
		sf("%s", s);
		int i, n = strlen(s);
		vector<int> a; 
		a.push_back(0);
		FORS(i, n) {
			if((!i && s[i] == 'B') || (i && s[i-1] != s[i]))
				a.push_back(0);
			a.back()++;
		}
		pf("%d\n", solve(a));
		a.clear();
	}
	return 0;
}