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

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl cout << '\n'

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int main(void)
{
	ios_base::sync_with_stdio(false);
	vector<int> num;
	int n;
	while(cin >> n) {
		num.push_back(n);
		int sz = (int) num.size();
		int pol = sz - 1;
		while(pol > 0 && num[pol-1] > num[pol]) {
			swap(num[pol-1], num[pol]);
			pol--;
		}
		if(sz & 1) {
			cout << num[sz / 2];
		} else {
			cout << (num[sz / 2] + num[sz / 2 - 1]) / 2;
		}
		nl;
	}
	
	return 0;
}
