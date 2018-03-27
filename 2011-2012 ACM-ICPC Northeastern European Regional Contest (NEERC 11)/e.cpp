#include <bits/stdc++.h>

using namespace std;

const string NAME = "eve";

const int N = 3e5 + 5;

int col[N], anc[N];
char gen[N];
int isalive[N];

int main() {
#ifndef LOCAL
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
#endif
  int n, m;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf(" %c", gen+i);
    col[i] = -i-1;
    anc[i] = i;
    isalive[i] = 1;
  }
  scanf("%d", &m);
  while (m--) {
    int id;
    scanf("%d", &id);
    if (id < 0) {
      isalive[-id] = 0;
    }
    else {
      ++n;
      int z;
      scanf("%d %c", &z, gen+n);
      isalive[n] = 1;
      if (gen[z] != 'F') z = id;
      anc[n] = anc[z];
    }
  }
  int k;
  scanf("%d", &k);
  while (k--) {
    int a, b;
    scanf("%d %d", &a, &b);
    col[anc[a]] = b;
  }
  set<int> vc;
  for (int i = 1; i <= n; ++i) {
    if (!isalive[i]) continue;
    vc.insert(col[anc[i]]);
    // cerr << " col " << col[anc[i]] << endl;
  }
  if (vc.size() <= 1) {
    puts("YES");
    return 0;
  }
  int warna = -1;
  for (int c : vc) {
    if (c > 0)
      warna = c;
  }
  bool ok = 1;
  for (int c : vc) {
    if (c > 0 && warna != c) {
      ok = 0;
    }
  }
  puts(ok ? "POSSIBLY" : "NO");


#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif

  return 0;
}
