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
const int inf = 2e9;
const int length = 3e4;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int is[length + 5];
vector<int> sieve;

int main(void)
{
	int i, j, l, r, ans = 0;
	sf("%d %d", &l, &r);
	reset(is, 1);
	sieve.push_back(2);
	if(l <= 2 && 2 <= r) ans++;
	for(i = 3; i*i <= r; i += 2) {
		if(is[i]) {
			if(l <= i && i % 4 == 1) ans++;
			sieve.push_back(i);
			if(1LL*i*i*i*i <= r)
				for(j = i*i; j*j <= r; j += i)
					is[j] = 0;
		}
	}
	int lo = max(l, i);
	int hi = min(r, lo + length - 1);
	int len = hi - lo + 1;
	while(lo <= hi) {
		reset(is, 1);
		FORS(i, sieve.size()) {
			int ii = sieve[i];
			if(ii == 2) continue;
			for(j = lo/ii*ii; j <= hi; j += ii) {
				if(j - lo < 0) continue;
				is[j - lo] = 0;
			}
		}
		j = (lo & 1? lo : lo + 1);
		while(j <= hi) {
			if(is[j - lo] && j % 4 == 1) ans++;
			j += 2;
		}
		lo += len;
		hi = min(r, hi + len);
	}
	cout << ans << endl;
	return 0;
}
