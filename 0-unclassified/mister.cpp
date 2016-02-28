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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char s[N];

struct fenwick {
public:
	fenwick(int _n) : n(_n) {
		a.resize(n);
	};
	void flip(int pos) {
		if(s[pos] == '(') {
			add(pos, -2);
			s[pos] = ')';
		}
		else {
			add(pos, 2);
			s[pos] = '(';
		}
	}
	void add(int pos, int val) {
		for(; pos <= n; pos |= pos + 1)
			a[pos] += val;
	}
	int find(int pos) {
		int ret = 0;
		for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
			ret += a[pos];
		return ret;
	}
	bool check() {
		int i, now = 0;
		FORS(i, n) {
			if(s[i] == '(') now++;
			else now--;
			if(now < 0) return false;
		}
		return true;
	}
private:
	vector<int> a;
	int n;
};

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		sf("%s", s);
		int n = strlen(s), type, pos, i;
		fenwick fen(n);
		FORS(i, n) {
			if(s[i] == '(') fen.add(i, 1);
			else fen.add(i, -1);
		}
		while(1) {
			sf("%d", &type);
			if(type == -1) break;
			if(type) {
				sf("%d", &pos);
				fen.flip(pos);
			}
			else {
				if(fen.find(n-1) == 0) {
					if(fen.check()) pf("Y");
					else pf("T");
				}
				else pf("T");
			}
		}
		nl;
	}
	return 0;
}
