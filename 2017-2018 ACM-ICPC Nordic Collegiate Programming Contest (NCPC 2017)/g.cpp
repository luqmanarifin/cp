#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

pair<int, int> s[N];

int main() {
  int n, m;
  set<pair<pair<int, int>, int> > st;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int t, x;
    scanf("%d %d", &t, &x);
    if (t == 1) {
      s[t].first++;
      s[t].second -= x;
      auto it = st.begin();
      while (it != st.end()) {
        if (it->first > s[1]) break;
        st.erase(it++);
      }
    }
    else {
      st.erase(make_pair(s[t], t));
      s[t].first++;
      s[t].second -= x;
      if (s[t] > s[1])
        st.insert(make_pair(s[t], t));
    }
    printf("%d\n", st.size() + 1);
  }
  return 0;
}
