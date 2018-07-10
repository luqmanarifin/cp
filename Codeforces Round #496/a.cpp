#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  vector<int> p;
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j + 1 < n && a[j + 1] == a[j] + 1) j++;
    p.push_back(j - i + 1);
    i = j;
  }
  printf("%d\n", p.size());
  for (auto it : p) printf("%d ", it);

  return 0;
}
