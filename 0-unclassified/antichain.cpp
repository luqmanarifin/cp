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
const int O = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

char s[O];
int cnt[O];

int main(void)
{
	cin >> s; int n = strlen(s);
	int i, j = 1; reset(cnt, 0); cnt[1] = 1;
	
	FOR(i,1,n-1) {
		if(s[i] != s[i-1]) j++;
		cnt[j]++;
	}
	if(s[0] == s[n-1]) cnt[1] += cnt[j], j--;
	
	int ans = 0, jack = 0;
	FOR(i,1,j) {
		if(cnt[i] == 1) jack++;
		else {
			ans += jack/2 + 1;
			jack = 0;
		}
	}
	if(cnt[j] == 1) ans += jack/2;
	
	cout << ans << endl;
	return 0;
}
