#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

long long ans[N];
long long dua[N];
long long lima[N];

int main() {
  for(int i = 1; i < N; i++) {
    int num = i;
    dua[i] = dua[i - 1];
    lima[i] = lima[i - 1];
    while(num % 2 == 0) {
      dua[i] += i;
      num /= 2;
    }
    while(num % 5 == 0) {
      lima[i] += i;
      num /= 5;
    }
  }
  
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    printf("%I64d\n", min(dua[n], lima[n]));
  }
  
  return 0;
}
