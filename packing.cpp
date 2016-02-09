#include <bits/stdc++.h>

using namespace std;

int cnt[777];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    memset(cnt, 0, sizeof(cnt));
    
    int n, s;
    scanf("%d %d", &n, &s);
    multiset<int> list;
    for(int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      cnt[a]++;
      list.insert(a);
    }
    int ans = 0;
    for(int i = 700; i >= 1; i--) {
      //printf("%d\n", i);
      while(cnt[i]--) {
        list.erase(list.find(i));
        ans++;
        int side = s - i;
        
        if(list.empty()) continue;
        multiset<int>::iterator it = list.upper_bound(side);
        if(it == list.begin()) continue;
        it--;
        int num = *it;
        cnt[num]--;
        list.erase(list.find(num));
      }
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
