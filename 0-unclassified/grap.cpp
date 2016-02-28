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
const int N = 3e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

#define x first
#define y second
pair<int, pair<int,int> > edge[N]; 
vector<pair<int,int> > st;
int len[N];

int main(void)
{
	int n, m, i, j;
	sf("%d %d", &n, &m);
	FORS(i, m) {
		int a, b, w;
		sf("%d %d %d", &a, &b, &w);
		edge[i] = mp(w, mp(a, b));
	}
	sort(edge, edge + m);
	int last = -1;
	FORS(i, m) {
		if(edge[i].x > last) {
			FORS(j, st.size()) {
				len[st[j].x] = max(len[st[j].x], st[j].y);
			}
			st.clear();
			last = edge[i].x;
		}
		st.push_back(mp(edge[i].y.y, len[edge[i].y.x] + 1));
	}
	FORS(j, st.size()) {
		len[st[j].x] = max(len[st[j].x], st[j].y);
	}
	int ans = -1;
	FOR(i, 1, n) if(len[i] > ans) ans = len[i];
	cout << ans << endl;
	return 0;
}
