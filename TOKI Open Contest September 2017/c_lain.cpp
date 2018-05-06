
#include <bits/stdc++.h>

using namespace std;

int nyawa = 16;
vector<int> ans;

int ask(int l, int r) {
  nyawa--;
  printf("%d", r - l + 1);
  for (int i = l; i <= r; i++) {
    printf(" %d", i);
  }
  printf("\n");
  fflush(stdout);

  int k;
  scanf("%d", &k);
  return k;
}

int ask(int l, int r, int a, int b) {
  nyawa--;
  printf("%d", r - l + 1 + b - a + 1);
  for (int i = l; i <= r; i++) printf(" %d", i);
  for (int i = a; i <= b; i++) printf(" %d", i);
  printf("\n");
  fflush(stdout);

  int k;
  scanf("%d", &k);
  return k;
}

// if inactive maka -1 -1
void dfs(int l, int r, int a, int b) {
  //printf("lala %d %d %d %d\n", l, r, a, b);
  if (l == r && l != -1) {
    ans.push_back(l);
  }
  if (a == b && a != -1) {
    ans.push_back(a);
  }
  if (l == r && a == b) return;
  if (l == a && r == b) {
    int mid = (l + r) >> 1;
    int k = ask(l, mid);
    if (k == 0) {
      dfs(mid + 1, r, mid + 1, r);
    } else if (k == 2) {
      dfs(l, mid, l, mid);
    } else {
      dfs(l, mid, mid + 1, r);
    }
  } else {
    if (l == r) {
      int mid = (a + b) >> 1;
      int k = ask(a, mid);
      if (k == 0) {
        dfs(-1, -1, mid + 1, b);
      } else {
        dfs(-1, -1, a, mid);
      }
    } else if (a == b) {
      int mid = (l + r) >> 1;
      int k = ask(l, mid);
      if (k == 0) {
        dfs(mid + 1, r, -1, -1);
      } else {
        dfs(l, mid, -1, -1);
      }
    } else {
      int ml = (l + r) >> 1;
      int ma = (a + b) >> 1;
      vector<tuple<int, int, int, int>> q;
      q.emplace_back(l, ml, a, ma);
      q.emplace_back(l, ml, ma + 1, b);
      q.emplace_back(ml + 1, r, a, ma);
      q.emplace_back(ml + 1, r, ma + 1, b);
      int random = rand() % q.size();
      int w, x, y, z;
      tie(w, x, y, z) = q[random];
      int k = ask(w, x, y, z);
      int n = random ^ 2;
      int m = random ^ 1;
      if (k == 0) {
        dfs(get<0>(q[n]), get<1>(q[n]), get<2>(q[m]), get<3>(q[m]));
      } else if (k == 2) {
        dfs(w, x, y, z);
      } else {
        int k = ask(w, x);
        if (k == 0) {
          dfs(get<0>(q[n]), get<1>(q[n]), y, z);
        } else {
          dfs(w, x, get<2>(q[m]), get<3>(q[m]));
        }
      }
    }
  }
}

int main() {
  int n;
  srand(time(0));
  scanf("%d", &n);
  dfs(1, n, 1, n);
/*
  if (nyawa < 0) {
    printf("%d\n", nyawa);
    puts("MATIO COK NYAWAMU ABIS");
    assert(0);
  }
*/
  while (nyawa > 0) {
    printf("0\n");
    fflush(stdout);
    int k;
    scanf("%d", &k);
    nyawa--;
  }
  printf("%d %d\n", ans[0], ans[1]);
  fflush(stdout);
  return 0;
}
