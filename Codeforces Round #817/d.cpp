#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    vector<int> a;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      int l = i;
      int r = n - i - 1;
      if (s[i] == 'L') {
        sum += l;
        a.push_back(max(0, r - l));
      } else {
        sum += r;
        a.push_back(max(0, l - r));
      }
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      sum += a[i];
      printf("%lld%c", sum, i == n - 1? '\n' : ' ');
    }
  }

  return 0;
}
