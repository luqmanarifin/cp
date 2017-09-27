#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 8;
  vector<int> a;
  for (int i = 0; i < n; i++) a.push_back(i + 1);
  int best = 0;
  do {
    int cur = 0;
    for (int i = 1; i < n; i++) {
      cur += abs(a[i] - a[i - 1]);
    }
    if (cur > best) best = cur;
  } while (next_permutation(a.begin(), a.end()));
  sort(a.begin(), a.end());
  do {
    int cur = 0;
    for (int i = 1; i < n; i++) {
      cur += abs(a[i] - a[i - 1]);
    }
    if (cur == best) {
      for (auto it : a) printf("%d ", it); printf("\n");
    }
  } while (next_permutation(a.begin(), a.end()));
  cout << best << endl;
  return 0;
}
