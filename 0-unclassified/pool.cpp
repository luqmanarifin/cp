#include <bits/stdc++.h>

using namespace std;

const int N = 12345679;

int b[N], y[N];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> np, nq;
  for(int i = 0; i < n; i++) {
    scanf("%d %d", b + i, y + i);
    np.push_back(b[i]);
    nq.push_back(y[i]);
  }
  sort(np.begin(), np.end());
  sort(nq.begin(), nq.end());
  np.resize(distance(np.begin(), unique(np.begin(), np.end())));
  nq.resize(distance(nq.begin(), unique(nq.begin(), nq.end())));
  if(np.size() != 2 || nq.size() != 2) {
    puts("-1");
    return 0;
  }
  int nb = 1e9, mb = -1e9, ny = 1e9, my = -1e9;
  for(int i = 0; i < n; i++) {
    nb = min(nb, b[i]);
    mb = max(mb, b[i]);
    ny = min(ny, y[i]);
    my = max(my, y[i]);
  }
  printf("%d\n", (mb - nb) * (my - ny));
  return 0;
}
