#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int to[N];
char s[N];

int solve(int l, int r) {
  if (l > r) return 0;
  if (l + 1 == r) return 1;
  int ans = 1;
  for (int now = l; now <= r; now = to[now] + 1) {
    ans += solve(now + 1, to[now] - 1);
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    stack<int> st;
    for (int i = 0; i < 2 * n; i++) {
      if (s[i] == '(') {
        st.push(i);
      } else {
        int v = st.top();
        st.pop();
        to[v] = i;
      }
    }
    printf("%d\n", solve(0, 2 * n - 1));
  }
  return 0;
}
