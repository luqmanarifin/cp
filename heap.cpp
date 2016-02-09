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

struct item {
	item(int a, int b, int c) : odd(a), num(b), at(c) {};
	int odd, num, at;
};

bool operator < (item a, item b) {
	return a.odd < b.odd ||
	(a.odd == b.odd && a.num < b.num) ||
	(a.odd == b.odd && a.num == b.num && a.at < b.at);
}

int a[205], cnt[105], pos[105];
vector<item> heap;

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FORS(i, 2*n) {
		sf("%d", a + i);
		cnt[a[i]]++;
	}
	FOR(i, 10, 99) {
		if(cnt[i]) heap.push_back(item(cnt[i] & 1, cnt[i], i));
	}
	sort(heap.begin(), heap.end());
	reverse(heap.begin(), heap.end());
	pos[heap[0].at] = 0;
	//pf("%d %d\n", cnt[heap[0].at], heap[0].at);
	int bef = 0;
	FOR(i, 1, heap.size() - 1) {
		if(heap[i-1].odd) pos[heap[i].at] = (bef ^ 1);
		else pos[heap[i].at] = bef;
		//pf("%d %d\n", cnt[heap[i].at], heap[i].at);
		bef = pos[heap[i].at];
	}
	int cnta = 0, cntb = 0;
	FOR(i, 10, 99) {
		if(cnt[i] == 0) continue;
		if(cnt[i] == 1) {
			if(pos[i]) cnta++;
			else cntb++;
		} else
			cnta++, cntb++;
	}
	cout << cnta*cntb << endl;
	//pf("%d %d\n", cnta, cntb);
	reset(cnt, 0);
	FORS(i, 2*n) {
		if(cnt[a[i]] & 1) pf("%d ", (pos[a[i]] ^ 1) + 1);
		else pf("%d ", pos[a[i]] + 1);
		cnt[a[i]]++;
	}
	nl; return 0;
}
