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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

pair<int,int> heap[500];
int ans[500];
bool a[205], b[205];

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FORS(i, 2*n) {
		int x;
		sf("%d", &x);
		heap[i] = mp(x, i);
	}
	sort(heap, heap + 2*n);
	int cnta = 0, cntb = 0;
	FORS(i, 2*n) {
		ans[heap[i].second] = i % 2 + 1;
		if(i & 1) {
			if(!a[heap[i].first]) cnta++;
			a[heap[i].first] = 1;
		} else {
			if(!b[heap[i].first]) cntb++;
			b[heap[i].first] = 1;
		}
	}
	pf("%d %d\n", cnta, cntb);
	cout << cnta*cntb << endl;
	FORS(i, 2*n) pf("%d ", ans[i]); nl;
	return 0;
}
