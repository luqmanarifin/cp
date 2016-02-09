#include <bits/stdc++.h>

/**
 * Codeforces Round #256 (Div. 2)
 * Problem : E
 * Luqman Arifin (kadalbonek)
 */
 
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
const int lim = 1e5;
const int N = 1e6;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<LL> ans;
set<LL> ada;
bool ok;
LL k;
bitset<N + 10> is;
map<LL, vector<LL> > faktor;
map<LL, bool> isPrime;

#define check if(ans.size() >= lim) ok = 1

bool prime(LL num) {
	// identifying prime number with fucking dumb method
	LL i, j; bool ok = 1;
	for(i = 2; i*i <= num; i++)
		if(num % i == 0) {
			ok = 0;
			break;
		}
	return ok;
}

void find(LL num, int id) {
	LL i;
	if(num == 1 || id == k) {
		ans.push_back(num);
		check;
		return;
	}
	if(ok) return;
	if(num <= N) {
		if(!is[num]) {
			cek:;
			FORS(i, k - id) {
				if(ok) return;
				ans.push_back(1);
				check;
			}
			if(ok) return;
			ans.push_back(num);
			check;
			return;
		}
	} else {
		if(binary_search(ada.begin(), ada.end(), num)) {
			if(isPrime[num]) goto cek;
		} else {
			bool prima = prime(num);
			isPrime[num] = prima;
			ada.insert(num);
			if(prima) goto cek;
		}
	}
	
	vector<LL> fact = faktor[num];
	if(fact.empty()) {
		for(i = 1; i*i <= num; i++) {
			if(num % i == 0) {
				fact.push_back(i);
				if(i*i != num) fact.push_back(num/i);
			}
		}
		sort(fact.begin(), fact.end());
		faktor[num] = fact;
	}
	FORS(i, fact.size()) {
		if(ok) return;
		find(fact[i], id + 1);
	}
}

int main(void)
{
	LL x; LL i, j;
	for(i = 2; i <= N; i++) {
		if(!is[i]) {
			if(i*i <= N)
			for(j = i*i; j <= N; j += i)
				is[j] = 1;
		}
	}
	sf("%I64d %I64d", &x, &k);
	find(x, 0);
	FORS(i, min((int) ans.size(), lim))
		pf("%I64d ", ans[i]); nl;
	return 0;
}
