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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[105], sum;
vector<pair<int,int> > op;

int main(void)
{
	int n, k, i, j, maks = -1, mini = inf, maxp, minp;
	sf("%d %d", &n, &k);
	FORS(i, n) {
		sf("%d", &a[i]);
		sum += a[i];
		if(a[i] > maks) {
			maks = a[i];
			maxp = i;
		}
		if(a[i] < mini) {
			mini = a[i];
			minp = i;
		}
	}
	int goal = !!(sum % n);
	while(maks - mini != goal && k--) {
		op.push_back(mp(maxp, minp));
		a[maxp]--, a[minp]++;
		maks = -1;
		mini = inf;
		FORS(i, n) {
			if(a[i] > maks) {
				maks = a[i];
				maxp = i;
			}
			if(a[i] < mini) {
				mini = a[i];
				minp = i;
			}
		}
	}
	int sz = (int) op.size();
	pf("%d %d\n", maks - mini, sz);
	FORS(i, sz) pf("%d %d\n", op[i].first + 1, op[i].second + 1);
	
	return 0;
}
