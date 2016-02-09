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

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

char a[15][15], b[15][15];
int n;

void ver() {
	int i, j;
	FORS(i, n/2) FORS(j, n) swap(a[i][j], a[n-i-1][j]);
}

bool isSame() {
	int i, j;
	FORS(i, n) FORS(j, n) if(a[i][j] != b[i][j]) return 0;
	return 1;
}

int rotate() {
	// return 90 if 90 degree to right
	// return 180 if 180 degree to right
	// return 270 if 270 degree to right
	bool same; int i, j;
	
	same = 1;
	FORS(i, n) FORS(j, n) if(a[i][j] != b[j][n-1-i]) same = 0;
	if(same) return 90;
	
	same = 1;
	FORS(i, n) FORS(j, n) if(a[i][j] != b[n-1-i][n-1-j]) same = 0;
	if(same) return 180;
	
	same = 1;
	FORS(i, n) FORS(j, n) if(a[i][j] != b[n-1-j][i]) same = 0;
	if(same) return 270;
	
	return 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	int i, j, tt = 0;
	while(cin >> n) {
		FORS(i, n) cin >> a[i] >> b[i];
		pf("Pattern %d was ", ++tt);
		if(isSame()) {
			pf("preserved.\n");
			continue;
		}
		int rot = rotate();
		if(rot) {
			pf("rotated %d degrees.\n", rot);
			continue;
		}
		ver();
		if(isSame()) {
			pf("reflected vertically.\n");
			continue;
		}
		rot = rotate();
		if(rot) {
			pf("reflected vertically and rotated %d degrees.\n", rot);
			continue;
		}
		pf("improperly transformed.\n");
	}
	
	return 0;
}
