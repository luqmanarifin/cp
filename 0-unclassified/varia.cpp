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

stack<pair<pair<int,int>, int> > st[26];

#define x first
#define y second

int main(void)
{
	ios_base::sync_with_stdio(false);
	int i, j, n, line;
	int now = 0;
	cin >> n;
	cin.ignore();
	FOR(line, 1, n) {
		string temp;
		getline(cin, temp);
		int len = temp.length();
		FORS(i, len) {
			if(temp[i] == '{') now++;
			if(temp[i] == '}') {
				FORS(j, 26) {
					while(!st[j].empty() && st[j].top().y == now)
						st[j].pop();
				}
				now--;
			}
			if('a' <= temp[i] && temp[i] <= 'z') {
				int id = temp[i] - 'a';
				if(!st[id].empty()) {
					pf("%d:%d: warning: shadowed declaration of %c, the shadowed position is %d:%d\n",
						line, i + 1, temp[i], st[id].top().x.x, st[id].top().x.y + 1);
				}
				st[id].push(mp(mp(line, i), now));
			}
		}
	}
	
	return 0;
}
