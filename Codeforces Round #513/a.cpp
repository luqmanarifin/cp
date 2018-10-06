#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];

int cnt[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  for (int i = 0; i < n; i++) {
    cnt[s[i] - '0']++;
  }   
  int all = n;
  cout << min(cnt[8], all / 11) << endl;
  return 0;
}
