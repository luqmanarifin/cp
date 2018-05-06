
#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  int now = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j + 1 < n && a[j + 1] == a[j]) j++;
    int ada = j - i + 1;
    now = max(0, now - ada);
    now += ada;
    i = j;
  }
  cout << now << endl;
  return 0;
}
