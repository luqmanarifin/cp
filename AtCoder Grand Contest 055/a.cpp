#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int N = 2e5 + 5;

char s[3 * N];
int ans[3 * N];
ordered_set at[3];

void remove(int i, int l, int r, int flag) {
  vector<int> to;
  for (int j = l; j <= r; j++) {
    to.push_back(*at[i].find_by_order(j));
  }
  for (auto it : to) {
    at[i].erase(it);
    ans[it] = flag;
    // printf("remove %d: %d\n", i, it);
  }
}

bool try_solve(int s, int f, int num, int flag) {
  // printf("%d %d %d %d\n", s, f, num, flag);
  int size = at[s].size();

  int mid = 3 - s - f;
  auto last_s = *at[s].find_by_order(num - 1);
  auto first_f = *at[f].find_by_order(size - num);
  auto idx = at[mid].order_of_key(last_s + 1);
  if (idx + num - 1 < size && *at[mid].find_by_order(idx+num-1) < first_f) {
    if (flag) {
      remove(s, 0, num - 1, flag);
      remove(f, size - num, size - 1, flag);
      remove(mid, idx, idx + num - 1, flag);
    }
    return true;
  } else {
    return false;
  }
}

int main() {
  int n;
  scanf("%d %s", &n, s);
  for (int i = 0; i < 3 * n; i++) {
    at[s[i] - 'A'].insert(i);
  }
  int done = 0, id = 0;
  while (done < n) {
    vector<pair<int, int>> fir, las;
    for (int i = 0; i < 3; i++) {
      fir.emplace_back(*at[i].find_by_order(0), i);
      las.emplace_back(*at[i].find_by_order(n - done - 1), i);
    }
    sort(fir.begin(), fir.end());
    sort(las.begin(), las.end());
    reverse(las.begin(), las.end());
    if (fir[0].second == las[0].second) {
      swap(las[0], las[1]);
    }
    int s = fir[0].second;
    int f = las[0].second;
    int l = 1, r = n - done;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (try_solve(s, f, mid, 0)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    id++;
    done += l;
    assert(try_solve(s, f, l, id));
  }
  assert(id <= 6);
  for (int i = 0; i < 3 * n; i++) printf("%d", ans[i]); printf("\n");
  return 0;
}
