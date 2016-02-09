#include <bits/stdc++.h>
#include <iomanip>

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

const LL mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int next[maxn], cnt[maxn], ans = 1;

void print(int a) {
	if(next[a]) ans++, print(next[a]);
	else cout << ans << endl;
	pf("%d %d\n", a, cnt[a]);
}

int main(void)
{
	char s[maxn];
	sf("%s", &s[1]);
	int n = strlen(&s[1]);
	int i, j = 0; reset(next, 0); reset(cnt, 0);
	FOR(i,2,n) {
		while(j && s[i] != s[j + 1]) j = next[j];
		if(s[i] == s[j + 1]) j++;
		next[i] = j; 
	}
	FORD(i,n,1) {
		cnt[i]++;
		cnt[next[i]] += cnt[i];
	}
	print(n);
	
	return 0;
}
