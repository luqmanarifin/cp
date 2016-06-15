#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n;
    scanf("%lld", &n);
    n--;
    if(n == 0) {
      puts("0");
      continue;
    }
    vector<int> a;
    while(n) {
      a.push_back(n % 5);
      n /= 5;
    }
    for(int i = a.size() - 1; i >= 0; i--) {
      printf("%d", a[i] * 2);
    }
    printf("\n");
  }
  return 0;
}
