#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int a[N], n, m;
bool is[N];

int ask(int x) {
  printf("? ");
  for (int i = 1; i <= m; i++) {
    if (i == x) {
      printf("1");
    } else {
      printf("0");
    }
  }
  printf("\n");
  fflush(stdout);
  int v;
  scanf("%d", &v);
  return v;
}

int ask() {
  printf("? ");
  for (int i = 1; i <= m; i++) {
    if (is[i]) {
      printf("1");
    } else {
      printf("0");
    }
  }
  printf("\n");
  fflush(stdout);
  int v;
  scanf("%d", &v);
  return v;
}

int main() {
  scanf("%d %d", &n, &m);
  vector<pair<int, int>> p;
  for (int i = 1; i <= m; i++) {
    a[i] = ask(i);
    p.emplace_back(a[i], i);
  }
  sort(p.begin(), p.end());
  int now = 0;
  for (auto it : p) {
    int i = it.second;
    int x = it.first;
    is[i] = 1;
    int v = ask();
    if (v == now + x) {
      now += x;
    } else {
      is[i] = 0;
    }
  }
  printf("! %d\n", now);
  fflush(stdout);
  return 0;
}
