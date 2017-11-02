#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5, LG = 16;

char s[33];

int a[N];
int sp[LG][N];
int p[2][33];

int cnt_pal(int n) {
  for (int i = 0; i < n; i++)
    p[0][i] = p[1][i] = 0;
  for (int z=0, l=0, r=0; z < 2; z++, l=0, r=0) {
    for (int i = 0; i < n; i++) {
      if (i < r) p[z][i] = min(r-i+!z, p[z][l+r-i+!z]);
      int L = i-p[z][i], R = i+p[z][i]-!z;
      while (L-1 >= 0 && R+1 < n && s[L-1] == s[R+1]) p[z][i]++, L--, R++;
      if(R > r) l = L,r = R;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += p[0][i] + 1 + p[1][i];
  }
  return ans;
}

long long enc(int n) {
  long long now = 0;
  for (int i = 0; i < n; i++) {
    now <<= 2;
    now |= s[i]-'a' + 1;
  }
  return now;
}
vector<pair<long long, int> > mp;

int id(long long x) {
  return lower_bound(mp.begin(), mp.end(), make_pair(x, -1))->second;
}

char sa[33], sb[33];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    mp.clear();
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      int len = strlen(s);
      mp.emplace_back(enc(len), i);
      a[i] = cnt_pal(len);
    }
    for (int i= 0; i < n; i++) {
      sp[0][i] = i;
    }
    for (int i = 0; i + 1 < LG; i++) {
      for (int j = 0; j + (1 << (i+1)) <= n; j++) {
        int le = sp[i][j], ri = sp[i][j + (1 << i)];
        sp[i+1][j] = a[le] < a[ri] ? ri : le;
      }
    }
    sort(mp.begin(), mp.end());
    while (m--) {
      scanf("%s", s);
      long long sa = enc(strlen(s));
      scanf("%s", s);
      long long sb = enc(strlen(s));
      int le = id(sa), ri = id(sb);
  //    cerr << le << " to " << ri << endl;
      if (le > ri) swap(le, ri);
      int len = ri - le+1;
      int lg = 31 - __builtin_clz(len);
      int ansl = sp[lg][le], ansr = sp[lg][ri-(1<<lg)+1];
//      cerr << ansl << " " << ansr << endl;
      printf("%d\n", (::a[ansl] < ::a[ansr] ? ansr : ansl) + 1);
    }
  }
  
  return 0;
}