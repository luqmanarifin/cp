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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

#define x first
#define y second
pair<int,int> num[N];

int main(void)
{
	//open;
	int t;
	sf("%d", &t);
	while(t--) {
		int i, j, n;
		sf("%d", &n);
		FORS(i, n) sf("%d %d", &num[i].x, &num[i].y);
		sort(num, num + n);
		int ans = 0;
		FORS(i, n) {
			ans++;
			int to = num[i].y;
			while(i + 1 < n && num[i+1].x <= to) {
				i++;
				to = min(to, num[i].y);
			}
		}
		pf("%d\n", ans);
	}
	
	//close;
	return 0;
}
