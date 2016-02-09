#include <bits/stdc++.h>

/** 
 * Codeforces Round #271 (Div. 2)
 * Problem : C
 * بسم الله الرحمان الرحيم
 */

typedef long long LL;

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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

typedef pair<int,int> pii;
#define X first
#define Y second

pii rot(pair<pii,pii> tt, int pos) {
	int x = tt.X.X;
	int y = tt.X.Y;
	int a = tt.Y.X;
	int b = tt.Y.Y;
	int dx = a - x;
	int dy = y - b;
	if(pos == 0) {
		return mp(a - dx, b + dy);
	}
	if(pos == 1) {
		return mp(a - dy, b - dx);
	}
	if(pos == 2) {
		return mp(a + dx, b - dy);
	}
	return mp(a + dy, b + dx);
}

int i, j, k, l;
pair<pii,pii> tes[4];

LL dist(pii a, pii b) {
	return 1LL*(a.X - b.X)*(a.X - b.X) + 1LL*(a.Y - b.Y)*(a.Y - b.Y);
}

bool isSame(vector<LL> a, vector<LL> b) {
	int ii, jj;
	FORS(ii, 4) {
		if(a[ii] != b[ii]) return 0;
	}
	return 1;
}

bool rect(vector<pii> points) {
	int ii, jj;
	vector<LL> dis;
	bool allZero = 1;
	FORS(jj, 4) {
		LL cur = dist(points[0], points[jj]);
		dis.push_back(cur);
		if(cur) allZero = 0;
	}
	if(allZero) return 0;
	sort(dis.begin(), dis.end());
	/*
	if(i == 0 && j == 0 && k == 1 && l == 0) {
		pf("dist ");
		FORS(ii, 4) pf("%d ", dis[ii]); nl;
	} */
	if(dis[1] != dis[2] || dis[2]*2 != dis[3]) return 0;
	FOR(ii, 1, 3) {
		vector<LL> temp;
		FORS(jj, 4) {
			temp.push_back(dist(points[ii], points[jj]));
		}
		sort(temp.begin(), temp.end());
		/*
		if(i == 0 && j == 0 && k == 1 && l == 0) {
			pf("temp ");
			FORS(ii, 4) pf("%d ", temp[ii]); nl;
		} */
		if(!isSame(dis, temp)) return 0;
	}
	return 1;
}

int isRec() {
	vector<pii> temp;
	temp.push_back(rot(tes[0], i));
	temp.push_back(rot(tes[1], j));
	temp.push_back(rot(tes[2], k));
	temp.push_back(rot(tes[3], l));
	/*
	if(i == 0 && j == 0 && k == 1 && l == 0) {
		puts("tempat : ");
		pf("%d %d\n", rot(tes[0], i).X, rot(tes[0], i).Y);
		pf("%d %d\n", rot(tes[1], j).X, rot(tes[1], j).Y);
		pf("%d %d\n", rot(tes[2], k).X, rot(tes[2], k).Y);
		pf("%d %d\n", rot(tes[3], l).X, rot(tes[3], l).Y);
	} */
	if(!rect(temp)) return inf;
	return i + j + k + l;
}

int main(void)
{
	int n;
	sf("%d", &n);
	while(n--) {
		int x, y, a, b;
		FORS(i, 4) {
			sf("%d %d %d %d", &x, &y, &a, &b);
			tes[i] = mp(mp(x, y), mp(a, b));
		}
		int ans = inf;
		FORS(i, 4) FORS(j, 4) FORS(k, 4) FORS(l, 4) {
			int cur = isRec();
			if(cur < ans) {
				ans = cur;
				//pf("%d %d %d %d\n", i, j, k, l);
			}
			ans = min(ans, isRec());
		}
		cout << (ans == inf? -1 : ans) << endl;
	}
	
	return 0;
}
