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
const int O = 2e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int main(void)
{
	//open;
	LL i, n; LL num[O]; sf("%I64d", &n);
	FORS(i,n) sf("%I64d", &num[i]);
	i = 0; int ans = 0;
	while(i < n) {
		ans++;
		LL a = i;
		while(num[a] == -1) a++;
		LL b = a + 1;
		while(num[b] == -1) b++;
		if((num[b] - num[a])%(b - a)) {
			i = b;
			continue;
		}
		LL dif = (num[b] - num[a])/(b - a);
		if(num[a] - (a - i)*dif < 1) {
			i = b;
			continue;
		}
		LL r = b + 1;
		while(r < n) {
			if(num[r] == -1) {
				if(num[r-1] + dif > 0)
					num[r] = num[r-1] + dif;
				else break;
			} else {
				if(num[r] - num[r-1] != dif)
					break;
			}
			r++;
		}
		i = r;
	}
	
	cout << ans << endl;
	//close;
	return 0;
}
