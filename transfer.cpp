#include <bits/stdc++.h>

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

const LL mod = 1e9+7;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

vector<int> num;

int main(void)
{
	int i, x, n, t, c, ans = 0;
	sf("%d %d %d", &n, &t, &c);
	FOR(i,1,n) {
		sf("%d", &x);
		if(x > t) num.push_back(i);
	}

	if(num.size()) {
		if(c < n + 1 - num[num.size()-1])
			ans += n + 1 - num[num.size()-1] - c;
		if(c < num[0]) ans += num[0] - c;
		FOR(i,1,num.size()-1)
			if(c < num[i] - num[i-1])
				ans += num[i] - num[i-1] - c;
	}
	else ans += n + 1 - c;
	
	cout << ans << endl;
	
	return 0;
}