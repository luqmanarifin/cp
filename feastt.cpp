#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 5;

bool done[N][2];

int main() {
  freopen("feast.in","r",stdin);
  freopen("feast.out","w",stdout);
  
  int t, a, b;
  scanf("%d %d %d", &t, &a, &b);
  queue<pair<int, int>> q;
  done[0][0] = 1;
  q.emplace(0, 0);
  while(!q.empty()) {
    int now, s;
    tie(now, s) = q.front();
    q.pop();
    if(now + a <= t && !done[now + a][s]) {
      done[now + a][s] = 1;
      q.emplace(now + a, s);
    }
    if(now + b <= t && !done[now + b][s]) {
      done[now + b][s] = 1;
      q.emplace(now + b, s);
    }
    if(!done[now / 2][1] && s == 0) {
      done[now / 2][1] = 1;
      q.emplace(now / 2, 1);
    }
  }
  for(int i = t; i >= 0; i--) {
    if(done[i][0] || done[i][1]) {
      cout << i << endl;
      fclose(stdin);
      fclose(stdout);
      return 0;
    }
  }
}
