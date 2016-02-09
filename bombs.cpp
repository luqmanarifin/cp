#include <bits/stdc++.h>

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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

typedef pair<int,int> Point;
#define x first
#define y second

Point bombs[N];

LL dist (Point a) {
	return 1LL*a.x*a.x + 1LL*a.y*a.y;
}

bool nearest(Point a, Point b) {
	return dist(a) < dist(b);
}

int main(void)
{
	int n, i, op = 0;
	sf("%d", &n);
	FORS(i, n) {
		sf("%d %d", &bombs[i].x, &bombs[i].y);
		int move;
		if(bombs[i].x && bombs[i].y) move = 2;
		else move = 1;
		op += move*2 + 2;
	}
	sort(bombs, bombs + n, nearest);
	cout << op << endl;
	FORS(i, n) {
		if(bombs[i].x > 0)
			pf("1 %d R\n", bombs[i].x);
		else if(bombs[i].x < 0)
			pf("1 %d L\n", -bombs[i].x);
		if(bombs[i].y > 0)
			pf("1 %d U\n", bombs[i].y);
		else if(bombs[i].y < 0)
			pf("1 %d D\n", -bombs[i].y);
		puts("2");
		
		if(bombs[i].x > 0)
			pf("1 %d L\n", bombs[i].x);
		else if(bombs[i].x < 0)
			pf("1 %d R\n", -bombs[i].x);
		if(bombs[i].y > 0)
			pf("1 %d D\n", bombs[i].y);
		else if(bombs[i].y < 0)
			pf("1 %d U\n", -bombs[i].y);
		puts("3");
	}
	return 0;
}
