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

#define x first
#define y second
pair<pair<int,int>, pair<int, string> > num[100];

int main(void)
{
	ios_base::sync_with_stdio(false);
	//open;
	int i, j, n, m, t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		string untuk;
		cin >> untuk;
		FORS(i, n) {
			cin >> num[i].y.y >> num[i].y.x >> num[i].x.y >> num[i].x.x;
		}
		sort(num, num + n);
		reverse(num, num + n);
		FORS(i, n) {
			if(num[i].y.y == untuk) {
				break;
			}
		}
		puts(i < m? "YA" : "TIDAK");
	}
	
	//close;
	return 0;
}