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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

#define x first
#define y second

typedef pair<int,int> Point;

Point a[3];

int dis(Point c, Point b) {
	return (c.x - b.x)*(c.x - b.x) + (c.y - b.y)*(c.y - b.y);
}

bool triangle(Point b, Point c, Point d) {
	if(b == c || b == d || c == d) return 0;
	if(dis(b, c) + dis(b, d) == dis(c, d)) return 1;
	if(dis(b, c) + dis(c, d) == dis(b, d)) return 1;
	if(dis(b, d) + dis(c, d) == dis(b, c)) return 1;
	return 0;
}

int main(void)
{
	int i, j;
	FORS(i, 3) sf("%d %d", &a[i].x, &a[i].y);
	if(triangle(a[0], a[1], a[2])) {
		puts("RIGHT");
		return 0;
	}
	FORS(i, 3) {
		Point asu[4];
		asu[0] = mp(a[i].x + 1, a[i].y);
		asu[1] = mp(a[i].x - 1, a[i].y);
		asu[2] = mp(a[i].x, a[i].y + 1);
		asu[3] = mp(a[i].x, a[i].y - 1);
		FORS(j, 4) 
			if(triangle(asu[j], a[(i+1)%3], a[(i+2)%3])) {
				puts("ALMOST");
				return 0;
			}
	
	}
	puts("NEITHER");
	return 0;
}
