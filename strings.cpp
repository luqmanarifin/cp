#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(cok,n) memset(cok, n, sizeof(cok))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

char in[maxn];
int dp[maxn];
vector<int> init;

int main(void)
{
	int k, n, i, j = 0;
	cin >> k >> in;
	LL ans = 0; 
	n = strlen(in);
	FORS(i, n) {
		if(in[i] == '0') {
			if(in[i] != in[i-1]) j++;
			dp[j]++;
		} else {
			if(!k) ans += 1LL*dp[j] *(dp[j]+1)/2;
			j++; dp[j] = -1;
			init.push_back(j);
		}
	}
	if(!k && dp[j] != -1)
		ans += 1LL*dp[j] *(dp[j]+1)/2;
	
	if(k)
		if(init.size())
			FORS(i, init.size()) {
				if(i + k > init.size())
					break;
				int a = init[i]-1;
				int b = init[i+k-1]+1;
				ans += 1LL*(dp[a]==-1? 1 : (dp[a]+1))*(dp[b]==-1? 1 : (dp[b]+1));
			}

	cout << ans << endl;
	
	return 0;
}
