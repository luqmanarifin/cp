
#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int MAX = 5e6 + 5;

int a[N], b[N];
bool ada[MAX];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i), ada[a[i]] = 1;
  for (int i = 0; i < n; i++) scanf("%d", b + i), ada[b[i]] = 1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (ada[a[i] ^ b[j]]) ans++;
    }
  }
  puts(ans % 2? "Koyomi" : "Karen");

  return 0;
}
