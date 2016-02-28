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
#define open freopen("joke.in","r",stdin); freopen("joke.out","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char s[200000];
int len, n;
set<char> done;
vector<char> num;

bool go(int i) {
	if(i == len) {
		//cout << num.size() << endl;
		FORS(i, num.size()) pf("%d ", num[i]); nl;
		return 1;
	}
	char v = s[i] - '0';
	if(s[i] != '0' && i + 1 < len) {	// 2 digit
		v = v * 10 + s[i+1] - '0';
		if(v <= n && done.find(v) == done.end()) {
			done.insert(v);
			num.push_back(v);
			if(go(i + 2)) return 1;
			done.erase(done.find(v));
			num.pop_back();
		}
	}
	v = s[i] - '0';
	if(done.find(v) != done.end() || v == 0 || v > n) return 0;
	done.insert(v);
	num.push_back(v);
	if(go(i + 1)) return 1;
	done.erase(done.find(v));
	num.pop_back();
	
	return 0;
}

int main(void)
{
	open;
	int i, j;
	sf("%s", s);
	len = strlen(s);
	n = min(len, 9);
	len -= 9;
	if(len > 0) {
		n += len/2;
	}
	len = strlen(s);
	assert(go(0));
	
	close;
	return 0;
}
