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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int next[N], prev[N], n;
char s[N];

int lepaskan(int pos) {
	int r = next[next[pos]];
	int l = prev[pos];
	next[l] = r;
	prev[r] = l;
	if(l == 0 || r == n + 1) return l;
	if(s[l] == s[r]) return lepaskan(l);
	return l;
}

int main(void)
{
	sf("%s", &s[1]);
	n = strlen(&s[1]);
	int i;
	FOR(i, 0, n) next[i] = i + 1;
	FOR(i, 1, n+1) prev[i] = i - 1;
	bool ada = 1;
	while(ada && next[0] != n + 1) {
		ada = 0;
		for(i = next[0]; i <= n && next[i] <= n; i = next[i])
			if(s[i] == s[next[i]])
				i = lepaskan(i), ada = 1;
	}
	if(next[0] == n + 1) puts("Yes");
	else puts("No");
	return 0;
}
