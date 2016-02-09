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

int bit[5005], n;
int bef[5005][5005], aft[5005][5005], a[5005];

void add(int pos) {
	for(; pos <= n; pos |= pos + 1)
		bit[pos]++;
}

int find(int pos) {
	int ret = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
		ret += bit[pos];
	return ret;
}

int main(void)
{
	int i, j;
	sf("%d", &n);
	FORS(i, n) {
		sf("%d", &a[i]);
		FORS(j, n) {
			bef[i][j] = find(n - j);
		}
		add(n - a[i]);
	}
	reset(bit, 0);
	FORM(i, n) {
		FORS(j, n) {
			aft[i][j] = find(j - 1);
		}
		add(a[i]);
	}
	int need = 0;
	FORS(i, n) need += bef[i][a[i]];
	int ans = -1, cnt = -1;
	FORS(i, n) FOR(j, i+1, n-1) {
		int geder = bef[j][a[j]] - bef[i][a[j]];
		int gedel = bef[j][a[i]] - bef[i][a[i]];
		int kecilr = aft[i][a[j]] - aft[j][a[j]];
		int kecill = aft[i][a[i]] - aft[j][a[i]];
		int dif = geder - kecilr + kecill - gedel;
		if(dif > ans) {
			ans = dif;
			cnt = 1;
		} else if(dif == ans)
			cnt++;
	}
	pf("%d %d\n", need - ans, cnt);
	return 0;
}
