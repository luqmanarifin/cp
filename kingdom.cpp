// hi judge, please accept me >.<
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9 + 10;

vector<int> v[N << 2];
int lef[N << 2];
int rig[N << 2];

pair<int, int> point[N];
int px[N];
int py[N];

void build(int p, int l, int r) {
  v[p].resize(r - l + 1);
  if(l == r) {
    v[p][0] = point[l].second;
    lef[p] = point[l].first;
    rig[p] = point[l].first;
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
  lef[p] = lef[p + p];
  rig[p] = rig[p + p + 1];
  merge(v[p + p].begin(), v[p + p].end(), v[p + p + 1].begin(), v[p + p + 1].end(), v[p].begin());
}

int find(int p, int xl, int xr, int yd, int yu) {
  if(rig[p] < xl || xr < lef[p]) return 0;
  if(xl <= lef[p] && rig[p] <= xr) return upper_bound(v[p].begin(), v[p].end(), yu) - lower_bound(v[p].begin(), v[p].end(), yd);
  return find(p + p, xl, xr, yd, yu) + find(p + p + 1, xl, xr, yd, yu);
}

int a[10];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", &point[i].first, &point[i].second);
  }
  sort(point + 1, point + 1 + n);
  for(int i = 1; i <= n; i++) {
    px[i] = point[i].first;
    py[i] = point[i].second;
  }
  sort(py + 1, py + 1 + n);
  for(int i = 1; i <= 9; i++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + 10);
  build(1, 1, n);
  do {
    int u = a[1] + a[2] + a[3];
    int d = a[7] + a[8] + a[9];
    int l = a[1] + a[4] + a[7];
    int r = a[3] + a[6] + a[9];
    int xl = px[l], xr = px[n - r + 1], yd = py[d], yu = py[n - u + 1];
    if(px[l] == px[l + 1] || px[n - r] == px[n - r + 1]) continue;
    if(py[d] == py[d + 1] || py[n - u] == py[n - u + 1]) continue;
    if(find(1, -inf, xl, yu, inf) != a[1]) continue;
    if(find(1, xr, inf, yu, inf) != a[3]) continue;
    if(find(1, -inf, xl, -inf, yd) != a[7]) continue;
    if(find(1, xr, inf, -inf, yd) != a[9]) continue;
    printf("%.15lf %.15lf\n%.15lf %.15lf\n", xl+.5, xr-.5, yd+.5, yu-.5);
    return 0;
  } while(next_permutation(a + 1, a + 10));
  puts("-1");
  return 0;
}
