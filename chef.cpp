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

// jumlah pesan, - id

#define x first
#define y second

queue<pair<int,int> > q;
stack<pair<int,int> > s;
priority_queue<pair<int,int> > pq;
bitset<mod> udah;

int main(void)
{
	int tt;
	sf("%d", &tt);
	while(tt--) {
		int a, b, c;
		sf("%d", &a);
		if(a == 0) {
			sf("%d %d", &b, &c);
			q.push(mp(c, -b));
			s.push(mp(c, -b));
			pq.push(mp(c, -b));
		} else if(a == 1) {
			while(udah[-q.front().y]) q.pop();
			udah[-q.front().y] = 1;
			pf("%d\n", -q.front().y);
			q.pop();
		} else if(a == 2) {
			while(udah[-s.top().y]) s.pop();
			udah[-s.top().y] = 1;
			pf("%d\n", -s.top().y);
			s.pop();
		} else if(a == 3) {
			while(udah[-pq.top().y]) pq.pop();
			udah[-pq.top().y] = 1;
			pf("%d\n", -pq.top().y);
			pq.pop();
		}
	}
	
	return 0;
}
