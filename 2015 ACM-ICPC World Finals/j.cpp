#include <bits/stdc++.h>
/**************** FFT dnegan complex ***********************/

using namespace std;
const double PI = acos(-1);
typedef complex<double> cd;
typedef vector<cd> vcd;

vcd fft(const vcd &as){
  int n = (int) as.size();
  int k = 0;
  while((1 << k) < n) k++;
  vector<int> r(n);
  r[0] = 0;
  int h = -1;
  for(int i = 1;i < n; i++){
    if((i & (i-1)) == 0) h++;
    r[i] = r[i ^ (1 << h)];
    r[i] |= (1 << (k - h - 1));
  }
  vcd root(n);
  for(int i = 0;i < n; ++i){
    double ang = 2.0 * PI * i / n;
    root[i] = cd(cos(ang), sin(ang));
  }

  vcd cur(n);
  for(int i = 0;i < n; ++i){
    cur[i] = as[r[i]];
  }

  for(int len = 1;len < n; len <<= 1){
    vcd ncur(n);
    int step = n / (len << 1);
    for(int pdest = 0; pdest < n;){
      for(int i = 0;i < len; i++){
        cd val = root[i * step] * cur[pdest + len];
        ncur[pdest] = cur[pdest] + val;
        ncur[pdest + len] = cur[pdest] - val;
        pdest++;
      }
      pdest += len;
    }
    cur.swap(ncur);
  }
  return cur;
}

vcd inv_fft(const vcd& fa){
  vcd res = fft(fa);
  int nn = (int) fa.size();
  for(int i = 0;i < nn; i++){
    res[i] /= nn;
  }
  reverse(res.begin() + 1, res.end());
  return res;
}

const int N = 500005, S = sqrt(1e9);

vector<long long> square(vector<long long> & a) {
  int n = a.size();
  vcd b(n);
  for (int i = 0; i < n; ++i) {
    b[i] = a[i];
  }
  vcd bb(n);
  b = fft(b);
  for (int i = 0; i < n; ++i) {
    bb[i] = b[i] * b[i];
  }
  bb = inv_fft(bb);
  vector<long long> ans(n);
  for (int i = 0; i < n; ++i) {
    long long vbb = (long long)(bb[i].real() + 0.5);
    ans[i] = vbb;
  }
  return ans;
}

const int LG = 21;
int sp[LG][N];
vector<long long> ans;

int get(int l, int r) {
  int len = r-l+1;
  int lg = 31 - __builtin_clz(len);
  int le = sp[lg][l], ri = sp[lg][r-(1<<lg) + 1];
  return ans[le] < ans[ri] ? ri : le;
}

int main() {
  vector<long long> a(1 << 20);
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i)
      ++a[j];
  }
  ans = square(a);
  int t;
  for (int i = 0; i < N; ++i)
    sp[0][i] = i;
  for (int i = 0; i + 1 < LG; ++i) {
    for (int j = 0; j + (1 << (i+1)) <= N; ++j) {
      int le = sp[i][j], ri = sp[i][j+(1 << i)];
      sp[i+1][j] = ans[le] < ans[ri] ? ri : le;
    }
  }
  scanf("%d", &t);
  while (t--) {
    int l, r;
    scanf("%d %d", &l, &r);
    int v = get(l, r);
    printf("%d %lld\n", v, ans[v]);
  }
  return 0;
}
