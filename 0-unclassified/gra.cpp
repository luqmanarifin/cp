// pertama kali ngoding dsu yeyeye
// bismillahirrohmanirrohim

#include <bits/stdc++.h>

/**
 * Codeforces Round #266 (Div. 2) 
 * Problem : E
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
#define open freopen("gra.txt","r",stdin); freopen("out.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int par[N], dad[N], lvl[N];
int s[N], when[N], dead[N];
vector<int> lis;

// disjoint set union + lazy propagation 
int find(int a) {
	//pf("%d paritinya %d\n", a, par[a]);
	if(a == par[a]) {
		lvl[a] = 1;
		return a;
	}
	int d = lvl[a] - lvl[par[a]];
	int root = find(par[a]);
	if(par[a] == dad[a]) {
		lvl[a] = lvl[par[a]] + 1;
	} else {
		lvl[a] = lvl[par[a]] + d;
	}
	return par[a] = root;
}

int main(void)
{
	open;
	int i, j, n, tt, day;
	sf("%d %d", &n, &tt);
	FOR(i, 1, n) par[i] = i;
	int last = 0;
	FORS(day, tt) {
		int type, x, y;
		//pf("day: %d\n", day);
		sf("%d", &type);
		vector<int> now;
		if(type == 1) {
			sf("%d %d", &x, &y);
			vector<int> upd;
			FORS(i, lis.size()) {
				int id = lis[i];
				if(dead[id] >= day) {
					if(find(s[id]) == x) {
						upd.push_back(id);
					}
					now.push_back(id);
				}
			}
			lis = now;
			dad[x] = y;
			par[x] = y;
			int root = find(x);
			//puts("gukguk");
			int d = lvl[x] - lvl[root];
			FORS(i, upd.size()) {
				int id = upd[i];
				dead[id] += d;
			}
		} else if(type == 2) {
			++last;
			sf("%d", &x);
			s[last] = x;
			when[last] = day;
			int root = find(x);
			int d = lvl[x] - lvl[root];
			dead[last] = day + d;
			lis.push_back(last);
		} else {
			bool found = 0;
			sf("%d %d", &x, &y);
			if(find(x) == find(s[y])) {
				int t = dead[y] - when[y];
				int v = lvl[s[y]] - lvl[x];
				pf("%d %d\n", t, v);
				if(t == v) {
					found = 1;
				}
			}
			puts(found? "YES" : "NO");
		}
		//FOR(i, 1, n) pf("par %d : %d\n", i, find(i));
	}
	FOR(i, 1, 8) {
		int root = find(i);
		pf("%d lvl : %d\n", i, lvl[i]);
	}
	close;
	return 0;
}
