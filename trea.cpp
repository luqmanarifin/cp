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

#define modar { puts("-1"); return 0; }

char s[N];
vector<int> ans;

int main(void)
{
	int i, j, n;
	sf("%s", s);
	n = strlen(s);
	int now = 0;
	int a = 0;
	int b = 0;
	FORS(i, n) {
		if(s[i] == '(') now++, a++;
		else if(s[i] == ')') now--, b++;
		else {
			ans.push_back(1);
			now--;
		}
		if(now < 0) modar;
	}
	ans.back() += a - b - ans.size();
	now = 0;
	j = 0;
	FORS(i, n) {
		if(s[i] == '(') now++;
		else if(s[i] == ')') now--;
		else {
			now -= ans[j];
			j++;
		}
		if(now < 0) modar;
	}
	FORS(i, ans.size()) pf("%d\n", ans[i]);
	return 0;
}
