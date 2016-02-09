#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n, k, mod;
char s[N];

int main() {
  scanf("%d %d", &n, &mod);
  scanf("%s", s);
  if(mod == 2) {
    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] != 'A' + i % 2) a++;
      else b++;
    }
    if(a < b) {
      cout << a << endl;
      for(int i = 0; i < n; i++) {
        printf("%c", 'A' + i % 2);
      }
    } else {
      cout << b << endl;
      for(int i = 0; i < n; i++) {
        printf("%c", 'A' + 1 - i % 2);
      }
    }
    printf("\n");
    return 0;
  }
  for(int i = 0; i < n; i++) {
    s[i] -= 'A';
  }
  
  int ans = 0;
  for(int i = 0; i < n; ) {
    int j = i + 1;
    while(s[j] == s[i] && j < n) j++;
    ans += (j - i) / 2;
    for(int k = i + 1; k < j; k += 2) {
      while(s[k - 1] == s[k] || (k + 1 < n && s[k] == s[k + 1])) {
        s[k]++;
        s[k] %= mod;
      }
    }
    i = j;
  }
  for(int i = 0; i < n; i++) {
    s[i] += 'A';
  }
  cout << ans << endl;
  printf("%s\n", s);
  return 0;
}