#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N], ans[N];

int main() {
  gets(s);
  int n = strlen(s);
  int t;
  scanf("%d", &t);
  int mul = 1, sum = 0;
  for(int tt = 0; tt < t; tt++) {
    int num;
    scanf("%d", &num);
    sum += mul * num;
    mul *= -1;
    sum %= n;
  }
  if(sum < 0) sum += n;
  for(int i = 0; i < n; i++) {
    ans[i] = s[(i + sum) % n];
  }
  if(t % 2) {
    reverse(ans, ans + n);
  }
  for(int i = 0; i < n; i++) printf("%c", ans[i]);
  return 0;
}