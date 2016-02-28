#include <bits/stdc++.h>

using namespace std;

int low, high;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    low += max(0, a * 100 - 50);
    high += min(10000, a * 100 + 49);
  }
  puts(low <= 10000 && 10000 <= high? "NO" : "YES");
  return 0;
}
