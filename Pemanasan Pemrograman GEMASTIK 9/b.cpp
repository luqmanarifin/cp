#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

vector<string> s[N];

int main() {
  int t;
  cin >> t;
  while (t--) {
    for (int i = 0; i < N; i++) {
      s[i].clear();
    }
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
      int v; string c;
      cin >> v >> c;
      for (int j = v; j < N; j += v) {
        s[j].push_back(c);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (s[i].empty()) {
        printf("%d\n", i);
      } else {
        for (auto it : s[i]) printf("%s", it.c_str()); printf("\n");
      }
    }
  }

  return 0;
}
