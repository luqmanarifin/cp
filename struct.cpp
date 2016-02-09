#include <bits/stdc++.h>

/**
 * Codeforces Round #256 (Div. 2)
 * Problem : B
 * Luqman Arifin (kadalbonek)
 */
 
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

int tc[26], sc[26];
bool done[105];

int main(void)
{
	char s[105], t[105];
	int i, j;
	sf("%s %s", s, t);
	int ss = strlen(s), tt = strlen(t);
	FORS(i, ss) sc[s[i]-'a']++;	// counter alphabet string s
	FORS(i, tt) tc[t[i]-'a']++;	// counter alphabet string t
	bool sama = 1;
	FORS(i, 26) {
		if(tc[i] > sc[i]) {
			puts("need tree");
			return 0;
		}
		if(tc[i] != sc[i]) sama = 0;
	}
	j = 0;
	FORS(i, tt) {
		while(j < ss && t[i] != s[j]) j++;
		if(j < ss && t[i] == s[j]) {
			done[i] = 1;
			j++;
		}
	}
	bool tomat = 1;
	FORS(i, tt) tomat = (tomat && done[i]);
	if(tomat) {
		puts("automaton");
		return 0;
	}
	if(sama) puts("array");
	else puts("both");
	return 0;
}
