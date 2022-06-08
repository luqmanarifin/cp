#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d %s", &n, &k, s);
    int lef = 0, mid = 0, rig = 0, first = -1, last = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        if (i == 0) {
          lef++;
        } else if (i == n - 1) {
          rig++;
        } else {
          mid++;
          if (first == -1) first = i;
          last = i;
        }
      }
    }

    vector<int> v;
    // hemat kanan kiri
    if (lef == 0 && rig == 0 && mid >= 2) {
      int cost = first + n - 1 - last;
      if (cost <= k) {
        v.push_back(11);
      }
    }

    // hemat kanan
    if (rig == 0 && mid >= 1) {
      int cost = n - 1 - last;
      if (cost <= k) {
        v.push_back(10);
      }
    }

    // kiri ke kanan
    if (rig == 0 && mid == 0 && lef == 1) {
      int cost = n - 1;
      if (cost <= k) {
        v.push_back(9);
      }
    }

    // hemat kiri
    if (lef == 0 && mid >= 1) {
      int cost = first;
      if (cost <= k) {
        v.push_back(1);
      }
    }

    // doing nothing
    v.push_back(0);

    int ans = lef * 10 + mid * 11 + rig - v[0];
    printf("%d\n", ans);
  }

  return 0;
}
