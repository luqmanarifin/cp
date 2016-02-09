#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n = 3, m = 4;
int bit[N][N];
char s[N][N];

void _update(int i, int j, int val) {
  for(int pi = i; pi <= n; pi |= pi + 1) {
    for(int pj = j; pj <= m; pj |= pj + 1) {
      bit[pi][pj] += val;
    }
  }
}

void update(int i, int j, int val) {
  _update(0, 0, val);
  _update(i + 1, 0, -val);
  _update(0, j + 1, -val);
  _update(i + 1, j + 1, val);
}

int _get(int i, int j) {
  int ret = 0;
  for(int pi = i; pi >= 0; pi = (pi & (pi + 1)) - 1) {
    for(int pj = j; pj >= 0; pj = (pj & (pj + 1)) - 1) {
      ret += bit[pi][pj];
    }
  }
  return ret;
}

int get(int i, int j) {
  return _get(i, j) - _get(i - 1, j) - _get(i, j - 1) + _get(i - 1, j - 1);
}

int main() {
  /*
  update(0, 0, 1);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      printf("%d ", _get(i, j));
    }
    printf("\n");
  }
  puts("");
  _update(1, 0, 4);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      printf("%d ", _get(i, j));
    }
    printf("\n");
  }
  */
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  int ni = n - 1, nj = m - 1;
  int ans = 0;
  while(ni || nj) {
    int from = _get(ni, nj);
    int to = (s[ni][nj] == 'W'? 1 : -1);
    if(from != to) {
      update(ni, nj, to - from);
      ans++;
    }
    for(int i = ni - 1; i >= 0; i--) {
      from = _get(i, nj);
      to = (s[i][nj] == 'W'? 1 : -1);
      if(from != to) {
        update(i, nj, to - from);
        ans++;
      }
    }
    for(int j = nj - 1; j >= 0; j--) {
      from = _get(ni, j);
      to = (s[ni][j] == 'W'? 1 : -1);
      if(from != to) {
        update(ni, j, to - from);
        ans++;
      }
    }
    if(ni) ni--;
    if(nj) nj--;
  }
  int from = _get(0, 0);
  int to = (s[0][0] == 'W'? 1 : -1);
  if(from != to) {
    update(0, 0, to - from);
    ans++;
  }
  cout << ans << endl;
  
  return 0;
}
