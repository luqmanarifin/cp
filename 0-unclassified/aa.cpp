#include <bits/stdc++.h>

using namespace std;

struct fenwick {
public:
	fenwick(int _n) : n(_n) {
		a.resize(n + 1);
		at.resize(n + 1);
	};
	void update(int l, int r, long long val) {
		_update(l, val, val * l);
		_update(r + 1, -val, -val * (r + 1));
	}
	long long find(int l, int r) {
		return _find(r) - _find(l - 1);
	}
private:
	void _update(int pos, long long aval, long long atval) {
		for(; pos <= n; pos |= pos + 1) {
			a[pos] += aval;
			at[pos] += atval;
		}
	}
	long long _find(int pos) {
		int r = pos;
		long long aval = 0, atval = 0;
		for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
			aval += a[pos];
			atval += at[pos];
		}
		return (r + 1) * aval - atval;
	}
	vector<long long> a, at;
	int n;
};

int main() {
  int n, q;
  vector<long long> a;
  scanf("%d %d", &n, &q);
  a.resize(n + 1);
  for(int i = 0; i < n; i++) {
    scanf("%I64d", &a[i]);
    if(i) a[i] += a[i - 1];
  }
  fenwick fen(n);
  while(q--) {
    int l, r, ll, rr;
    long long val;
    scanf("%d %d %I64d %d %d", &l, &r, &val, &ll, &rr);
    fen.update(l, r, val);
    printf("%I64d\n", fen.find(ll, rr) + a[rr] - (ll? a[ll - 1] : 0));
  }
  
  return 0;
}
