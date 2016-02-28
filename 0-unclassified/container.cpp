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
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int main(void)
{
	int i = 0, j, n, bef = 0;
	sf("%d", &n);
	while(i < n) {
		vector<pair<int,int> > now;
		int a = 1;
		while(a) {
			if(i == n) {
				FOR(j, bef, n-1)
					puts("pushBack");
				return 0;
			}
			sf("%d", &a);
			if(a) now.push_back(mp(a,i));
			i++;
		}
		if(now.empty()) {
			puts("0");
			bef = i;
			continue;
		}
		sort(now.begin(), now.end());
		reverse(now.begin(), now.end());
		vector<int> it;
		FORS(j, min(3, (int)now.size())) {
			it.push_back(now[j].second);
		}
		sort(it.begin(), it.end());
		if(it.size() == 1) {
			puts("pushStack");
			puts("1 popStack");
		} else if(it.size() == 2) {
			puts("pushStack");
			puts("pushFront");
			puts("2 popStack popFront");
		} else {
			FOR(j, bef, it[0]) puts("pushStack");
			FOR(j, it[0]+1, it[1]) puts("pushFront");
			FOR(j, it[1]+1, it[2]-1) puts("pushBack");
			FOR(j, it[2], i-2) puts("pushQueue");
			puts("3 popStack popFront popQueue");
		}
		bef = i;
	}
	
	return 0;
}
