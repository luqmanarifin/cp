#include <bits/stdc++.h>

using namespace std;

int power(int a, int b) {
  int ret = 1;
  for (int i = 0; i < b; i++) ret *= a;
  return ret;
}

int a[20];


int main() {
  for (int n = 2; n <= 6; n++) {
    vector<pair<int, int>> rule;
    for (int i = 2; i <= n; i++) {
      rule.emplace_back(i, i - 1);
      rule.emplace_back(i - 1, i);
    }

    for (int step = n; step <= 2 * n; step++) {
      int to = power(n, step);
      for (int h = 0; h < to; h++) {
        int t = h;
        for (int i = 1; i <= step; i++) {
          a[i] = t % n + 1;
          //printf("%d ", a[i]);
          t /= n;
        }
        //printf("\n");
        bool complete = 1;
        for (auto it : rule) {
          bool found = 0;
          for (int i = 1; i <= step; i++) {
            if (it.first != a[i]) continue;
            for (int j = i + 1; j <= step; j++) {
              if (it.second != a[j]) continue;
              found = 1;
              goto COK;
            }
          }
          COK:;
          if (!found) {
            complete = 0;
            break;
          }
        }
        if (complete) {
          for (int i = 1; i <= step; i++) printf("%d ", a[i]); printf("\n");
          goto FINE;
        }
      }
    }
    FINE:;
  }  

  return 0;
}
