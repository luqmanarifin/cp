#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N][5];

struct Segtree {
public:
  Segtree(int _n, int _m) : n(_n), m(_m) {
    for(int i = 0; i < m; i++) {
      num[i].resize(n << 2);
    }
    build(1, 1, n);
  };
  int find(int i, int l, int r) {
    return cari(1, 1, n, l, r, i);
  }
private:
  void build(int p, int l, int r) {
    if(l == r) {
      for(int i = 0; i < m; i++) {
        num[i][p] = a[l][i];
      }
      return;
    }
    int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
    build(lef, l, mid);
    build(rig, mid + 1, r);
    for(int i = 0; i < m; i++) {
      num[i][p] = max(num[i][lef], num[i][rig]);
    }
  }
  int cari(int p, int l, int r, int ll, int rr, int i) {
    if(l == ll && r == rr) {
      return num[i][p];
    }
    int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
    int ret = -1;
    if(ll <= mid) ret = max(ret, cari(lef, l, mid, ll, min(mid, rr), i));
    if(mid < rr) ret = max(ret, cari(rig, mid + 1, r, max(mid + 1, ll), rr, i));
    return ret;
  }
  int n, m;
  vector<int> num[5];
};

int main() {
  clock_t t = clock();
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  Segtree seg(n, m);
  
  int ans = 0;
  vector<int> weapon;
  weapon.resize(m);
  for(int i = 1; i <= n; i++) {
    int l = i, r = n;
    while(l < r) {
      int mid = (l + r + 1) >> 1;
      int need = 0;
      for(int j = 0; j < m; j++) {
        need += seg.find(j, i, mid);
      }
      if(need <= k) l = mid;
      else r = mid - 1;
    }
    int need = 0;
    for(int j = 0; j < m; j++) {
      need += seg.find(j, i, l);
    }
    if(need <= k && ans < l - i + 1) {
      ans = l - i + 1;
      for(int j = 0; j < m; j++) {
        weapon[j] = seg.find(j, i, l);
      }
    }
  }
  for(auto it : weapon) printf("%d ", it);
  cerr << "Program berhasil mencari solusi dalam " << (float) (clock() - t)*1000.0/CLOCKS_PER_SEC << " milidetik."<< endl;
  return 0;
}