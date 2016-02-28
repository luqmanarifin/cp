#include <bits/stdc++.h>

using namespace std;

int a[105][2], lim[2];
stack<pair<int, int>> st;

void sebar(int at, int s) {
  int awal = at % lim[s ^ 1];
  int now = at % lim[s ^ 1];
  bool min = (lim[s] < lim[s ^ 1]);
  while(1) {
    if(a[now][s ^ 1] == 0) {
      st.emplace(now, s ^ 1);
    }
    a[now][s ^ 1] = 1;
    
    if(min) now -= abs(lim[0] - lim[1]);
    else now += abs(lim[0] - lim[1]);
    now %= lim[s ^ 1];
    if(now < 0) now += lim[s ^ 1];
    
    if(now == awal) {
      break;
    }
  }
}

int main() {
  int aa, bb;
  scanf("%d %d", &lim[0], &lim[1]);
  scanf("%d", &aa);
  while(aa--) {
    int at;
    scanf("%d", &at);
    st.emplace(at, 0);
    a[at][0] = 1;
  }
  scanf("%d", &aa);
  while(aa--) {
    int at;
    scanf("%d", &at);
    st.emplace(at, 1);
    a[at][1] = 1;
  }
  while(!st.empty()) {
    int at, s;
    tie(at, s) = st.top();
    st.pop();
    sebar(at, s);
  }
  bool all = 1;
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < lim[i]; j++) {
      all &= a[j][i];
    }
  }
  puts(all? "Yes" : "No");
  return 0;
}