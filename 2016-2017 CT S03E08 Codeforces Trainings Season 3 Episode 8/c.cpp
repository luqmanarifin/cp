#include <bits/stdc++.h>

using namespace std;

map<string, int> MP;
int p;

struct cube {
  int a[10];
  cube() {}
  void input() {
    for (int i = 1; i <= 6; i++) {
      string str;
      cin >> str;
      if (!MP.count(str)) MP[str] = p++;
      a[i] = MP[str];
    }
  }
  void rotate1() {
    int tmp[10];
    tmp[2] = a[1];
    tmp[6] = a[2];
    tmp[5] = a[6];
    tmp[1] = a[5];
    tmp[3] = a[3];
    tmp[4] = a[4];
    for (int i = 1; i <= 6; i++) a[i] = tmp[i];
  }
  void rotate2() {
    int tmp[10];
    tmp[3] = a[1];
    tmp[1] = a[4];
    tmp[4] = a[6];
    tmp[6] = a[3];
    tmp[2] = a[2];
    tmp[5] = a[5];
    for (int i = 1; i <= 6; i++) a[i] = tmp[i];
  }
};


cube c[5];
int n;
int ans;

int calc() {
  int ret = 0;
  for (int i = 1; i <= 6; i++) {
    int cnt[30] = {};
    for (int j = 0; j < n; j++) {
      cnt[c[j].a[i]]++;
    }
    int cur = 1e9;
    for (int j = 0; j < 30; j++) {
      cur = min(cur, n - cnt[j]);
    }
    ret += cur;
  }
  return ret;
}

void dfs(int now) {
  if (now == n) {
    ans = min(ans, calc());
    return;
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      dfs(now + 1);
      c[now].rotate1();
    }
    c[now].rotate2();
  }
  c[now].rotate1();
  c[now].rotate2();
  for (int i = 0; i < 4; i++) {
    dfs(now + 1);
    c[now].rotate1();
  }
  c[now].rotate2();
  c[now].rotate2();
  for (int i = 0; i < 4; i++) {
    dfs(now + 1);
    c[now].rotate1();
  }
}

int main() {
  scanf("%d", &n);
  while (n) {
    MP.clear();
    p = 0;
    ans = 1e9;
    for (int i = 0; i < n; i++) c[i].input();
    dfs(0);
    printf("%d\n", ans);
    
    scanf("%d", &n);
  }

  return 0;
}
