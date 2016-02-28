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
int lcm(int a, int b) { return a*b / gcd(a, b); }

map<pair<int,int>, bool> ada, udah;
int n;
bool mau = 1;
vector<int> atas, bawah, kanan, kiri;
pair<int,int> now, cur;
vector<pair<int,int> > start, finish;

void dfs(int x, int y) {
	if(!mau) return;
	if(x == 1 || y == n) {
		mau = 0;
		return;
	}
	udah[mp(x,y)] = 1;
	if(x < cur.first) cur = mp(x, y);
	if(y > now.second) now = mp(x, y); 
	if(ada[mp(x - 1, y + 1)] && !udah[mp(x - 1, y + 1)])
		dfs(x - 1, y + 1);
	if(ada[mp(x, y + 1)] && !udah[mp(x, y + 1)])
		dfs(x, y + 1);
	if(ada[mp(x - 1, y)] && !udah[mp(x - 1, y)])
		dfs(x - 1, y);
		
	if(ada[mp(x - 1, y - 1)] && !udah[mp(x - 1, y - 1)])
		dfs(x - 1, y - 1);
	if(ada[mp(x + 1, y + 1)] && !udah[mp(x + 1, y + 1)])
		dfs(x + 1, y + 1);
	if(ada[mp(x, y - 1)] && !udah[mp(x, y - 1)])
		dfs(x, y - 1);
	if(ada[mp(x + 1, y)] && !udah[mp(x + 1, y)])
		dfs(x + 1, y);
	if(ada[mp(x + 1, y - 1)] && !udah[mp(x + 1, y - 1)])
		dfs(x + 1, y - 1);
}

void dfs2(int x, int y) {
	if(!mau) return;
	if(x == n || y == 1) {
		mau = 0;
		return;
	}
	udah[mp(x,y)] = 1;
	if(x > cur.first) cur = mp(x, y);
	if(y < now.second) now = mp(x, y);
	
	if(ada[mp(x + 1, y - 1)] && !udah[mp(x + 1, y - 1)])
		dfs2(x + 1, y - 1);
	if(ada[mp(x, y - 1)] && !udah[mp(x, y - 1)])
		dfs2(x, y - 1);
	if(ada[mp(x + 1, y)] && !udah[mp(x + 1, y)])
		dfs2(x + 1, y);
		
	if(ada[mp(x - 1, y - 1)] && !udah[mp(x - 1, y - 1)])
		dfs2(x - 1, y - 1);
	if(ada[mp(x + 1, y + 1)] && !udah[mp(x + 1, y + 1)])
		dfs2(x + 1, y + 1);
	if(ada[mp(x, y + 1)] && !udah[mp(x, y + 1)])
		dfs2(x, y + 1);
	if(ada[mp(x - 1, y)] && !udah[mp(x - 1, y)])
		dfs2(x - 1, y);
	if(ada[mp(x - 1, y + 1)] && !udah[mp(x - 1, y + 1)])
		dfs2(x - 1, y + 1);
}

int main(void)
{
	int i, m, j;
	sf("%d %d", &n, &m);
	while(m--) {
		int a, b;
		sf("%d %d", &a, &b);
		if(b == 1) kiri.push_back(a);
		if(a == n) bawah.push_back(b);
		if(a == 1) atas.push_back(b);
		if(b == n) kanan.push_back(a);
		ada[mp(a,b)] = 1;
	}
	FORS(i, kiri.size()) {
		now = mp(n, 1);
		cur = mp(n, 1);
		udah[mp(kiri[i], 1)] = 1;
		dfs(kiri[i], 1);
		start.push_back(now);
		start.push_back(cur);
	}
	FORS(i, bawah.size()) {
		now = mp(n, 1);
		cur = mp(n, 1);
		udah[mp(n, bawah[i])] = 1;
		dfs(n, bawah[i]);
		start.push_back(now);
		start.push_back(cur);
	}
	
	FORS(i, atas.size()) {
		now = mp(1, n);
		cur = mp(1, n);
		udah[mp(1, atas[i])] = 1;
		dfs2(1, atas[i]);
		finish.push_back(now);
		finish.push_back(cur);
	}
	FORS(i, kanan.size()) {
		now = mp(1, n);
		cur = mp(1, n);
		udah[mp(kanan[i], n)] = 1;
		dfs2(kanan[i], n);
		finish.push_back(now);
		finish.push_back(cur);
	}
	FORS(i, start.size())
		FORS(j, finish.size()) {
			if(!mau) goto PRINT;
			#define x first
			#define y second
			if(start[i].y + 1 >= finish[j].y && start[i].x < finish[j].x)
				mau = 0;
			if(start[i].x - 1 <= finish[j].x && start[i].y > finish[j].y)
				mau = 0;
		}
	
	PRINT:;
	if(mau) cout << 2*(n - 1) << endl;
	else puts("-1");
	return 0;
}
