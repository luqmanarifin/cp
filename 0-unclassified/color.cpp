#include <bits/stdc++.h>

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
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const int inf = 2e9;
const int N5 = 1e5 + 5;
const int N = 1e5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

map<pair<int,int>,bool> ada;
int color[N5], cur[N5];

int main(void)
{
	int n, m, i;
	sf("%d %d", &n, &m);
	FORS(i,N5) cur[i] = -1;
	FOR(i,1,n) {
		sf("%d", &color[i]);
		cur[color[i]] = 0;
	}
	while(m--) {
		int a, b;
		sf("%d %d", &a, &b);
		int aa = color[a];
		int bb = color[b];
		if(aa != bb) {
			if(aa > bb) swap(aa, bb);
			if(!ada[mp(aa,bb)]) {
				cur[aa]++;
				cur[bb]++;
				ada[mp(aa,bb)] = 1;
			}
		}
	}
	
	int ans, now = -1;
	FOR(i,1,N)
		if(cur[i] > now) {
			now = cur[i];
			ans = i;
		}
	cout << ans << endl;
	return 0;
}
