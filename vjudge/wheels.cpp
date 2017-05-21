#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const int inf = 1e9;

struct asu {
  asu() {}
  int a[4];
  int hash() {
    int ret = 0;
    for (int i = 0; i < 4; i++) ret = ret * 10 + a[i];
    return ret;
  }
  void inject(int now) {
    for (int i = 3; i >= 0; i--) {
      a[i] = now % 10;
      now /= 10;
    }
  }
};

bool forbid[N];
int d[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(forbid, 0, sizeof(forbid));
    fill(d, d + N, inf);
    
    asu from, to;
    for (int i = 0; i < 4; i++) scanf("%d", &from.a[i]);
    for (int i = 0; i < 4; i++) scanf("%d", &to.a[i]);
    int n;
    scanf("%d", &n);
    while (n--) {
      asu cok;
      for (int i = 0; i < 4; i++) scanf("%d", &cok.a[i]);
      forbid[cok.hash()] = 1;
    }
    if (forbid[from.hash()] || forbid[to.hash()]) {
      puts("-1");
    } else {
      d[from.hash()] = 0;
      queue<int> q;
      q.push(from.hash());
      while (!q.empty()) {
        asu now;
        now.inject(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
          for (int j = -1; j <= 1; j++) {
            if (j == 0) continue;
            asu tmp;
            for (int k = 0; k < 4; k++) tmp.a[k] = now.a[k];
            tmp.a[i] = (tmp.a[i] + j + 10) % 10;
            if (forbid[tmp.hash()]) continue;
            if (d[tmp.hash()] > d[now.hash()] + 1) {
              d[tmp.hash()] = d[now.hash()] + 1;
              q.push(tmp.hash());
            }
          }
        }
      }
      if (d[to.hash()] == inf) {
        puts("-1");
      } else {
        printf("%d\n", d[to.hash()]);
      }
    }
  }

  return 0;
}
