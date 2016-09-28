#include <bits/stdc++.h>

using namespace std;

const int N = 25e3 + 5;

int a[N];

int main() {
  memset(a, -1, sizeof(a));
  for (int i = 1; i < N; i += 2) a[i] = 0;
  for (int v = 1; v < 10; v++) {
    printf("%d\n", v);
    set<int> done;
    set<int> bef;
    for (int i = 1; i < N; i++) {
      if (a[i] == -1 && !done.count(i)) {
        bef.insert(i);
        for (auto it : bef) {
          done.insert(it + i);
        }
        a[i] = v;
      }
    }
  }
  for (int i = 1; i < N; i++) {
    if (a[i] == -1) {
      printf("lala %d", i);
      return 0;
    }
    printf("%d", a[i]);
  }
  return 0;
}
