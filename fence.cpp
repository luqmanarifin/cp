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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int a[10];

bool by(const pair<int,int> &lef, const pair<int,int> &rig) {
	if(lef.first != rig.first) return lef.first < rig.first;
	return lef.second > rig.second;
}

int main(void)
{
	int v, i, minimum = inf, mini;
	sf("%d", &v);
	FOR(i,1,9) {
		sf("%d", &a[i]);
		if(a[i] <= minimum) {
			mini = i;
			minimum = a[i];
		}
	}
	int len = v / a[mini];
	if(len == 0) {
		puts("-1");
		return 0;
	}
	int sisa = v % a[mini];
	vector<int> ans; i = 9;
	while(mini < i) {
		if(a[i] - a[mini] > sisa) {
			i--;
			continue;
		}
		sisa -= a[i] - a[mini];
		ans.push_back(i);
	}
	FORS(i, ans.size()) pf("%d", ans[i]);
	FORS(i, len - ans.size()) pf("%d", mini); nl;
	return 0;
}
