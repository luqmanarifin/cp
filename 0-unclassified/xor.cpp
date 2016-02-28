#include <bits/stdc++.h>
#include <iomanip>

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
#define reset(cok,n) memset(cok, n, sizeof(cok))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int ans[maxn], kelas[maxn], bener[maxn], t = 0;
vector<int> son[maxn];

void dfs(int a, int sta, int flip) {
	int i;
	if(sta) {
		if(son[a].size())
			FORS(i,son[a].size())
				dfs(son[a][i], sta^1, flip);
		return;
	}
	if(flip%2) bener[a] ^= 1;
	int tukar = flip;
	if(!bener[a]) {
		++tukar;
		ans[++t] = a;
	}
	if(son[a].size())
		FORS(i,son[a].size())
			dfs(son[a][i], sta^1, tukar);
}

int main(void)
{
	int n, i; sf("%d", &n);
	reset(kelas, 0);
	kelas[1] = 1;
	FORS(i,n-1) {
		int a, b;
		sf("%d %d", &a, &b);
		if(kelas[a]) {
			kelas[b] = kelas[a] + 1;
			son[a].push_back(b);
		} else {
			kelas[a] = kelas[b] + 1;
			son[b].push_back(a);
		}
	}
	
	FOR(i,1,n) sf("%d", &bener[i]);
	FOR(i,1,n) {
		int x; sf("%d", &x);
		bener[i] = bener[i] == x;
	}
	
	dfs(1,0,0);
	if(son[1].size())
		FORS(i,son[1].size())
			dfs(son[1][i],0,0);
	
	cout << t << endl;
	random_shuffle(ans+1, ans+1+t);
	FOR(i,1,t) pf("%d\n", ans[i]);
	
	return 0;
}
