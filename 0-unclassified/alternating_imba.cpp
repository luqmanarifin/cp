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

// alternating = string selang seling
// one element segment is alternating string 
struct is_alternating_segtree {
public:
  // *s is one-indexed
  is_alternating_segtree(char* _s) {
    s = _s;
    n = strlen(s + 1);
    //puts("taek");
    num.resize(n << 2);
    build(1, 1, n);
  }
  int get(int l, int r) {
    return _get(1, 1, n, l, r);
  }
private:
  void build(int p, int l, int r) {
    //printf("%d %d %d\n", p, l, r);
    if(l == r) {
      num[p] = 1;
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    num[p] = num[p + p] && num[p + p + 1] && s[mid] != s[mid + 1];
  }
  int _get(int p, int l, int r, int ll, int rr) {
    if(ll <= l && r <= rr) return num[p];
    int mid = (l + r) >> 1;
    if(ll <= mid && mid < rr) {
      return _get(p + p, l, mid, ll, rr) && _get(p + p + 1, mid + 1, r, ll, rr) && s[mid] != s[mid + 1];
    }
    if(ll <= mid) {
      return _get(p + p, l, mid, ll, rr);
    }
    if(mid < rr) {
      return _get(p + p + 1, mid + 1, r, ll, rr);
    }
    puts("JANCOK");
  }
  vector<int> num;
  int n;
  char* s;
};

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, k;
    scanf("%d %d %s", &n, &k, s + 1);
    
    rmq dp(n);
    is_alternating_segtree is(s);
    
    dp.update(0, 0);
    for(int i = 1; i <= n; i++) {
      int l = max(1, i - k + 1), r = i;
      dp.update(i, dp.get(i - 1, i - 1) + 1);
      while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(is.get(mid, i)) {
          r = mid - 1;
        } else {
          l = mid;
        }
      }
      if(!is.get(l, i)) {
        dp.update(i, dp.get(max(1, i - k + 1) - 1, l - 1) + 1);
      }
      //printf("ini %d : %d\n", i, dp.get(i, i));
    }
    printf("%d\n", dp.get(n, n) - 1);
  }
  
  return 0;
}
