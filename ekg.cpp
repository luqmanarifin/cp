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

int behind[1005], x, bear;
bool ada[1005];
vector<int> len, awal;

pair<int,bool> dfs(int pos, int id) {
	if(pos == x) bear = id;
	if(behind[pos] == 0) {
		return mp(1, pos != x);
	}
	pair<int,bool> next = dfs(behind[pos], id+1);
	return mp(next.first + 1, next.second && (pos != x));
}

int main(void)
{
	int i, j, n;
	sf("%d %d", &n, &x);
	FOR(i, 1, n) {
		int temp;
		sf("%d", &temp);
		if(temp) behind[temp] = i;
		else awal.push_back(i);
	}
	FORS(i, awal.size()) {
		pair<int,bool> now = dfs(awal[i], 1);
		if(now.second) len.push_back(now.first);
	}
	ada[0] = 1;
	FORS(i, len.size()) {
		vector<int> bakal;
		bakal.clear();
		FOR(j, len[i], n)
			if(ada[j-len[i]] && !ada[j])
				bakal.push_back(j);
		FORS(j, bakal.size())
			ada[bakal[j]] = 1;
	}
	FOR(i, 0, n) if(ada[i]) pf("%d\n", i + bear);
	return 0;
}
