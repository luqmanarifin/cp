//I_HAVE_A_DREAM
//E.cpp
//DreamBig
//Sep 16, 2015
#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end();i++)
#define present(c,x)  ( (c).find(x) !=(c).end())
#define cpresent(c,x) (find(all(c),x)!= (c).end() )
#define minei(x)  min_element(x.begin(),x.end())-(x).begin()
#define maxei(x)  max_element(x.begin(),x.end())-(x).begin()

#define uns(v)     sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define acusum(x)  accumulate(x.begin(),x.end(),0)
#define acumul(x)  accumulate(x.begin(),x.end(),1, multiplies<int>()); 
#define bits(x)     __builtin_popcount( x )
#define oo INT_MAX
#define inf 1000000000

const double pi = acos(-1.0);
const double eps = 1e-11;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

double calc(vector<double> v, double nm) {
	//negative
	int n = sz(v);
	double mx = 0;
	double cur = 0;
	for (int i = 0; i < n; i++) {
		if (cur < 0) {
			cur = 0;

		}
		cur += (v[i] - nm);
		mx = max(mx, cur);
	}
	cur = 0;
	for (int i = 0; i < n; i++) {
		if (cur > 0) {
			cur = 0;

		}
		cur += (v[i] - nm);
		mx = max(mx, abs(cur));

	}

	return mx;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<double> v(n);

	for (int i = 0; i < n; i++) {
		scanf("%lf", &v[i]);

	}
	double l = -inf, r = inf;
	for (int i = 0; i < 400; i++) {
		double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
		if (calc(v, m1) >= calc(v, m2)) {
			l = m1;
		}
		else
			r = m2;
	}

	cout << fixed;
	cout << setprecision(14);
	cout << min(calc(v, l), calc(v, r)) << endl;

	return 0;
}