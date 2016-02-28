#include <bits/stdc++.h>

// сука блять...
// it was so close, but i can't implement it on time
// maybe next time i must code properly without any bugs

using namespace std;

const int inf = 1e9;
const int N = 2e5 + 5;

struct rmq {
public:
  rmq(int _n) : n(_n) {
    num.resize(n << 2);
    build(1, 0, n - 1);
  }
  void update(int l, int r, int val) {
    _update(1, 0, n - 1, l, r, val);
  }
  int find(int l, int r) {
    return _find(1, 0, n - 1, l, r);
  }
private:
  void build(int p, int l, int r) {
    num[p] = inf;
    if(l == r) {
      return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
  }
  void _update(int p, int l, int r, int ll, int rr, int val) {
    if(ll <= l && r <= rr) {
      num[p] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if(ll <= mid) {
      _update(p << 1, l, mid, ll, rr, val);
    }
    if(mid < rr) {
      _update(p << 1 | 1, mid + 1, r, ll, rr, val);
    }
    num[p] = min(num[p << 1], num[p << 1 | 1]);
  }
  int _find(int p, int l, int r, int ll, int rr) {
    if(ll <= l && r <= rr) {
      return num[p];
    }
    int mid = (l + r) >> 1, ret = inf;
    if(ll <= mid) {
      ret = min(ret, _find(p << 1, l, mid, ll, rr));
    }
    if(mid < rr) {
      ret = min(ret, _find(p << 1 | 1, mid + 1, r, ll, rr));
    }
    return ret;
  }
  int n;
  vector<int> num;
};

struct rmq_max {
public:
  rmq_max(int _n) : n(_n) {
    num.resize(n << 2);
    build(1, 0, n - 1);
  }
  void update(int l, int r, int val) {
    _update(1, 0, n - 1, l, r, val);
  }
  int find(int l, int r) {
    return _find(1, 0, n - 1, l, r);
  }
private:
  void build(int p, int l, int r) {
    num[p] = -inf;
    if(l == r) {
      return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
  }
  void _update(int p, int l, int r, int ll, int rr, int val) {
    if(ll <= l && r <= rr) {
      num[p] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if(ll <= mid) {
      _update(p << 1, l, mid, ll, rr, val);
    }
    if(mid < rr) {
      _update(p << 1 | 1, mid + 1, r, ll, rr, val);
    }
    num[p] = max(num[p << 1], num[p << 1 | 1]);
  }
  int _find(int p, int l, int r, int ll, int rr) {
    if(ll <= l && r <= rr) {
      return num[p];
    }
    int mid = (l + r) >> 1, ret = -inf;
    if(ll <= mid) {
      ret = max(ret, _find(p << 1, l, mid, ll, rr));
    }
    if(mid < rr) {
      ret = max(ret, _find(p << 1 | 1, mid + 1, r, ll, rr));
    }
    return ret;
  }
  int n;
  vector<int> num;
};

vector<int> p;

int id(int a) {
  return lower_bound(p.begin(), p.end(), a) - p.begin();
}

char s[N][5];
int a[N];
bool done[N];

int main() {
  int n, m, junk;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d %d %s", &junk, a + i, s[i]);
    p.push_back(a[i]);
  }
  sort(p.begin(), p.end());
  p.resize(distance(p.begin(), unique(p.begin(), p.end())));
  
  rmq upp(p.size());
  rmq_max lef(p.size());
  for(int i = 0; i < m; i++) {
    int idx = id(a[i]);
    if(done[idx]) {
      puts("0");
      continue;
    }
    if(s[i][0] == 'L') {
      int l = idx, r = p.size();
      while(l < r) {
        int mid = (l + r) >> 1;
        if(upp.find(idx, mid) <= idx) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      //cerr << "binser " << l << endl;
      // nggak ada yg nge block
      if(l == p.size()) {
        printf("%d\n", n + 1 - a[i]);
        lef.update(idx, idx, m);
      } else {
        //cerr << "jancok " << p[l] << endl;
        printf("%d\n", p[l] - a[i]);
        lef.update(idx, idx, l - 1);
      }
    } else {
      int l = -1, r = idx;
      while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(lef.find(mid, idx) >= idx) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      //cerr << "binser " << l << endl;
      // nggak ada yg nge block
      if(l == -1) {
        printf("%d\n", a[i]);
        upp.update(idx, idx, 0);
      } else {
        //cerr << "jancok " << p[l] << endl;
        printf("%d\n", a[i] - p[l]);
        upp.update(idx, idx, l + 1);
      }
    }
    done[idx] = 1;
  }
  
  return 0;
}
