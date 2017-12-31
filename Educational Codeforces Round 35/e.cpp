#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int a[N];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> ans;
  for (int i = 0; i < k; i++) {
    scanf("%d", a + i);
    ans.push_back(a[i]);
  }
  stack<int> st, done;
  int now = 1;
  for (int i = 0; i < k; i++) {
    if (!st.empty() && st.top() < a[i]) {
      puts("-1");
      return 0;
    }
    st.push(a[i]);
    while (!st.empty() && st.top() == now) {
      done.push(now);
      now++;
      st.pop();
    }
  }
  while (!st.empty()) {
    int from = (done.size()? done.top() : 0) + 1;
    int to = st.top() - 1;
    for (int i = to; i >= from; i--) {
      ans.push_back(i);
    }
    done.push(st.top());
    st.pop();
  }
  int last = (done.size()? done.top() : 0);
  for (int i = n; i > last; i--) ans.push_back(i);
  for (auto it : ans) printf("%d ", it);
  return 0;
}
