#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

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

const LL mod = 200003;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 160000;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

LL fact[N], ifact[N];
int a[15], b[15];

LL power(LL a, LL b) {
	if(b == 0) return 1LL;
	LL temp = power(a, b/2);
	temp *= temp;
	temp %= mod;
	if(b & 1) {
		temp *= a;
		temp %= mod;
	}
	return temp;
}

LL inv(LL a) {
	return power(a, mod - 2);
}

LL c(LL n, LL k) {
	if(n < 0 || k < 0 || n < k) return 0;
	LL temp = fact[n] * ifact[k];
	temp %= mod;
	temp *= ifact[n - k];
	temp %= mod;
	return temp;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	//open;
	int i, j, t;
	fact[0] = ifact[0] = 1;
	FOR(i, 1, N-1) {
		fact[i] = fact[i-1] * i;
		fact[i] %= mod;
		ifact[i] = inv(fact[i]);
	}
	sf("%d", &t);
	while(t--) {
		int n, k;
		sf("%d %d", &n, &k);
		FORS(i, n) {
			sf("%d %d", &a[i], &b[i]);
			k -= a[i];
			b[i] -= a[i];
			a[i] -= a[i];
			//pf("disini %d %d\n", a[i], b[i]);
		}
		//cout << k << endl;
		int pol = (1 << n), mask;
		LL ans = 0;
		FORS(mask, pol) {
			int popcount = 0, elim = 0;
			FORS(i, n) {
				if((1 << i) & mask) {
					popcount++;
					elim += b[i] + 1;
				}
			}
			int bola = k - elim;
			LL now = c(bola + n - 1, bola);
			if(popcount & 1) {
				ans -= now;
				if(ans < 0) ans += mod;
			} else {
				ans += now;
				if(ans >= mod) ans -= mod;
			}
		}
		pf("%d\n", (int) ans);
	}
	
	//close;
	return 0;
}