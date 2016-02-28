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

int sama[1005][1005], n, m, k, w, sum[1005];
char a[1005][15][15];
bool done[1005];

int main(void)
{
	sf("%d %d %d %d", &n, &m, &k, &w);
	int i, j;
	FOR(i, 1, k)
		FORS(j, n)
			sf("%s", a[i][j]);
	
	int x, y;
	FOR(i, 1, k-1)
		FOR(j, i+1, k)
			FORS(x, n)
				FORS(y, m)
					if(a[i][x][y] == a[j][x][y]) {
						sama[i][j]++;
						sama[j][i]++;
					}
						
	int maks = -1, start;
	FOR(i, 1, k) {
		sum[i] = 0;
		FOR(j, 1, k) {
			if(i != j)
				sum[i] += sama[i][j];
		}
		if(sum[i] > maks) {
			maks = sum[i];
			start = i;
		}
	}
	
	LL ans = n*m, udah = 1;
	vector<pair<int,int> > jawab;
	jawab.push_back(mp(start, 0));
	done[start] = 1;
	int now = start;
	while(udah < k) {
		int same = -1, sami, sumi, sumu = -1, samj;
		FOR(i, 1, k)
			if(!done[i]) {
				FOR(j, 1, k) {
					if(done[j]) {
						if(sama[i][j] > same) {
							same = sama[i][j];
							sami = i;
							samj = j;
						}
					}
				}
				if(sum[i] > sumu) {
					sumu = sum[i];
					sumi = i;
				}
			}
		if(n*m <= (n*m-same)*w) {
			ans += 1LL*n*m;
			jawab.push_back(mp(sumi, 0));
			now = sumi;
		} else {
			ans += 1LL*(n*m-same)*w;
			jawab.push_back(mp(sami, samj));
			now = sami;
		}
		done[now] = 1;
		udah++;
	}
	cout << ans << endl;
	FORS(i, jawab.size())
		pf("%d %d\n", jawab[i].first, jawab[i].second);
		
	//FOR(i,1,k) { FOR(j,1,k) pf("%d ", sama[i][j]); nl; }
	return 0;
}
