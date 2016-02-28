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

map<string, int> id;
string st[N];
LL howr[N], len[N];
vector<int> child[N];
int t, ess[N];
bool vis[N];
pair<LL,LL> memo[N];

void norm(string &s) {
	int i, n = s.length();
	FORS(i, n) {
		if('A' <= s[i] && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
	}
}

int get(string s) {
	int temp = id[s];
	if(temp) return temp;
	++t;
	id[s] = t;
	st[t] = s;
	len[t] = s.length();
	int i;
	FORS(i, len[t]) if(s[i] == 'r') howr[t]++;
	return t;
}

pair<LL,LL> dfs(int pos) {
	if(memo[pos].first != -1) return memo[pos];
	if(vis[pos]) return mp(inf, inf);
	vis[pos] = 1;
	pair<LL,LL> now = mp(howr[pos], len[pos]);
	int i;
	FORS(i, child[pos].size()) {
		pair<LL,LL> cur = dfs(child[pos][i]);
		now = min(now, cur);
	}
	return memo[pos] = now;
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
		child[ida].push_back(idb);
	}
	FORS(i, N) memo[i] = mp(-1, -1);
	FOR(i, 1, t) dfs(i);
	while(1) {
		bool valid = 1;
		FOR(i, 1, t) FORS(j, child[i].size()) {
			if(memo[child[i][j]] < memo[i]) {
				valid = 0;
				memo[i] = memo[child[i][j]];
			}
		}
		if(valid) break;
	}
	
	LL sumr = 0, totlen = 0;
	FORS(i, n) {
		pair<LL,LL> cur = dfs(ess[i]);
		sumr += cur.first;
		totlen += cur.second;
	}
	pf("%I64d %I64d\n", sumr, totlen);
	//FOR(i, 1, t) cout << i << ' ' << st[i] << endl;
	
	return 0;
}
