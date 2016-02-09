#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];
int cnt[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    cnt[a[i]]++;
  }
  int ans = -1;
  for(int i = 6; i >= 1; i--) if(cnt[i] == 1) {
    ans = i;
    break;
  }
  if(ans == -1) {
    puts("none");
    return 0;
  }
  for(int i = 0; i < n; i++) {
    if(a[i] == ans) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
