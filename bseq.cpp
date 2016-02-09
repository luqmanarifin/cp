#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];
int a[N];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for(int i = 0; i < N; i++) {
    a[i] = i + 1;
  }
  for(int i = 1; i <= n; i++) {
    if(s[a[i - 1] - 1] == '(' && s[i] == ')') {
      a[i] = a[i - 1] - 1;
      int j = a[i];
      while(a[j - 1] < j - 1) {
        a[i] = j = a[j - 1];
      }
    }
  }
  int ans = 0, cnt = 0;
  for(int i = 1; i <= n; i++) {
    if(ans < i - a[i] + 1) {
      ans = i - a[i] + 1;
      cnt = 1;
    } else if(ans == i - a[i] + 1) {
      cnt++;
    }
  }
  if(ans < 2) {
    cnt = 1;
  }
  printf("%d %d\n", ans, cnt);
  return 0;
}
