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
const double eps = 1e-13;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> num;
int cnt[N];
LL lef[N];
LL rig[N];

int main(void)
{
	int i, j, n;
	sf("%d", &n);
	FORS(i, n) {
		int a;
		sf("%d", &a);
		num.push_back(a);
		cnt[a]++;
	}
	sort(num.begin(), num.end());
	num.resize(distance(num.begin(), unique(num.begin(), num.end())));
	if(num.size() <= 2) {
		puts("Slavko");
		pf("%d %d\n", num[0], num.back());
		return 0;
	}
	LL now = 0;
	FORS(i, num.size()) {
		now += cnt[num[i]];
		lef[i+1] = now;
		lef[i+1] += lef[i];
	}
	now = 0;
	FORM(i, num.size()) {
		now += cnt[num[i]];
		rig[i+1] = now;
		rig[i+1] += rig[i+2];
	}
	//FOR(i, 0, 3) pf("%I64d ", lef[i]); nl;
	//FOR(i, 0, 3) pf("%I64d ", rig[i]); nl;
	FORS(j, num.size()-1) {
		i = j + 1;
		if(lef[i-1] == rig[i+2]) {
			puts("Slavko");
			pf("%d %d\n", num[i-1], num[i]);
			break;
		} else if(lef[i-1] < rig[i+2]) {
			if(lef[i] > rig[i+2]) {
				puts("Slavko");
				pf("%d %d\n", num[i-1], num[i]);
				break;
			}
		} else { // if(lef[i-1] > rig[i+2])
			if(lef[i-1] < rig[i+1]) {
				puts("Mirko");
				pf("%d %d", num[i-1], num[i]);
				break;
			}
		}
	}
	
	return 0;
}
