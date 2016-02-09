#include <bits/stdc++.h>

/**
 * Codeforces Round #283 (Div. 2)
 * Problem : E
 * Luqman Arifin (kadalbonek)
 * بسم الله الرحمان الرحيم
 */

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

struct Play {
	Play(int b, int e, int i) : begin(b), end(e), index(i) {};
	int begin;
	int end;
	int index;
};

struct Actor {
	Actor(int c, int b, int e, int i) : cap(c), begin(b), end(e), index(i) {};
	int cap;
	int begin;
	int end;
	int index;
};

bool operator < (const Play &a, const Play &b) {
	if(a.begin != b.begin) return a.begin < b.begin;
	if(a.end != b.end) return a.end < b.end;
	return a.index < b.index;
}

bool operator < (const Actor &a, const Actor &b) {
	if(a.begin != b.begin) return a.begin < b.begin;
	if(a.end != b.end) return a.end < b.end;
	if(a.cap != b.cap) return a.cap < b.cap;
	return a.index < b.index;
}

set<Play> parts;
vector<Actor> ada;
int ans[N];

int main(void)
{
	int i, j, n, m;
	sf("%d", &n);
	FORS(i, n) {
		int a, b;
		sf("%d %d", &a, &b);
		parts.insert(Play(a, b, i));
	}
	sf("%d", &m);
	FORS(i, m) {
		int a, b, cap;
		sf("%d %d %d", &a, &b, &cap);
		ada.push_back(Actor(cap, a, b, i));
	}
	sort(ada.begin(), ada.end());
	FORS(i, m) {
		if(parts.empty()) break;
		int kali = ada[i].cap;
		Play temp = Play(ada[i].begin, 0, 0);
		set<Play>::iterator it = parts.lower_bound(temp);
		while(it != parts.end()) {
			//pf("%d %d %d %d\n", ada[i].begin, it->begin, it->end, ada[i].end);
			if(kali == 0 || ada[i].end < it->begin) {
				break;
			}
			bool del = false;
			set<Play>::iterator toErase;
			if(it->end <= ada[i].end) {
				kali--;
				ans[it->index] = ada[i].index;
				toErase = it;
				del = true;
			}
			it++;
			if(del) {
				parts.erase(toErase);
			}
		}
	}
	if(!parts.empty()) {
		puts("NO");
	} else {
		puts("YES");
		FORS(i, n) pf("%d ", ans[i] + 1); nl;
	}
	
	return 0;
}
