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

LL sum(int n) {
	return (long long) n * (n + 1) / 2;
}

LL get(int l, int r) {
	if(r < l) return 0;
	return sum(r) - sum(l-1);
}

int a[N];

int main(void)
{
	//open;
	int t, i;
	sf("%d", &t);
	while(t--) {
		int n, k;
		sf("%d %d", &n, &k);
		FORS(i, k) sf("%d", &a[i]);
		sort(a, a + k);
		LL tot = 0;
		FORS(i, k) {
			if(i && tot + 1 < a[i-1] + 1) {
				break;
			}
			if(i) tot += get(a[i-1] + 1, a[i] - 1);
			else tot += get(1, a[0] - 1);
		}
		if(tot + 1 < a[k-1] + 1 && a[k-1] < n) {
		
		} else {
			tot += get(a[k-1] + 1, n);
		}
		puts(tot % 2? "Mom" : "Chef");
	}
	
	//close;
	return 0;
}
