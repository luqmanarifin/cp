#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

int suml[N], sumk[N];
int siku[N];
char s[N];

struct Segtree {
public:
  Segtree(int _n) : n(_n) {
    ln.resize(n << 2);
    sk.resize(n << 2);
    build(1, 1, n);
  };
  int find_lengkung(int l, int r) {
    return cari_len(1, 1, n, l, r);
  }
  int find_siku(int l, int r) {
    return cari_sik(1, 1, n, l, r);
  }
private:
  void build(int p, int l, int r) {
    if(l == r) {
      ln[p] = suml[l];
      sk[p] = sumk[l];
      return;
    }
    int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
    build(lef, l, mid);
    build(rig, mid + 1, r);
    ln[p] = min(ln[lef], ln[rig]);
    sk[p] = min(sk[lef], sk[rig]);
  }
  int cari_len(int p, int l, int r, int ll, int rr) {
    if(l == ll && r == rr) {
      return ln[p];
    }
    int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
    int ret = inf;
    if(ll <= mid) ret = min(ret, cari_len(lef, l, mid, ll, min(mid, rr)));
    if(mid < rr) ret = min(ret, cari_len(rig, mid + 1, r, max(mid + 1, ll), rr));
    return ret;
  }
  int cari_sik(int p, int l, int r, int ll, int rr) {
    if(l == ll && r == rr) {
      return sk[p];
    }
    int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
    int ret = inf;
    if(ll <= mid) ret = min(ret, cari_sik(lef, l, mid, ll, min(mid, rr)));
    if(mid < rr) ret = min(ret, cari_sik(rig, mid + 1, r, max(mid + 1, ll), rr));
    return ret;
  }
  int n;
  vector<int> ln, sk;
};

int main() {
  scanf("%s", &s[1]);
  int n = strlen(&s[1]);
  for(int i = 1; i <= n; i++) {
    suml[i] += suml[i - 1];
    sumk[i] += sumk[i - 1];
    siku[i] += siku[i - 1];
    switch(s[i]) {
      case '(' : suml[i]++; break;
      case '[' : sumk[i]++, siku[i]++; break;
      case ')' : suml[i]--; break;
      case ']' : sumk[i]--; break;
    }
  }
  Segtree seg(n);
  int ans = 0;
  int a = n + 1, b = n + 1;
  for(int i = 1; i <= n; i++) {
    int l = i, r = n;
    while(l < r) {
      int mid = (l + r + 1) >> 1;
      bool valid = (suml[i - 1] == suml[mid] && sumk[i - 1] == sumk[mid]);
      int min_lengkung = seg.find_lengkung(i, mid);
      int min_siku = seg.find_siku(i, mid);
      //printf("%d %d %d\n", mid, min_lengkung, min_siku);
      if(suml[i - 1] > min_lengkung || sumk[i - 1] > min_siku) r = mid - 1;
      else l = mid;
    }
    bool valid = (suml[i - 1] == suml[l] && sumk[i - 1] == sumk[l]);
    valid &= (suml[i - 1] == seg.find_lengkung(i, l));
    valid &= (sumk[i - 1] == seg.find_siku(i, l));
    //printf("%d %d\n", i, l);
    if(valid && ans < siku[l] - siku[i - 1]) {
      ans = siku[l] - siku[i - 1];
      a = i;
      b = l;
      //printf("%d %d %d\n", ans, a, b);
    }
  }
  cout << ans << endl;
  if(ans == 0) return 0;
  for(int i = a; i <= b; i++) {
    printf("%c", s[i]);
  }
  printf("\n");
  return 0;
}