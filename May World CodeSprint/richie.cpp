#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> a;
char s[N];
bool done[N];

int main() {
  int n, k;
  scanf("%d %d %s", &n, &k, s);
  int half = n / 2;
  for(int i = 0; i < half; i++) {
    if(s[i] != s[n - 1 - i]) {
      k--;
      s[i] = s[n - 1 - i] = max(s[i], s[n - 1 - i]);
      done[i] = 1;
    }
  }
  if(k < 0) {
    puts("-1");
    return 0;
  }
  for(int i = 0; i < half; i++) {
    if(done[i] && k >= 1 && s[i] != '9') {
      s[i] = s[n - 1 - i] = '9';
      k--;
    }
    if(!done[i] && k >= 2 && s[i] != '9') {
      s[i] = s[n - 1 - i] = '9';
      k -= 2;
    }
  }
  if(n % 2 && s[n / 2] != '9' && k >= 1) {
    s[n / 2] = '9';
  }
  printf("%s\n", s);
  return 0;
}