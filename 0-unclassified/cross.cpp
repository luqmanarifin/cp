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
#define open freopen("crosswords.in","r",stdin); freopen("crosswords.out","w",stdout)
#define close fclose(stdin); fclose(stdout)

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

char s[55][55];
bool yoi[55][55];

bool clue(int i, int j) {
	if(s[i][j] != '.') return 0;
	if((i == 0 || s[i-1][j] == '#') && s[i+1][j] == '.' && s[i+2][j] == '.') return 1;
	if((j == 0 || s[i][j-1] == '#') && s[i][j+1] == '.' && s[i][j+2] == '.') return 1;
	return 0;
}

int main(void)
{
	//ios_base::sync_with_stdio(false);
	open;
	int i, j, n, m;
	sf("%d %d", &n, &m);
	FORS(i, n) sf("%s", s[i]);
	int ans = 0;
	FORS(i, n) FORS(j, m) if(clue(i, j)) ans++;
	cout << ans << endl;
	FORS(i, n) FORS(j, m) if(clue(i, j)) pf("%d %d\n", i + 1, j + 1);
	close;
	return 0;
}