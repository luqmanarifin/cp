#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int task[N];

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//open;
	int i, n, m;
	sf("%d %d", &n, &m);
	while(n || m) {
		reset(task, 0);
		int l, r, t;
		FORS(i, n) {
			sf("%d %d", &l, &r);
			task[l]++;
			task[r]--;
		}
		FORS(i, m) {
			sf("%d %d %d", &l, &r, &t);
			while(l < N) {
				task[l]++;
				if(r >= N) break;
				task[r]--;
				l += t;
				r += t;
			}
		}
		bool ok = 1;
		FOR(i, 0, 1000000) {
			if(i) task[i] += task[i - 1];
			if(task[i] > 1) {
				ok = 0;
				break;
			}
		}
		puts(ok? "NO CONFLICT" : "CONFLICT");
		sf("%d %d", &n, &m);
	}
	
	//close;
	return 0;
}