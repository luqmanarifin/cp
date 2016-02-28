#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 1e5 + 5;

struct rmq {
public:
  rmq(int _n) : n(_n){
    num.resize((n + 1) << 2);
    build(1, 0, n);
  }
  void update(int at, int val) {
    _update(1, 0, n, at, val);
  }
  int get(int l, int r) {
    return _get(1, 0, n, l, r);
  }
private:
  void build(int p, int l, int r) {
    if(l == r) {
      num[p] = inf;
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    num[p] = min(num[p + p], num[p + p + 1]);
  }
  void _update(int p, int l, int r, int at, int val) {
    if(l == r) {
      num[p] = min(num[p], val);
      return;
    }
    int mid = (l + r) >> 1;
    if(at <= mid) {
      _update(p + p, l, mid, at, val);
    } else {
      _update(p + p + 1, mid + 1, r, at, val);
    }
    num[p] = min(num[p + p], num[p + p + 1]);
  }
  int _get(int p, int l, int r, int ll, int rr) {
    if(ll <= l && r <= rr) return num[p];
    if(r < ll || rr < l) return inf;
    int mid = (l + r) >> 1;
    return min(_get(p + p, l, mid, ll, rr), _get(p + p + 1, mid + 1, r, ll, rr)); 
  }
  vector<int> num;
  int n;
};

char s[N];
vector<pair<int, int>> alt;
int safe[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    alt.clear();
    
    int n, k;
    scanf("%d %d %s", &n, &k, s + 1);
    for(int i = 1; i <= n; i++) {
      int j = i;
      while(j + 1 <= n && s[j] != s[j + 1]) j++;
      for(int k = i; k <= j; k++) {
        safe[k] = i - 1;
      }
      i = j;
    }
  
    rmq dp(n);
    dp.update(0, 0);
    for(int i = 1; i <= n; i++) {
      dp.update(i, dp.get(i - 1, i - 1) + 1);
      int l = max(1, i - k + 1);
      if(l <= safe[i]) {
        dp.update(i, dp.get(l - 1, safe[i] - 1) + 1);
      }
    }
    printf("%d\n", dp.get(n, n) - 1);
  }
  
  return 0;
}
