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

int dist[26][26];
char a[N], b[N];
vector<pair<int,int> > edge[26];

int main(void)
{
	int i, j, n;
	FORS(i, 26) FORS(j, 26) dist[i][j] = inf;
	sf("%s %s %d", a, b, &n);
	FORS(i, n) {
		char x, y, junk[5];
		int val;
		gets(junk);
		sf("%c %c %d", &x, &y, &val);
		if(x != y) edge[x-'a'].push_back(mp(y-'a', val));
	}
	FORS(i, 26) {
		priority_queue<pair<int,int> > pq;
		dist[i][i] = 0;
		pq.push(mp(0, i));
		while(!pq.empty()) {
			int now = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();
			if(cost > dist[i][now]) continue;
			FORS(j, edge[now].size()) {
				int near = edge[now][j].first;
				int ncos = edge[now][j].second;
				if(cost + ncos < dist[i][near]) {
					dist[i][near] = cost + ncos;
					pq.push(mp(-dist[i][near], near));
				}
			}
		}
	}
	char ret[N];
	int lena = strlen(a), lenb = strlen(b);
	LL ans = 0;
	FORS(i, lena) {
		int aa = a[i] - 'a';
		int bb = b[i] - 'a';
		int cost = inf + 5, pos;
		FORS(j, 26) {
			if(1LL*dist[aa][j] + 1LL*dist[bb][j] < cost) {
				cost = dist[aa][j] + dist[bb][j], pos = j;
			}
		}
		ret[i] = pos + 'a';
		ans += cost;
	}
	
	if(ans >= inf || lena != lenb) {
		puts("-1");
		return 0;
	}
	cout << ans << endl;
	FORS(i, lena) pf("%c", ret[i]); nl;
	return 0;
}
