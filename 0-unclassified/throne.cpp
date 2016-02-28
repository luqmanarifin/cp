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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int cnt[26], now[26];

int main(void)
{
	int i, j;
	char s[N];
	sf("%s", s);
	int n = strlen(s);
	cout << n << endl;
	FORS(i, n) cnt[s[i]-'a']++;
	FORS(i, n/2) now[s[i]-'a']++;
	FORS(i, n) {
		if(n & 1) cnt[s[i]-'a']--;
		now[s[i]-'a']--;
		now[ s[(i+n/2)%n] -'a']++;
		bool valid = 1;
		FORS(j, 26) {
			if(2*now[j] != cnt[j]) {
				valid = 0;
				pf("%d %d\n", i, j);
				break;
			}
		}
		if(valid) {
			puts("YES");
			return 0;
		}
		if(n & 1) cnt[s[i]-'a']++;
	}
	puts("NO");
	return 0;
}
