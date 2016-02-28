#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>

using namespace std;

#define LL long long
#define DB double
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORD(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORM(i,n) FORD(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define muat first
#define init second

const int N = 1000010;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

struct group {
	int money;
	int people;
	int init;
};

bool byMoney(const group &lhs, const group &rhs) {
	return lhs.money > rhs.money;
}

bool byMuat(const pair<int,int> &lhs, const pair<int,int> &rhs) {
	return lhs.muat < rhs.muat;
}

group guest[1005];
int k;
pair<int,int> r[1005];
vector< pair<int,int> > ans;
LL uang = 0;
bool mark[1005];

int main(void)
{
	int n, i, j; sf("%d", &n);
	FORS(i,n) {
		sf("%d %d", &guest[i].people, &guest[i].money);
		guest[i].init = i+1;
	}
	sf("%d", &k);
	FORS(i,k) {
		sf("%d", &r[i].muat);
		r[i].init = i+1;
	}
	sort(guest, guest+n, byMoney);
	sort(r, r+k, byMuat);
	
	FORS(i,k) { // table has i, then guest has j
		FORS(j,n) {
			if(r[i].muat >= guest[j].people && !mark[j]) {
				uang += guest[j].money;
				ans.push_back( mp(guest[j].init, r[i].init) );
				mark[j]++;
				break;
			}
		}
	}
	
	pf("%d %I64d\n", ans.size(), uang);
	if(ans.size()) {
		random_shuffle(ans.begin(), ans.end());
		FORS(i,ans.size()) 
			pf("%d %d\n",ans[i].first, ans[i].second);
	}
	return 0;
}