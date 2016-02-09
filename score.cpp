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
#define nl printf("\n")

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

struct item {
	int ac, time, num, tried[15];
	bool done[15], ada;
};

item team[105];

bool cmp(item l, item r) {
	if(l.ac != r.ac) return l.ac > r.ac;
	if(l.time != r.time) return l.time < r.time;
	return l.num < r.num;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	bool first = 1;
	int tt, i, j;
	cin >> tt;
	cin.ignore();
	cin.ignore();
	while(tt--) {
		FORS(i, 105) {
			team[i].ac = 0;
			team[i].time = 0;
			team[i].ada = 0;
			FORS(j, 15) {
				team[i].done[j] = 0;
				team[i].tried[j] = 0;
			}
		}
		string temp;
		getline(cin, temp);
		while(temp.length() > 0) {
			stringstream ss(temp);
			int id, prob, t;
			char ver;
			ss >> id >> prob >> t >> ver;
			team[id].ada = 1;
			team[id].num = id;
			if(!team[id].done[prob]) {
				if(ver == 'C') {
					team[id].ac++;
					team[id].time += t + 20 * team[id].tried[prob];
					team[id].done[prob] = 1;
				} else if(ver == 'I') {
					team[id].tried[prob]++;
				}
			}
			
			getline(cin, temp);
		}
		vector<item> now;
		FORS(i, 105) if(team[i].ada) now.push_back(team[i]);
		sort(now.begin(), now.end(), cmp);
		int sz = (int) now.size();
		if(!first) nl;
		FORS(i, sz) {
			printf("%d %d %d\n", now[i].num, now[i].ac, now[i].time);
		}
		first = 0;
	}
	
	return 0;
}
