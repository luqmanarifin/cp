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
const double INF = 4e18;
const int N = 1e5 + 5;
const double eps = 1e-5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

typedef pair<double,double> Point;
#define x first
#define y second

Point node[N];
vector<Point> will, ans;
double A, B;

bool equal(double a, double b) {
	return abs(a - b) < eps;
}

bool les(double a, double b) {
	if(equal(a, b)) return false;
	return a < b;
}

bool more(double a, double b) {
	if(equal(a, b)) return false;
	return a > b;
}

bool moreEqual(double a, double b) {
	if(equal(a, b)) return true;
	return a > b;
}

bool lesEqual(double a, double b) {
	if(equal(a, b)) return true;
	return a < b;
}

// mengembalikan perpotongan suatu titik dengan y = 0
double withO(Point a) {
	return a.x + a.y/2;
}

// mengembalikan perpotongan suatu titik dengan y = A
double withA(Point a) {
	return a.x + abs(A - a.y)/2;
}

// mengembalikan perpotongan suatu titik dengan y = B
double withB(Point a) {
	return a.x + abs(B - a.y)/2;
}

bool o_near(Point a, Point b) {
	return withO(a) < withO(b);
}

bool a_near(Point a, Point b) {
	return withA(a) < withA(b);
}

bool b_near(Point a, Point b) {
	return withB(a) < withB(b);
}

bool ratain(Point a, Point b) {
	return a.y < b.y;
}

bool intersect(Point a, Point b) {
	double terus = a.x + abs(a.y - b.y)/2;
	return more(terus, b.x);
}

// Point i yg bawah, Point j yg atas
Point cut(Point i, Point j) {
	double ci = i.y - 2*i.x;
	double cj = j.y + 2*j.x;
	double yy = (ci + cj)/2;
	double xx = (yy - ci)/2;
	return mp(xx, yy);
}

double cal(Point a, Point b) {
	return (a.x + b.x)/2*abs(a.y - b.y);
}

double calc() {
	if(ans.empty()) return INF;
	double ret = 0;
	int i;
	FOR(i, 1, ans.size()-1)
		ret += cal(ans[i-1], ans[i]);
	return ret;
}

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		int n, i, j, k;
		sf("%d %lf %lf", &n, &A, &B);
		FORS(i, n) {
			sf("%lf %lf", &node[i].x, &node[i].y);
			node[i].x /= 2;
		}
		
		will.clear();
		ans.clear();
		sort(node, node + n, o_near);
		FORS(i, n) {
			if(will.empty()) will.push_back(node[i]);
			else {
				if(intersect(will.back(), node[i]))
					will.push_back(node[i]);
			}
		}
		FORS(i, will.size()) {
			if(more(will[i].y, B)) {
				if(ans.empty()) ans.push_back(mp(withB(will[i]), B));
				else {
					if(les(withB(will[i]), withB(ans.back())))
						ans.push_back(mp(withB(will[i]), B));
				}
				break;
			}
			if(lesEqual(will[i].y, A)) continue;
			if(ans.empty() && i && les(withA(will[i-1]), withA(will[i]))) {
				ans.push_back(mp(withA(will[i-1]), A));
			}
			ans.push_back(will[i]);
		}
		if(ans.empty()) {
			ans.push_back(mp(withA(will.back()), A));
		}
		int last = ans.size() - 1;
		FOR(i, 1, ans.size() - 1) {
			ans.push_back(cut(ans[i-1], ans[i]));
			if(i == last) break;
		}
		if(more(ans[0].y, A)) {
			ans.push_back(mp(withA(ans[0]), A));
		}
		if(les(ans[last].y, B)) {
			ans.push_back(mp(withB(ans[last]), B));
		}
		sort(ans.begin(), ans.end(), ratain);
		pf("%.15f\n", calc());
	}
	return 0;
}
