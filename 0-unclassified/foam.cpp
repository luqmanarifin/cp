#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

vector<int> prime[N];
int is[N];

int a[N], mul[N];

bool ada[N];
int cnt[N];

int main() {
  for(int i = 2; i < N; i++) {
    if(!is[i]) {
      for(int j = i; j < N; j += i) {
        is[j] = 1;
        prime[j].push_back(i);
      }
    }
  }

  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int now = 0;
  long long ans = 0;
  for(int qq = 1; qq <= q; qq++) {
    int at;
    scanf("%d", &at);
    at--;
    
    int cur = 0;
    mul[0] = 1;
    for(int i = 0; i < prime[a[at]].size(); i++) {
      mul[1 << i] = prime[a[at]][i];
    }
    //printf("ITERASI %d\n", qq);
    for(int mask = 1; mask < (1 << prime[a[at]].size()); mask++) {
      int bit = __builtin_popcount(mask);
      if(bit != 1) {
        int last = (1 << __builtin_ctz(mask));
        mul[mask] = mul[mask ^ last] * mul[last];
      }
      cnt[mul[mask]] += (ada[at]? -1 : 0);
      if(bit & 1) {
        cur += cnt[mul[mask]];
      } else {
        cur -= cnt[mul[mask]];
      }
      cnt[mul[mask]] += (ada[at]? 0 : 1);
      
      /*
      printf("cur %d : ", cur);
      for(int i = 0; i < prime[a[at]].size(); i++) {
        if(mask & (1 << i)) {
          printf("%d ", prime[a[at]][i]);
        }
      }
      printf("\n");
      */
    }
    now += (ada[at]? -1 : 0);
    
    //printf("%d %d\n", qq, cur);
    ans += (ada[at]? cur - now : now - cur);
    printf("%I64d\n", ans);
    //puts("");
    
    now += (ada[at]? 0 : 1);
    ada[at] ^= 1;
  }
  
  return 0;
}
