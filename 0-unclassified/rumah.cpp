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
#define open freopen("rumah.txt","r",stdin); freopen("out1.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 5;
const int N6 = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool row[N], col[N];
int nrow, ncol;
vector<pair<LL, LL> > ans;

int b[N6], a[N6];
pair<LL, LL> will[N6], ansa[N6];
LL w[N6], ten[20];

inline int dig(LL num, int sh) {
	return (num/ten[sh]) % 10;
}

void radix_sort(int n) {
	queue<pair<LL, LL> > q[10];
	int i, j;
	FOR(i, 0, 18) {
		FORS(j, n) {
			q[dig(ans[j].first, i)].push(ans[j]);
		}
		int t = 0;
		FORS(j, 10) {
			while(!q[j].empty()) {
				ans[t++] = q[j].front();
				q[j].pop();
			}
		}
	}
	FOR(i, 0, 10) {
		FORS(j, n) {
			q[dig(ans[j].second, i)].push(ans[j]);
		}
		int t = 0;
		FORM(j, 10) {
			while(!q[j].empty()) {
				ans[t++] = q[j].front();
				q[j].pop();
			}
		}
	}
}

inline bool cmp(pair<LL,LL> lef, pair<LL, LL> rig) {
	if(lef.second != rig.second)
		return lef.second > rig.second;
	return lef.first < rig.first;
}

int main()
{
	//open;
	//clock_t t = clock();
	int i, n, m, q;
	ten[0] = 1;
	FOR(i, 1, 19) ten[i] = ten[i-1]*10;
	sf("%d %d %d", &n, &m, &q);
	
	FORS(i, q) {
		sf("%d %d %lld", &b[i], &a[i], &w[i]);
	}
	
	int v = 0;
	FORM(i, q) {
		if(b[i] == 1) {
			if(row[a[i]]) continue;
			will[v++] = mp(w[i], m - ncol);
			nrow++;
			row[a[i]] = 1;
		} else {
			if(col[a[i]]) continue;
			will[v++] = mp(w[i], n - nrow);
			ncol++;
			col[a[i]] = 1;
		}	
	}
	sort(will, will + v);
	int sz = 0;
	FORS(i, v) {
		//if(will[i].first == 0) continue;
		if(i && will[i].first == will[i-1].first)
			ansa[sz-1].second += will[i].second;
		else
			ansa[sz++] = will[i];
	}
	FORS(i, sz) {
		if(ansa[i].second) ans.push_back(ansa[i]);
	}
	sort(ans.begin(), ans.end(), cmp);
	sz = (int) ans.size();
	pf("%d\n", sz);
	FORS(i, sz) {
		pf("%lld %lld\n", ans[i].first, ans[i].second);
	}
	/*
	t = clock() - t;
	printf ("It took me %lf ms.\n", ((double)t)*1000/CLOCKS_PER_SEC);
	close; */
	return 0;
}
