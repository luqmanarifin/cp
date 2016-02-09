#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int lim = 305;

int ada[N];
bool udah[N];
int w[N];

int main() {
  int m, t, r;
  scanf("%d %d %d", &m, &t, &r);
  for(int i = 0; i < m; i++) {
    scanf("%d", w + i);
  }
  int ans = 0;
  for(int i = 0; i < m; i++) {
    if(i) {
      for(int j = w[i - 1] + 1; j <= w[i]; j++) {
        ada[j + lim] += ada[j + lim - 1];
      }
    }
    int rem = max(0, r - ada[w[i] + lim]);
    ans += rem;
    for(int j = w[i] - 1; j >= w[i] - t && rem; j--) {
      if(!udah[j + lim]) {
        udah[j + lim] = 1;
        ada[w[i] + lim]++;
        ada[j + lim + t + 1]--;
        rem--;
      }
    }
    if(ada[w[i] + lim] < r) {
      puts("-1");
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}