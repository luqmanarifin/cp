#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N];
bool done[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  reverse(a, a + n);
  int udah = 0;
  int ans = 0;
  while(udah < n) {
    ans++;
    int last = 1e9;
    for(int i = 0; i < n; i++) {
      if(!done[i] && a[i] < last) {
        done[i] = 1;
        last = a[i];
        udah++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}