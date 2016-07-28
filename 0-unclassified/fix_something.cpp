#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], to[N];
bool done[N];
vector<int> edge[N];

void dfs(int now) {
  done[now] = 1;
  for (auto it : edge[now]) {
    dfs(it);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (a[i] != i) {
      to[a[i]]++;
      edge[a[i]].push_back(i);
    }

  }
  int root = -1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == i) {
      if (root == -1) {
        root = i;
      } else {
        ans++;
        a[i] = root;
      }
      dfs(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (done[i]) continue;
    set<int> s;
    int now = i;
    while (1) {
      if (now == a[now]) {
        if (root == -1) {
          root = now;
        } else {
          a[now] = root;
          ans++;
        }
        break;
      }
      if (done[a[now]]) {
        if (s.count(a[now])) {
          if (root == -1) {
            root = now;
            a[now] = now;
            ans++;
          } else {
            a[now] = root;
            ans++;
          }
        }
        break;
      }
      done[now] = 1;
      s.insert(now);
      now = a[now];
    }
    done[now] = 1;
    s.insert(now);
    now = a[now];
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  return 0;
}
