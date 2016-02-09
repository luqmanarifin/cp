#include <iostream>
#include <fstream>
#include <cstdlib>
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
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORD(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORM(i,n) FORM(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define db (double)
#define X first
#define Y second

const int N = 100000;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

struct data {
	int value;
	data() : value(0) {}
};

vector< pair<LL, pair<LL, int > > > kopi;
map<LL, data> num;
LL i = 0, a;

int find(LL b, int j) {
	if(num[b].value) return num[b].value;
	else {
		while(!(kopi[j].X <= b && b <= kopi[j].Y.X)) j++;
		LL temp = (b - kopi[j].X + 1)%kopi[j].Y.Y;
		num[b].value = find(temp? temp : kopi[j].Y.Y, 0);
		return num[b].value;
	}
}

int main(void)
{
	int m;
	sf("%d", &m);
	while(m--) {
		int x; sf("%d", &x);
		if(x == 1) {
			sf("%d", &x);
			i++;
			num[i].value = x;
		} else {
			int l, c;
			sf("%d %d", &l, &c);
			kopi.push_back( mp(i+1, mp(i+ (l*c), l)) );
			i += l*c;
		}
	}
	int n; sf("%d", &n); i = 0;
	while(n--) {
		cin >> a;
		if(num[a].value) pf("%d ", num[a].value);
		else {
			while(!(kopi[i].X <= a && a <= kopi[i].Y.X)) i++;
			LL temp = (a - kopi[i].X + 1)%kopi[i].Y.Y;
			num[a].value = find(temp? temp : kopi[i].Y.Y, 0);
			pf("%d ", num[a].value);
		}
	}
	nl;
	
	return 0;
}