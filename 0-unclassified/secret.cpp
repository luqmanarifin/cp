#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N], n;

int to_sorted[N];
int to_nature[N];

bool done(int i, int d) {
  bool lef = (i == 0 || a[i - 1] < a[i] - d);
  bool rig = (i == n - 1 || a[i] + d < a[i + 1]);
  return lef && rig;
}

int front(int, int);
int back(int, int);

int front(int i, int d) {
  if(done(i, d)) {
    return i;
  }
  int id = upper_bound(a, a + n, a[i] + d) - a - 1;
  long long rot = 2 * abs(a[i] - a[id]);
  bool safe = (i == 0 || a[i - 1] < a[i] - (d - rot));
  if(safe && d >= rot) {
    return front(i, d % rot);
  }
  return back(id, d - abs(a[i] - a[id]));
}

int back(int i, int d) {
  if(done(i, d)) {
    return i;
  }
  int id = lower_bound(a, a + n, a[i] - d) - a;
  long long rot = 2 * abs(a[i] - a[id]);
  bool safe = (i == n - 1 || a[i] + d - rot < a[i + 1]);
  if(safe && d >= rot) {
    return back(i, d % rot);
  }
  return front(id, d - abs(a[i] - a[id]));
}

int main() {
  int m;
  scanf("%d %d", &n, &m);
  vector<pair<int, int>> p;
  for(int i = 0; i < n; i++) {
    scanf("%I64d", a + i);
    p.emplace_back(a[i], i);
  }
  sort(a, a + n);
  sort(p.begin(), p.end());
  for(int i = 0; i < n; i++) {
    to_sorted[p[i].second] = i;
    to_nature[i] = p[i].second;
  }
  
  while(m--) {
    int id, l;
    scanf("%d %d", &id, &l);
    id = to_sorted[id - 1];
    printf("%d\n", to_nature[front(id, l)] + 1);
  }
  return 0;
}
