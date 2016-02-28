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

struct score {
	int ac;
	int time;
};

struct team {
	string name;
	bool done[10];
	int tried[10];
	score log[301];
};

inline bool cmp(team l, team r) {
	int i;
	FORD(i, 300, 1) {
		if(l.log[i].ac != r.log[i].ac) return l.log[i].ac > r.log[i].ac;
		if(l.log[i].time != r.log[i].time) return l.log[i].time < r.log[i].time;
	}
	return l.name < r.name;
}

inline bool same(team l, team r) {
	int i;
	FORD(i, 300, 1) {
		if(l.log[i].ac != r.log[i].ac) return 0;
		if(l.log[i].time != r.log[i].time) return 0;
	}
	return 1;
}

team a[55];
map<string, int> m;

int main(void)
{
	ios_base::sync_with_stdio(false);
	int t, i, j, n, q, qq;
	cin >> t;
	while(t--) {
		m.clear();
		cin >> n >> q;
		FORS(i, 55) {
			FORS(j, 10) {
				a[i].done[j] = 0;
				a[i].tried[j] = 0;
			}
			FORS(j, 301) {
				a[i].log[j].ac = 0;
				a[i].log[j].time = 0;
			}
		}
		FOR(i, 1, n) {
			cin >> a[i].name;
			m[a[i].name] = i;
		}
		FOR(qq, 1, q) {
			int time;
			string nama, verdi;
			char prob;
			cin >> time >> nama >> prob;
			while(prob < 'A' || 'J' < prob) cin >> prob;
			prob -= 'A';
			cin >> verdi;
			
			int id = m[nama];
			if(a[id].done[prob]) continue;
			if(verdi[0] == 'a') {
				a[id].done[prob] = 1;
				int add = time + 20 * a[id].tried[prob];
				a[id].log[time].ac++;
				a[id].log[time].time += add;
			} else a[id].tried[prob]++;
		}
		FOR(i, 1, n) FOR(j, 1, 300) {
			a[i].log[j].ac += a[i].log[j - 1].ac;
			a[i].log[j].time += a[i].log[j - 1].time;
		}
		
		sort(a + 1, a + 1 + n, cmp);
		int last;
		FOR(i, 1, n) {
			if(i == 1 || !same(a[i], a[i - 1])) last = i;
			cout << last << ' ' << a[i].name << ' ';
			cout << a[i].log[300].ac << ' ' << a[i].log[300].time << '\n';
		}
	}
	
	return 0;
}
