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
const int N = 1e6;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool is[N + 5];
int dp[N + 5];
vector<int> prime;

int main(void)
{
	int a, b, k, i, j;
	for(i = 2; i <= N; i++) {
		if(!is[i]) {
			prime.push_back(i);
			dp[i]++;
			if(1LL*i*i <= N)
			for(j = i*i; j <= N; j += i)
				is[j] = 1;
		}
		dp[i] += dp[i-1];
	}
	sf("%d %d %d", &a, &b, &k);
	int l = 1, r = b - a + 1;
	while(l < r) {
		int mid = (l + r) >> 1;
		//pf("%d %d %d\n", l, mid, r);
		bool valid = 1;
		FOR(i, a, b) {
			if(i + mid - 1 > b) break;
			if(dp[i + mid - 1] - dp[i - 1] < k) {
				valid = 0;
				break;
			}
		}
		if(valid) r = mid;
		else l = mid + 1;
	}
	if(dp[b] - dp[a-1] < k) l = -1;
	cout << l << endl;
	return 0;
}
