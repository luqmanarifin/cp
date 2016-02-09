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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int mask[105], num[105], c[105];
vector<pair<int,int> > card;

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FORS(i, n) {
		char s[4];
		sf("%s", s);
		if(s[0] == 'R') c[i] = 0;
		if(s[0] == 'G') c[i] = 1;
		if(s[0] == 'B') c[i] = 2;
		if(s[0] == 'Y') c[i] = 3;
		if(s[0] == 'W') c[i] = 4;
		num[i] = s[1] - '1';
		card.push_back( mp(c[i], num[i]) );
	}
	sort(card.begin(), card.end());
	card.resize(unique(card.begin(), card.end()) - card.begin());
	n = card.size();
	FORS(i, n) {
		c[i] = card[i].first;
		num[i] = card[i].second;
	}
	
	int ans = inf, tc, tn;
	FORS(tc, (1 << 5))
		FORS(tn, (1 << 5)) {
			vector<int> hints;
			FORS(i, 5)
				if(tc & (1 << i))
					hints.push_back(i);
			FORS(i, 5)
				if(tn & (1 << i))
					hints.push_back(~i);
			int now = hints.size();
			FORS(i, n) {
				mask[i] = 0;
				FORS(j, now) {
					if(hints[j] >= 0) {
						if(hints[j] == c[i])
							mask[i] |= (1 << j);
					} else {
						if(~hints[j] == num[i])
							mask[i] |= (1 << j);
					}
				}
			}
			bool valid = 1;
			sort(mask, mask + n);
			FORS(i, n-1)
				if(mask[i] == mask[i+1]) {
					valid = 0;
					break;
				}
			if(valid && now < ans) {
				ans = now;
			}
		}
	cout << ans << endl;
	return 0;
}
