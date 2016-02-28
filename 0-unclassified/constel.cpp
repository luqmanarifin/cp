#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

vector<int> edge[N];
int a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    for(int i = 0; i < N; i++) {
      edge[i].clear();
    }
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d %d", a + i, b + i);
    }
    for(int i = 0; i < n; i++) {
      for(int j = i + 1; j < n; j++) {
        int d = (a[i] - a[j])*(a[i] - a[j]) + (b[i] - b[j])*(b[i] - b[j]);
        edge[i].push_back(d);
        edge[j].push_back(d);
      }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
      sort(edge[i].begin(), edge[i].end());
      for(int j = 0; j < edge[i].size(); ) {
        int k = j + 1;
        while(k < edge[i].size() && edge[i][j] == edge[i][k]) k++;
        int cnt = k - j;
        ans += 1LL * cnt * (cnt - 1) / 2;
        j = k;
      }
    }
    printf("Case #%d: %I64d\n", tt, ans);
    cerr << tt << " done!" << endl;
  }
  
  return 0;
}
