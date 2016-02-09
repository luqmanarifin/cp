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
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool unyu(char c) {
	int ih = c - 'a';
	return (0 <= ih && ih <= 25);
}

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		vector<int> big, sm;
		char s[105];
		sf("%s", s);
		int n = strlen(s), i;
		FORS(i, n) {
			if(unyu(s[i])) sm.push_back(s[i] - 'a');
			else big.push_back(s[i] - 'A');
		}
		bool same = 1;
		int gede = (int)big.size();
		int kecil = (int)sm.size();
		if(gede != kecil) same = 0;
		FORS(i, min(gede, kecil)) {
			if(sm[i] != big[i]) {
				same = 0;
			}
			if(!same) break;
		}
		if(!same) pf("TIDAK ");
		puts("SEHAT");
	}
	return 0;
}
