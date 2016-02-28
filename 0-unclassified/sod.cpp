#include <bits/stdc++.h>

using namespace std;

int ans[400];
int n;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int dig;
    scanf("%d", &dig);
    int low = 0;
    for(int i = 0; i < n; i++) {
      low += ans[i];
    }
    for(int i = 0; ; i++) {
      if(i + 1 > n) n = i + 1;
      if(ans[i] == 9) {
        low -= ans[i];
        continue;
      }
      int hig = low - ans[i];
      hig += (i + 1) * 9;
      low++;
      if(low <= dig && dig <= hig) {
        low -= ans[i] + 1;
        for(int j = ans[i] + 1; j <= 9; j++) {
          if(low + j <= dig && dig <= low + j + i * 9) {
            ans[i] = j;
            int rem = dig - (low + j);
            for(int k = 0; k < i; k++) {
              ans[k] = 0;
            }
            for(int k = 0; k < i; k++) {
              int at = min(rem, 9);
              ans[k] = at;
              rem -= at;
            }
            break;
          }
        }
        break;
      }
      low -= ans[i] + 1;
    }
    for(int i = n - 1; i >= 0; i--) {
      printf("%d", ans[i]);
    }
    printf("\n");
    
  }
  
  return 0;
}