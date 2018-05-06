
#include <bits/stdc++.h>

using namespace std;

int lis(vector<int>& a) {
  vector<int> d(a.size(), 1);
  int ans = 1;
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) {
        d[i] = max(d[i], d[j] + 1);
      }
    }
    ans = max(ans, d[i]);
  }
  return ans;
}

int main() {
  for (int n = 7; n <= 7; n++) {
    vector<int> a;
    for (int i = 0; i < n; i++) a.push_back(i);
    set<tuple<int, int, int>> s;
    do {
      int A = lis(a);
      reverse(a.begin(), a.end());
      int B = lis(a);
      reverse(a.begin(), a.end());
      if (!s.count(make_tuple(A + B, A, B))) {
        s.insert(make_tuple(A + B, A, B));
        for (auto it : a) printf("%d ", it); printf(": %d %d\n", A, B);
      }
    } while (next_permutation(a.begin(), a.end()));
    for (auto it : s) {
      int b, c;
      tie(ignore, b, c) = it;
      printf("%d %d\n", b, c);
    }
  }

  return 0;
}
