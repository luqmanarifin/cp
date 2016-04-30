#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

int done[N];
int n, a[N];
int wew[5];

int get() {
  int ret = 0;
  for(int i = 0; i < n; i++) {
    ret = ret * 4 + a[i];
  }
  return ret;
}

void push(int now) {
  for(int i = n - 1; i >= 0; i--) {
    a[i] = now % 4;
    now /= 4;
  }
}

int main() {
  fill(done, done + N, N);
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i]--;
  }
  queue<int> q;
  int s = get();
  q.push(s);
  done[s] = 0;
  while(!q.empty()) {
    int now = q.front();
    push(now);
    if(now == 0) {
      cout << done[now] << endl;
      return 0;
    }
    q.pop();
    memset(wew, 0, sizeof(wew));
    for(int i = 0; i < n; i++) {
      if(wew[a[i]]) continue;
      for(int j = 0; j < 4; j++) {
        if(!wew[j]) {
          int tmp = a[i];
          a[i] = j;
          int p = get();
          if(done[now] + 1 < done[p]) {
            done[p] = done[now] + 1;
            q.push(p);
          }
          a[i] = tmp;
        }
      }
      wew[a[i]] = 1;
    }
  }
  return 0;
}