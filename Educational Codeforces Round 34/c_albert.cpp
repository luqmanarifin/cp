#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;

#define newline '\n';
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FAST_IO  ios_base::sync_with_stdio(false)

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;

const int MAXN = 5005;

int n;

vector<int> arr;

bool wrapped[MAXN];

bool is_all_wrapped() {
	for (int i = 0; i < n; ++i) {
		if (!wrapped[i]) return false;
	}
	return true;
}

multiset<int> s;

int N;
int main() {
	cin >> N;
	for (int i = 0 ; i < N; ++i){
		int x;
		cin >> x;
		s.insert(x);
	}
	int cnt = 0;
	while (!s.empty()) {
		int last = *s.begin();
		queue<multiset<int>::iterator> q;
		q.push(s.begin());
		for (auto it = ++s.begin(); it != s.end(); ++it) {
			if (*it > last) {
				last = *it;
				q.push(it);
			}
		}
		while(!q.empty()) {
			multiset<int>::iterator it = q.front(); q.pop();
			s.erase(it);
		}
		++cnt;
	}
	cout << cnt << '\n';
	return 0;
}