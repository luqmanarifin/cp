#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long dp[N];
char s[100];
int n;
bool done[N];
long long ret;

long long find(int l, int r) {
  if (l > r) return 0;
  return dp[r] - dp[l - 1];
}

int isi_kiri(int l, int r, int val) {
  for (int i = l + 1; i < r && val; i++) {
    if (!done[i]) {
      ret += i;
      done[i] = 1;
      val--;
    }
  }
  return val;
}

int isi_kanan(int l, int r, int val) {
  for (int i = r - 1; i > l && val; i--) {
    if (!done[i]) {
      done[i] = 1;
      val--;
    }
  }
  return val;
}


long long mini(const vector<tuple<int, int, int>>& _a, const vector<tuple<int, int, int>>& _b) {
  long long all = 0;
  memset(done, 0, sizeof(done));
  for (int i = 0; i < _a.size(); i++) {
    int p, q, r;
    tie(p, q, r) = _a[i];
    done[p] = 1;
    all += p;
  }
  for (int i = 0; i < _b.size(); i++) {
    int u, v, w;
    tie(u, v, w) = _b[i];
    done[u] = 1;
  }
  set<tuple<int, int, int>> a, b;
  for (auto it : _a) a.insert(it);
  for (auto it : _b) b.insert(it);
  
  auto it = a.begin();
  auto jt = b.begin();
  ret = 0;
  while (it != a.end() && jt != b.end()) {
    int p, q, r, u, v, w;
    tie(p, q, r) = *it;
    tie(u, v, w) = *jt;
    //printf("%d %d %d - %d %d %d\n", p, q, r, u, v, w);
    if (q <= u) {
      r = isi_kiri(p, q, r);
      assert(r == 0);
      it++;
    } else if (v <= p) {
      jt++;
    } else if (u <= p && q <= v) {
      r = isi_kiri(p, q, r);
      assert(r == 0);
      
      w = isi_kanan(u, p, w);
      
      w = isi_kanan(p, q, w);
      
      if (w) {
        b.insert(make_tuple(q, v, w));
      }
      it++;
      jt++;
    } else if (p <= u && v <= q) {
      w = isi_kanan(u, v, w);
      assert(w == 0);
      r = isi_kiri(p, u, r);
      r = isi_kiri(u, v, r);
      if (r) {
        a.insert(make_tuple(v, q, r));
      }
      it++;
      jt++; 
    } else if (p <= u) {
      r = isi_kiri(p, q, r);
      r = isi_kiri(u, q, r);
      assert(r == 0);
      w = isi_kanan(u, q, w);
      if (w) {
        b.insert(make_tuple(q, v, w));
      }
      it++;
      jt++;
    } else {
      w = isi_kanan(u, p, w);
      w = isi_kanan(p, v, w);
      assert(w == 0);
      r = isi_kiri(p, v, r);
      if (r) {
        a.insert(make_tuple(v, q, r));
      }
      it++;
      jt++;
    }
  }
  while (it != a.end()) {
    int p, q, r;
    tie(p, q, r) = *it;
    isi_kiri(p, q, r);
    it++;
  }
  return all + ret;
}

long long maks(const vector<tuple<int, int, int>>& _a, const vector<tuple<int, int, int>>& _b, int num) {
  vector<tuple<int, int, int>> a, b;
  for (int i = 0; i < _a.size(); i++) {
    int u, v, w;
    tie(u, v, w) = _a[i];
    a.emplace_back(n + 1 - v, n + 1 - u, w);
  }
  for (int i = 0; i < _b.size(); i++) {
    int u, v, w;
    tie(u, v, w) = _b[i];
    b.emplace_back(n + 1 - v, n + 1 - u, w);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long ret = mini(a, b);
  return 1LL * num * (n + 1) - mini(a, b);
}

int main() {
  for (int i = 1; i < N; i++) dp[i] = dp[i - 1] + i;
  int u, v;
  scanf("%d %d %d", &n, &u, &v);
  int last = 0, now = 0;
  vector<tuple<int, int, int>> a, b;
  for (int i = 0; i < u; i++) {
    scanf("%s", s);
    if (s[0] == '?') {
      now++;
    } else {
      int val = atoi(s);
      a.emplace_back(last, val, now);
      now = 0;
      last = val;
    }
  }
  a.emplace_back(last, n + 1, now);
  
  last = 0; now = 0;
  for (int i = 0; i < v; i++) {
    scanf("%s", s);
    if (s[0] == '?') {
      now++;
    } else {
      int val = atoi(s);
      b.emplace_back(last, val, now);
      now = 0;
      last = val;
    }
  }
  b.emplace_back(last, n + 1, now);
  //cout << maks(a, b) << endl;
  printf("%lld %lld\n", mini(a, b), maks(a, b, u));
  printf("%lld %lld\n", mini(b, a), maks(b, a, v));
  return 0;
}
