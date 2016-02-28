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

int a[1005];

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//open;
	int i, j, n;
	sf("%d", &n);
	while(n) {
		while(true) {
			stack<int> st;
			FORS(i, n) {
				sf("%d", &a[i]);
				if(a[i] == 0) goto NEXT;
				a[i]--;
			}
			i = 0; // kereta masuk
			j = 0;
			while(i < n) {
				while(st.empty() || st.top() != a[j]) {
					st.push(i++);
					if(i == n) break;
				}
				while(!st.empty() && st.top() == a[j]) {
					j++;
					st.pop();
				}
			}
			puts(j == n? "Yes" : "No");
		}
		NEXT:;
		nl;
		sf("%d", &n);
	}
	
	//close;
	return 0;
}