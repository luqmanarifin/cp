#include <bits/stdc++.h>

using namespace std;

const int N = 305;
const int inf = 1e9;

char a[N][N], x[N][N], o[N][N], s[N];

int en[N], mid[N];

int pre(int i) {
  // if (i < 10) printf("%d: %c\n", i, s[i]);
  if (s[i] != '(') {
    // printf("%d alone\n", i);
    en[i] = i;
    return i;
  }

  int r = pre(i + 1);
  mid[i] = r + 1;
  r = pre(mid[i] + 1);
  en[i] = r + 1;
  return en[i];
}

char solve(int l, int r) {
  if (l == r) return s[l];
  char cl = solve(l + 1, mid[l] - 1);
  char cr = solve(mid[l] + 1, r - 1);
  if (s[mid[l]] == '|') {
    return o[cl][cr];
  } else if (s[mid[l]] == '&') {
    return a[cl][cr];
  } else {
    return x[cl][cr];
  }
}

int main() {
  a['0']['0'] = '0'; a['0']['1'] = '0'; a['0']['x'] = '0'; a['0']['X'] = '0';
  a['1']['0'] = '0'; a['1']['1'] = '1'; a['1']['x'] = 'x'; a['1']['X'] = 'X';
  a['x']['0'] = '0'; a['x']['1'] = 'x'; a['x']['x'] = 'x'; a['x']['X'] = '0';
  a['X']['0'] = '0'; a['X']['1'] = 'X'; a['X']['x'] = '0'; a['X']['X'] = 'X';

  x['0']['0'] = '0'; x['0']['1'] = '1'; x['0']['x'] = 'x'; x['0']['X'] = 'X';
  x['1']['0'] = '1'; x['1']['1'] = '0'; x['1']['x'] = 'X'; x['1']['X'] = 'x';
  x['x']['0'] = 'x'; x['x']['1'] = 'X'; x['x']['x'] = '0'; x['x']['X'] = '1';
  x['X']['0'] = 'X'; x['X']['1'] = 'x'; x['X']['x'] = '1'; x['X']['X'] = '0';

  o['0']['0'] = '0'; o['0']['1'] = '1'; o['0']['x'] = 'x'; o['0']['X'] = 'X';
  o['1']['0'] = '1'; o['1']['1'] = '1'; o['1']['x'] = '1'; o['1']['X'] = '1';
  o['x']['0'] = 'x'; o['x']['1'] = '1'; o['x']['x'] = 'x'; o['x']['X'] = '1';
  o['X']['0'] = 'X'; o['X']['1'] = '1'; o['X']['x'] = '1'; o['X']['X'] = 'X';

  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%s", s);
    int n = strlen(s);
    assert(pre(0) == n - 1);
    auto c = solve(0, n - 1);
    printf("Case #%d: ", tt);
    if (c == '0' || c == '1') {
      printf("0\n");
    } else {
      printf("1\n");
    }
  }

  return 0;
}
