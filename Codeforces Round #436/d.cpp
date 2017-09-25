#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
int done[N];
bool dep[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    done[a[i]]++;
  }
  set<int> lom;
  for (int i = 1; i <= n; i++) {
    if (!done[i]) {
      lom.insert(i);
    }
  }
  printf("%d\n", lom.size());
  for (int i = 1; i <= n; i++) {
    if (done[a[i]] > 1) {
      if (*(lom.begin()) < a[i] || dep[a[i]]) {
        done[a[i]]--;
        auto it = lom.begin();
        a[i] = *it;
        lom.erase(it);
        done[a[i]]++;
      } else {
        done[a[i]] = N;
        dep[a[i]] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  return 0;
}
