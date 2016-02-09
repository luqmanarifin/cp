#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

deque<int> a;
char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  a.push_back(1);
  auto now = a.begin();
  int dir = 1;
  for(int i = 0; i < n - 1; i++) {
    now = find(a.begin(), a.end(), i + 1);
    if(dir == 1) {
      if(i >= 2) if(s[i] == s[i - 1] && s[i] != s[i - 2]) {
        now = find(a.begin(), a.end(), i - 1);
      }
      now++;
      a.insert(now, i + 2);
    } else {
      if(i >= 2) if(s[i] == s[i - 1] && s[i] != s[i - 2]) {
        now = find(a.begin(), a.end(), i - 1);
      }
      a.insert(now, i + 2);
    }
    if(i + 1 < n - 1 && s[i] == s[i + 1]) {
      dir ^= 1;
    }
  }
  for(int i = 0; i < a.size(); i++) {
    if(i) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
  return 0;
}
