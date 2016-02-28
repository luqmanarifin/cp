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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

LL sum = 0;
int a[N];
vector<int> side[N];

int main(void)
{
	int n, m, i, j;
	sf("%d %d", &n, &m);
	FORS(i,m) {
		sf("%d", &a[i]);
		if(i) {
			sum += abs(a[i] - a[i-1]);
			if(a[i] != a[i-1]) {
				side[a[i]].push_back(a[i-1]);
				side[a[i-1]].push_back(a[i]);
			}
		}
	}
	
	LL ans = sum;
	FOR(i,1,n) {
		if(!side[i].size()) continue;
		sort(side[i].begin(), side[i].end());
		int siz = side[i].size();
		int baru = side[i][siz/2]; // median
		LL cur = sum;
		FORS(j, side[i].size())
			cur -= abs(side[i][j] - i) - abs(side[i][j] - baru);
		ans = min(ans, cur);
	}
	
	cout << ans << endl;
	return 0;
}
