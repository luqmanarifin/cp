#include <bits/stdc++.h>

/**
 * Codeforces Round #267 (Div. 2)
 * Problem : D
 * Luqman Arifin (kadalbonek)
 */

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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 3e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

#define x first
#define y second

map<string, int> id;
vector<int> par[N];
//string st[N];
int t, ess[N];
pair<LL,LL> memo[N], now;
pair<pair<LL,LL>, int> sou[N];

void norm(string &s) {
	int i, n = s.length();
	FORS(i, n) {
		if('A' <= s[i] && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
	}
}

int get(string s) {
	int temp = id[s], i;
	if(temp) return temp;
	++t;
	//st[t] = s;
	id[s] = t;
	memo[t].y = s.length();
	FORS(i, memo[t].y) if(s[i] == 'r') memo[t].x++;
	return t;
}

void dfs(int pos) {
	memo[pos] = now;
	int i;
	FORS(i, par[pos].size()) {
		int near = par[pos][i];
		if(now < memo[near])
			dfs(near);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	int n, i, j, q;
	cin >> n;
	FORS(i, n) {
		string s;
		cin >> s;
		norm(s);
		ess[i] = get(s);
	}
	cin >> q;
	while(q--) {
		string a, b;
		cin >> a >> b;
		norm(a); norm(b);
		int ida = get(a);
		int idb = get(b);
		par[idb].push_back(ida);
	}
	FOR(i, 1, t) sou[i] = mp(memo[i], i);
	sort(sou + 1, sou + 1 + t);
	FOR(i, 1, t) {
		int upd = sou[i].y;
		now = sou[i].x;
		FORS(j, par[upd].size()) {
			int near = par[upd][j];
			if(now < memo[near])
				dfs(near);
		}
	}
	LL sumr = 0, sumlen = 0;
	FORS(i, n) {
		pair<LL,LL> cur = memo[ess[i]];
		sumr += cur.first;
		sumlen += cur.second;
	}
	pf("%I64d %I64d\n", sumr, sumlen);
	/*
	FOR(i, 1, t) {
		pf("%I64d %I64d ", memo[i].first, memo[i].second);
		cout << st[i] << endl;
	}*/
	return 0;
}
