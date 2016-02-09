#include <bits/stdc++.h>

using namespace std;

const int N = 105;

bool done[N];
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(done, 0, sizeof(done));
    
    int n;
    scanf("%d %s", &n, s + 1);
    for(int i = 1; i <= n; i++) {
      if(s[i] == '*') {
        done[i - 1] = done[i] = done[i + 1] = 1;
      }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      if(!done[i]) {
        done[i] = done[i + 1] = done[i + 2] = 1;
        ans++;
      }
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
