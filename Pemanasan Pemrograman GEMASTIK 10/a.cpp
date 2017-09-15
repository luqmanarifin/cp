#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    set<string> st;
    int ms = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      bool selfie = s[0] == 's';
      int k;
      cin >> k;
      if (!selfie)
        ms = max(ms, k);
      while (k--) {
        cin >> s;
        st.insert(s);
      }
    }
    int ans = st.size() + (ms == st.size());
    printf("%d\n", ans);
  }
  return 0;
}