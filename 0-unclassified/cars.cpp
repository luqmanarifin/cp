#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int turned[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      int a;
      scanf("%d", &a);
      if(i == j) continue;
      if(a == 1) turned[i] = 1;
      else if(a == 2) turned[j] = 1;
      else if(a == 3) turned[i] = turned[j] = 1;
    } 
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(!turned[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  for(int i = 1; i <= n; i++) {
    if(!turned[i]) {
      printf("%d ", i);
    }
  }
  
  return 0;
}
