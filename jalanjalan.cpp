#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const int pol = 1e5 + 5;

bool to[pol / 2][N];
bool done[pol];

int a[N];
int ans[N], n;

void dfs(int now) {
  for(int i = n - 1; i >= 0; i--) {
    //printf("%d %d\n", now, i);
    if(to[now][i]) {
      //printf("PAKE %d\n", a[i]);
      ans[i] = 1;
      now -= a[i];
    }
  }
  //printf("AKHIR %d\n", now);
  assert(now == 0);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    memset(done, 0, sizeof(done));
    memset(ans, 0, sizeof(ans));
    
    done[0] = 1;
    int sum = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
      sum += a[i];
    }
    //sort(a, a + n);
    int half = sum / 2;
    int now = 0;
    for(int i = 0; i < n; i++) {
      now = min(now + a[i], half);
      for(int j = 0; j < now; j++) {
        to[j][i] = 0;
      }
      for(int j = now; j >= a[i]; j--) {
        bool& cak = to[j][i] = 0;
        if(done[j - a[i]]) {
          done[j] = 1;
          cak = 1;
        }
      }
    }
    /*
    for(int i = 0; i < n; i++) {
      for(int j = 0; j <= half; j++) {
        printf("%d ", to[j][i]);
      }
      printf("\n");
    }
    */
    for(int j = half; j >= 0; j--) {
      if(done[j]) {
        dfs(j);
        printf("%lld\n", 1LL * j * (sum - j));
        break;
      }
    }
    for(int i = 0; i < n; i++) {
      if(ans[i]) {
        printf("R");
      } else {
        printf("D");
      }
    }
    printf("\n");
  }
  
  return 0;
}
