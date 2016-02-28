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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<LL> ans;
LL res = INF, l, r;

bool valid(LL a) {
	return (l <= a && a <= r);
}

void cek_satu() {
	res = l;
	ans.clear();
	ans.push_back(l);
}

void cek_dua() {
	LL i, j;
	FOR(i, l, r) {
		if(i == r) continue;
		res = i^(i + 1);
		ans.clear();
		FOR(j, i, i+1) {
			ans.push_back(j);
		}
		if(res == 1) return;
	}
}

void cek_tiga() {
	LL will[10], i;
	FORS(i, 3) will[i] = i + 1;
	while(will[0] <= r) {
		bool ok = 1;
		FORS(i, 3) ok = (ok && valid(will[i]));
		if(ok) {
			res = 0;
			ans.clear();
			FORS(i, 3) ans.push_back(will[i]);
			return;
		}
		FORS(i, 3) {
			will[i] <<= 1;
			if(i < 2) will[i] |= 1;
		}
	}
}

void cek_empat() {
	LL i, j;
	FOR(i, l, r) {
		if(i % 2 == 0 && i + 3 <= r) {
			res = 0;
			FOR(j, i, i + 3)
				ans.push_back(j);
			break;
		}
	}
}
int main(void)
{
	LL k, i, j;
	sf("%I64d %I64d %I64d", &l, &r, &k);
	if(k == 1) res = l, ans.push_back(l);
	else if(k == 2) {
		cek_dua();
		if(l < res) cek_satu();
	} else if(k == 3) {
		cek_tiga();
		if(res) cek_dua();
		if(l < res) cek_satu();
	} else {
		cek_empat();
		if(res) cek_tiga();
		if(res) cek_dua();
		if(l < res) cek_satu();
	}
	cout << res << endl << ans.size() << endl;
	FORS(i, ans.size()) pf("%I64d ", ans[i]); nl;
	return 0;
}
