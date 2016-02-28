#include <bits/stdc++.h>

using namespace std;

int c[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int count(int n) {
  int ans = 0;
  while(n > 0) {
    ans += c[n % 10];
    n /= 10;
  }
  return ans;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int ans = 0;
  for(int i = a; i <= b; i++) {
    ans += count(i);
  }
  cout << ans << endl;
  return 0;
}
