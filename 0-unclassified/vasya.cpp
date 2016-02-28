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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int kun[2][105];
int done[2][105];
char home[25];
char away[25];
vector<pair<bool, pair<int,int> > > ans;

int main(void)
{
	int n, i;
	sf("%s %s %d", home, away, &n);
	while(n--) {
		int min, num;
		char ah, card;
		sf("%d %c", &min, &ah);
		while(ah != 'a' && ah != 'h') sf("%c", &ah);
		sf("%d %c", &num, &card);
		while(card != 'y' && card != 'r') sf("%c", &card);
		int id = (ah == 'a');
		if(done[id][num]) continue;
		if(card == 'y') {
			if(kun[id][num]) {
				done[id][num] = 1;
				ans.push_back(mp(id, mp(num, min)));
			} else {
				kun[id][num] = 1;
			}
		} else {
			done[id][num] = 1;
			ans.push_back(mp(id, mp(num, min)));
		}
	}
	FORS(i, ans.size()) {
		pf("%s %d %d\n", ans[i].first? away : home, ans[i].second.first, ans[i].second.second);
	}
	
	return 0;
}
