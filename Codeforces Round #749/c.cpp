#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector<string> s;
vector<vector<int>> a;  // lowest column this cell can reach
int rmq[N][20];
char buf[N];

string create_string(int n, char c) {
  string res = "";
  for (int i = 0; i < n; i++) res.push_back(c);
  return res;
}

int find(int l, int r) {
  int g = __builtin_clz(r - l + 1) ^ 31;
  return max(rmq[l][g], rmq[r-(1<<g)+1][g]);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  s = vector<string>(n + 1, create_string(m + 1, '.'));
  a = vector<vector<int>>(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    scanf("%s", buf);
    s[i] = '.' + string(buf);
  }
  // puts("IO done");
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      a[i][j] = j;
      if (j <= 1) {
        a[i][j] = 0;
      }
      if (i > 0 && s[i-1][j] == '.') {
        a[i][j] = min(a[i][j], a[i-1][j]);
      }
      if (j > 0 && s[i][j-1] == '.') {
        a[i][j] = min(a[i][j], a[i][j-1]);
      }
      rmq[j][0] = max(rmq[j][0], a[i][j]);
    }
  }
  // puts("preprocess done");
  for (int j = 1; (1 << j) <= m + 1; j++) {
    for (int i = 0; i + (1 << j) - 1 <= m; i++) {
      rmq[i][j] = max(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
    }
  }
  // puts("build rmq done");
  
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    puts(find(l, r) > l? "NO" : "YES");
  }
  return 0;
}
