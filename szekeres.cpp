#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

vector<int> edge[N];
int to[N];
int a[N];
int b[N];
int ans[N];
bool done[N];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    memset(to, 0, sizeof(to));
    memset(done, 0, sizeof(done));
    for(int i = 0; i < N; i++) {
      edge[i].clear();
    }
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
      scanf("%d", &b[i]);
    }
    for(int i = 0; i < n; i++) {
      int last = -1;
      for(int j = 0; j < i; j++) {
        if(a[j] == a[i] - 1) {
          last = j;
        } else if(a[j] >= a[i]) {
          edge[i].push_back(j);
          to[j]++;
        }
      }
      if(a[i] > 1) {
        assert(last != -1);
        edge[last].push_back(i);
        to[i]++;
      }
    }
    for(int i = n - 1; i >= 0; i--) {
      int last = -1;
      for(int j = n - 1; j > i; j--) {
        if(b[j] == b[i] - 1) {
          last = j;
        } else if(b[j] >= b[i]) {
          edge[i].push_back(j);
          to[j]++;
        }
      }
      if(b[i] > 1) {
        assert(last != -1);
        edge[last].push_back(i);
        to[i]++;
      }
    }
    priority_queue<int> topo;
    vector<int> res;
    for(int i = 0; i < n; i++) {
      if(to[i] == 0) {
        topo.push(-i);
      }
    }
    while(!topo.empty()) {
      int now = topo.top();
      now = -now;
      if(!done[now]) {
        res.push_back(now);
      }
      done[now] = 1;
      topo.pop();
      for(auto it : edge[now]) {
        to[it]--;
        if(to[it] == 0) {
          topo.push(-it);
        }
      }
    }
    for(int i = 0; i < n; i++) {
      if(!done[i]) {
        res.push_back(i);
      }
    }
    for(int i = 0; i < n; i++) {
      ans[res[i]] = i;
    }
    int aa[n], bb[n];
    memset(aa, 0, sizeof(aa));
    memset(bb, 0, sizeof(bb));
    for(int i = 0; i < n; i++) {
      int maxi = 0;
      for(int j = 0; j < i; j++) {
        if(ans[j] < ans[i]) {
          maxi = max(maxi, aa[j]);
        }
      }
      aa[i] = maxi + 1;
      assert(aa[i] == a[i]);
    }
    for(int i = n - 1; i >= 0; i--) {
      int maxi = 0;
      for(int j = n - 1; j > i; j--) {
        if(ans[i] > ans[j]) {
          maxi = max(maxi, bb[j]);
        }
      }
      bb[i] = maxi + 1;
      assert(bb[i] == b[i]);
    }
    printf("Case #%d:", tt);
    for(int i = 0; i < n; i++) {
      printf(" %d", ans[i] + 1);
    }
    printf("\n");
  }
  
  return 0;
}
