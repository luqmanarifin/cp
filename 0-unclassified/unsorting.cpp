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

int a[N], d[N], n;
pair<int,int> s[N];

void next(int &i, int &j) {
	if(j == n - 1) {
		i++;
		j = i + 1;
	} else j++;
}

#define x first
#define y second

int main(void)
{
	int i, j;
	sf("%d", &n);
	FORS(i, n) {
		sf("%d", &a[i]);
		d[i] = s[i].x = a[i];
		s[i].y = i;
		
	}
	sort(s, s + n);
	sort(d, d + n);
	reverse(d, d + n);
	if(d[0] == d[n - 1] || n <= 2) {
		puts("-1");
		return 0;
	}
	bool ok = 1;
	i = 0, j = 0;
	int posi = 0, posj = 0, t;
	while(ok) {
		swap(a[posi], a[posj]);
		next(i, j);
		while(s[i].x == s[j].x && i < n) next(i, j);
		if(i == n - 1) break;
		posi = s[i].y, posj = s[j].y;
		swap(a[posi], a[posj]);
		bool des = 1, asc = 1;
		FORS(t, n) {
			if(a[t] != s[t].x)
				asc = 0;
			if(a[t] != d[t])
				des = 0;
		}
		ok = asc || des;
	}
	if(ok) puts("-1");
	else pf("%d %d\n", posi + 1, posj + 1);
	return 0;
}
