#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

char s[N], cmd[N];
int l[N], r[N];

int lef[N], rig[N];

int main() {
  int n, m, p;
  scanf("%d %d %d %s %s", &n, &m, &p, s + 1, cmd);
  for(int i = 0; i <= n + 1; i++) {
    l[i] = i - 1;
    r[i] = i + 1;
  }
  stack<int> st;
  for(int i = 1; i <= n; i++) {
    if(s[i] == '(') {
      st.push(i);
    } else {
      rig[st.top()] = i;
      lef[i] = st.top();
      st.pop();
    }
  }
  for(int i = 0; i < m; i++) {
    if(cmd[i] == 'L') {
      p = l[p];
    } else if(cmd[i] == 'R') {
      p = r[p];
    } else {
      int ll, rr;
      if(s[p] == '(') {
        ll = l[p];
        rr = r[rig[p]];
      } else {
        ll = l[lef[p]];
        rr = r[p];
      }
      r[ll] = rr;
      l[rr] = ll;
      p = rr;
      if(p > n) p = ll;
    }
  }
  for(int i = r[0]; i <= n; i = r[i]) {
    printf("%c", s[i]);
  }
  return 0;
}