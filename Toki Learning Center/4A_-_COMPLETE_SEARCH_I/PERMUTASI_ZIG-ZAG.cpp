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

int ans[int(4e5)][10];
int a[10], n;

bool cmp(int l[], int r[]) {
	int i;
	FORS(i, n) {
		if(l[i] != r[i]) {
			return l[i] < r[i];
		}
	}
}

int main(void)
{
	int i, j;
	sf("%d", &n);
	FORS(i, n) a[i] = i + 1;
	int perm = 1, t = 0;
	FOR(i, 1, n) perm *= i;
	while(perm--) {
		bool valid = 1;
		FOR(i, 1, n-2) {
			if((a[i-1] < a[i] && a[i] < a[i+1]) || (a[i-1] > a[i] && a[i] > a[i+1])) {
				valid = 0;
				break;
			}	
		}
		if(valid) {
			FORS(i, n) ans[t][i] = a[i];
			t++;
		}
		next_permutation(a, a + n);
	}
	//sort(ans, ans + t, cmp);
	FORS(i, t) {
		FORS(j, n) pf("%d", ans[i][j]);
		nl;
	}
	
	return 0;
}
