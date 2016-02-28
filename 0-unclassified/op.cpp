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
const int N = (1 << 20) + 10;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N], b[N], tmp[N];
bool stat[22];
LL inv[22], des[22];

// hurray this is for the first time I wrote my own
// merge algorithm, hope this is will be a nice new start
// though I feel dizzy head now

void merge(int l, int r, int lv) {
	if(lv == 0) return;
	int mid = (l + r) >> 1, i = l, j = mid + 1, cur = 0, t;
	merge(l, mid, lv - 1);
	merge(mid + 1, r, lv - 1);
	// merge two sorted array
	while(i <= mid && j <= r) {
		if(a[i] > a[j]) {
			inv[lv - 1] += mid - i + 1;
			tmp[cur++] = a[j++];
		} else
			tmp[cur++] = a[i++];
	}
	// finishing what doesn't finish yet
	while(i <= mid) tmp[cur++] = a[i++];
	while(j <= r) tmp[cur++] = a[j++];
	// replacing nerd array with the cool array
	FORD(t, r, l) a[t] = tmp[--cur];
}

void mergedes(int l, int r, int lv) {
	if(lv == 0) return;
	int mid = (l + r) >> 1, i = l, j = mid + 1, cur = 0, t;
	mergedes(l, mid, lv - 1);
	mergedes(mid + 1, r, lv - 1);
	while(i <= mid && j <= r) {
		if(b[i] < b[j]) {
			des[lv - 1] += mid - i + 1;
			tmp[cur++] = b[j++];
		} else
			tmp[cur++] = b[i++];
	}
	while(i <= mid) tmp[cur++] = b[i++];
	while(j <= r) tmp[cur++] = b[j++];
	FORD(t, r, l) b[t] = tmp[--cur];
}

int main(void)
{
	int n, i, j, p, q, m;
	sf("%d", &n);
	p = (1 << n);
	FORS(i, p) {
		sf("%d", &a[i]);
		b[i] = a[i];
	}
	merge(0, p - 1, n);
	mergedes(0, p - 1, n);
	sf("%d", &m);
	while(m--) {
		sf("%d", &q);
		FORS(i, q) stat[i] ^= 1;
		LL ans = 0;
		FORS(i, n) ans += (stat[i]? des[i] : inv[i]);
		pf("%I64d\n", ans);
	}
	return 0;
}
