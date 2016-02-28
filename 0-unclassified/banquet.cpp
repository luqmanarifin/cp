#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int SAMPAH = 10005;

int a[N], b[N], n;
vector<int> kon[SAMPAH];

bool can(int must) {
  multiset<pair<int, int>> st;
  for(int i = 0; i < SAMPAH; i++) {
    for(auto it : kon[i]) {
      st.insert(make_pair(it, must));
    }
    if(st.empty()) continue;
    auto it = st.begin();
    st.erase(it);
    if(it->first <= i) return 0;
    if(it->second > 1) {
      st.insert(make_pair(it->first, it->second - 1));
    }
  }
  return 1;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", a + i, b + i);
    kon[a[i]].push_back(b[i]);
  }
  int l = 0, r = 10000;
  while(l < r) {
    int mid = (l + r + 1) >> 1;
    if(can(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  printf("%d\n", l * n);
  return 0;
}
