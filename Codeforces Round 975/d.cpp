#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], val[N];
vector<int> at[N];
map<int, int> mp;
bool ok[N];

int mat[2][2];  // size segment - pos
int size_ans;

int tax() {
  if (mat[0][0] == 0 && mat[0][1] == 0 && mat[1][0] == 0) return 1;
  return 0;
}

tuple<int, int, int, int> combine(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
  int lena = get<1>(a) - get<0>(a) + 1;
  int lenb = get<1>(b) - get<0>(b) + 1;
  int l = get<2>(b);
  int r = get<3>(b);
  if (lena % 2) {
    swap(l, r);
  }
  mat[lena % 2][0] -= get<2>(a);
  mat[lena % 2][1] -= get<3>(a);
  mat[lenb % 2][0] -= get<2>(b);
  mat[lenb % 2][1] -= get<3>(b);
  size_ans -= (lena + 1) / 2;
  size_ans -= (lenb + 1) / 2;
  int len = lena + lenb;

  int mat0 = get<2>(a) + l;
  int mat1 = get<3>(a) + r;
  mat[len % 2][0] += mat0;
  mat[len % 2][1] += mat1;
  size_ans += (len + 1) / 2;
  return make_tuple(get<0>(a), get<1>(b), mat0, mat1);
}

void print(tuple<int, int, int, int> a) {
  printf("%d %d %d %d", get<0>(a), get<1>(a), get<2>(a), get<3>(a));
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    mp.clear();

    int n;
    scanf("%d", &n);
    set<int> uni;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      uni.insert(a[i]);
    }
    int max_id = 0;
    for (auto it : uni) {
      val[max_id] = it;
      mp[it] = max_id++;
    }
    for (int i = 0; i < n; i++) at[mp[a[i]]].push_back(i);

    // construct base
    set<tuple<int, int, int, int>> s;
    mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0;
    size_ans = 0;

    int mx = val[max_id - 1];
    for (int i = 0; i < n; i++) {
      if (a[i] != mx) continue;
      int r = i;
      while (r + 1 < n && a[r + 1] == a[r]) r++;
      int len = r - i + 1;
      
      s.insert(make_tuple(i, r, (len + 1) / 2, len / 2));
      size_ans += (len + 1) / 2;
      mat[len % 2][0] += (len + 1) / 2;
      mat[len % 2][1] += len / 2;

      for (int j = i; j <= r; j++) ok[j] = 1;

      i = r;
    }
    int ans = 2 * mx + size_ans;

    for (int id = max_id - 2; id >= 0; id--) {
      for (auto x : at[id]) {
        bool first = 1;
        auto cur = make_tuple(x, x, 0, 0);
        if (x > 0 && ok[x-1]) {
          auto it = s.lower_bound(cur);
          it--;
          if (first) {
            size_ans++;
            s.insert(cur);
            first = 0;
          }
          auto nex = combine(*it, cur);
          s.erase(*it);
          s.erase(cur);
          s.insert(nex);

          cur = nex;
        }
        if (x + 1 < n && ok[x+1]) {
          auto it = s.lower_bound(cur);
          it++;
          if (first) {
            it--;
            size_ans++;
            s.insert(cur);
            first = 0;
          }
          auto nex = combine(cur, *it);
          s.erase(*it);
          s.erase(cur);
          s.insert(nex);
        }
        if (first) {
          size_ans++;
          s.insert(cur);
          first = 0;
        }

        ok[x] = 1;
      }
      int cur_ans = val[id] + mx + size_ans - tax();
      ans = max(ans, cur_ans);
    }
    printf("%d\n", ans);

    for (int i = 0; i < n; i++) {
      at[i].clear();
      ok[i] = 0;
    }
  }

  return 0;
}
