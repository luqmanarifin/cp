#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    if(n == 1) {
      puts("Bob");
    } else {
      puts("Alice");
    }
  }
  return 0;
}