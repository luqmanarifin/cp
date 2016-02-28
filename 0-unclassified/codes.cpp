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

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

char s[55];

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//open;
	while(true) {
		sf("%s", s);
		if(s[0] == '#') break;
		int n = strlen(s), i, j;
		FORD(i, n-2, 0) {
			if(s[i] < s[i+1]) break;
		}
		//cout << i << endl;
		if(i == -1) puts("No Successor");
		else {
			int loc = i + 1;
			FOR(j, i+1, n-1) if(s[i] < s[j]) {
				if(s[j] < s[loc]) loc = j;
			}
			//cout << loc << endl;
			swap(s[loc], s[i]);
			sort(s + i + 1, s + n);
			pf("%s\n", s);
		}
	}
	
	//close;
	return 0;
}