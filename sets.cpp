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

int now, ans[N], num[N];
map<int, int> cnt;
map<int, bool> ada;

int main(void)
{
	int n, a, b, i, j;
	sf("%d %d %d", &n, &a, &b);
	FORS(i, n) {
		sf("%d", num + i);
		cnt[num[i]]++;
	}
	FORS(i, n) {
		if(num[i] < a && num[i] < b) {
			if(cnt[a - num[i]] && cnt[b - num[i]] && cnt[num[i]] == 1) {
				puts("NO");
				return 0;
			}
		}
		//puts("gukguk");
		bool udah = 0;
		bool dob = (num[i] < a && num[i] < b && cnt[a - num[i]] && cnt[b - num[i]]);
		if(dob) {
			udah = 1;
			if(ada[num[i]]) ans[i] = 1;
			else ada[num[i]] = 1;
		} else {
			if(num[i] < a && cnt[a - num[i]]) udah = 1;
			if(num[i] < b && cnt[b - num[i]]) {
				udah = 1;
				ans[i] = 1;
			}
		}
		if(!udah) {
			puts("NO");
			return 0;
		}
		
	}
	puts("YES");
	FORS(i, n) pf("%d ", ans[i]); nl;
	return 0;
}
