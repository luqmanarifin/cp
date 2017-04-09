#include <bits/stdc++.h>

using namespace std;

const int N = 25;

char s[N];

string solve() {
  //printf("%s\n", s);
  int n = strlen(s);
  bool done = 0;
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] > s[i+1]) {
      int j = i;
      while (j > 0 && s[j-1] == s[j]) j--;
      if (j == 0 && s[j] == '1') {
        for (int i = 0; i < n - 1; i++) s[i] = '9';
        s[n - 1] = 0;
      } else {
        for (int k = j; k <= j; k++) s[k]--;
        for (int k = j + 1; k < n; k++) s[k] = '9';
      }
      done = 1;
      break;
    }
  }
  return (string) s;
}

int fill(int n) {
  if (n < 10) {
    s[0] = n + '0';
    return 0;
  }
  int last = fill(n / 10) + 1;
  s[last] = (n % 10) + '0';
  return last;
}

int main() {
  int t = 1000;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(s, 0, sizeof(s));
    fill(tt);
    
    scanf("%s", s);
    printf("Case #%d: %s\n", tt, solve().c_str());
    cerr << tt << " done!" << endl;
  }

  return 0;
}
