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
const double PI = acos(-1.0);

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

#define x first
#define y second
#define OUT { puts("NO"); continue; }

typedef pair<int,int> Point;
typedef pair<Point, Point> Line;

Line num[3];

bool isValid(Line a, Line b) {
	if(a.y.x - a.x.x && b.y.x - b.x.x) {
		double ma = (double) (a.y.y - a.x.y)/(a.y.x - a.x.x);
		double ca = a.x.y - 1LL*ma*a.x.x;
		double mb = (double) (b.y.y - b.x.y)/(b.y.x - b.x.x);
		double cb = b.x.y - 1LL*mb*b.x.x;
		double intersect = (double) (cb - ca)/(ma - mb);
		double lef = min(a.x.x, a.y.x);
		double rig = max(a.x.x, a.y.x);
		if(intersect < lef || rig < intersect) return 0;
		double shortest = min(intersect - lef, rig - intersect);
		if(shortest*5 < rig - lef) return 0;
		return 1;
	} else if (b.y.x - b.x.x) {
		double mb = (double) (b.y.y - b.x.y)/(b.y.x - b.x.x);
		double cb = b.x.y - 1LL*mb*b.x.x;
		double intersect = mb*a.y.x + cb;
		double lef = min(a.x.y, a.y.y);
		double rig = max(a.x.y, a.y.y);
		if(intersect < lef || rig < intersect) return 0;
		double shortest = min(intersect - lef, rig - intersect);
		if(shortest*5 < rig - lef) return 0;
		return 1;
	} else if (a.y.x - a.x.x) {
		double ma = (double) (a.y.y - a.x.y)/(a.y.x - a.x.x);
		double ca = a.x.y - 1LL*ma*a.x.x;
		double intersect = b.x.x;
		double lef = min(a.x.x, a.y.x);
		double rig = max(a.x.x, a.y.x);
		if(intersect < lef || rig < intersect) return 0;
		double up = max(b.x.y, b.y.y);
		double down = min(b.x.y, b.y.y);
		double high = ma*intersect + ca;
		if(high < down || up < high) return 0;
		double shortest = min(intersect - lef, rig - intersect);
		if(shortest*5 < rig - lef) return 0;
		return 1;
	} else return 0;
}

bool isPair(Line a, Line b) {
	Point aa = a.x;
	Point bb = a.y;
	Point cc = b.x;
	Point dd = b.y;
	return  (aa == cc || aa == dd || bb == cc || bb == dd);
}

double degree(Point A, Point B, Point C) {
	LL b = 1LL*(A.x - C.x)*(A.x - C.x) + 1LL*(A.y - C.y)*(A.y - C.y);
	LL a = 1LL*(B.x - C.x)*(B.x - C.x) + 1LL*(B.y - C.y)*(B.y - C.y);
	LL c = 1LL*(A.x - B.x)*(A.x - B.x) + 1LL*(A.y - B.y)*(A.y - B.y);
	return acos((a - b + c)/(2*(DB) sqrt(a)*sqrt(c)));
}

int main(void)
{
	int t, i; sf("%d", &t);
	while(t--) {
		FORS(i, 3)
			sf("%d %d %d %d", &num[i].x.x, &num[i].x.y, &num[i].y.x, &num[i].y.y);
		if(isPair(num[1], num[2])) swap(num[0], num[2]);
		else if(isPair(num[0], num[2])) swap(num[1], num[2]);
		if(!isPair(num[0], num[1])) OUT
		
		if(num[0].y == num[1].y) {
			swap(num[0].x, num[0].y);
			swap(num[1].x, num[1].y);
		} else if(num[0].x == num[1].y)
			swap(num[1].x, num[1].y);
		else if(num[1].x == num[0].y)
			swap(num[0].x, num[0].y);
			
		double teta = degree(num[0].y, num[0].x, num[1].y);
		if(!(0 < teta && teta < (DB) PI/2)) OUT

		if(isValid(num[0], num[2]) && isValid(num[1], num[2]))
			puts("YES");
		else
			puts("NO");
	}
	
	return 0;
}
