#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

map<int, int> cnt;
map<int, bool> done;
int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    cnt.clear();
    done.clear();
    
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for(int i = 0; i < k; i++) {
      cnt[a[i]]++;
    }
    int cur = 0;
    for(int i = 0; i < k; i++) {
      //printf("cnt %d %d\n", a[i], cnt[a[i]]);
      if(cnt[a[i]] == a[i] && !done[a[i]]) {
        cur++;
        done[a[i]] = 1;
      }
    }
    //printf("cur %d\n", cur);
    int ans = cur;
    for(int i = k; i < n; i++) {
      bool mut = 0;
      if(cnt[a[i - k]]-- == a[i - k]) {
        cur--;
        mut = 1;
      }
      if(!mut) if(cnt[a[i - k]] == a[i - k]) {
        cur++;
      }
      
      mut = 0;
      if(cnt[a[i]]++ == a[i]) {
        cur--;
        mut = 1;
      }
      if(!mut) if(cnt[a[i]] == a[i]) {
        cur++;
      }
      //printf("%d %d\n", i, cur);
      ans += cur;
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
