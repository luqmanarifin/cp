#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const double eps = 1e-7;

int B, L, D;
int score[N];
int ttime[N], ship[N]; // L
vector<int> books[N]; // L
bool done[N];

vector<int> idx[N];

long long sum[N];
set<pair<double, int> > pq;   // (sum/D), id

int lib_ans;
vector<int> ans_book[N];
int ans[N]; 

double get_value(int lib) {
  return -(double)sum[lib] / ttime[lib];
}

void update(int lib, int book) {
  double value = get_value(lib) - eps;
  auto it = pq.lower_bound(make_pair(value, -1));
  while (it->second != lib) {
    // printf ("tai %.6f %d find %d\n", it->first, it->second, lib);
    it++;
  }
  // puts("done update");
  pq.erase(it);
  sum[lib] -= score[book];
  double new_value = -(double)sum[lib] / ttime[lib];
  pq.insert(make_pair(new_value, lib));
}

int main() {
  scanf("%d %d %d", &B, &L, &D);
  for (int i = 0; i < B; i++) {
    scanf("%d", score + i);
  }
  for (int i = 0; i < L; i++) {
    int k;
    scanf("%d %d %d", &k, &ttime[i], &ship[i]);
    while (k--) {
      int v;
      scanf("%d", &v);
      books[i].push_back(v);
      idx[v].push_back(i);
    }
  }
  // printf("asu\n");
  for (int i = 0; i < L; i++) {
    for (auto it : books[i]) {
      sum[i] += score[it];
    }
    pq.insert(make_pair(get_value(i), i));
  }
  // auto it = pq.begin();
  // while (it != pq.end()) {
  //   printf("%.3f %d\n", it->first, it->second);
  //   it++;
  // }
  // return 0;
  // printf("asu\n");
  long long ttime_now = 0;
  while (ttime_now < D && !pq.empty()) {
    auto it = pq.begin();
    pq.erase(it);
    int lib = it->second;
    if (ttime_now + ttime[lib] > D) {
      continue;
    }
    // printf("process %d\n", lib);
    vector<int> now;
    for (auto book : books[lib]) {
      if (done[book]) continue;
      done[book] = 1;
      now.push_back(book);
      for (auto other_lib : idx[book]) {
        if (other_lib != lib) {
          update(other_lib, book);
        }
      }
    }
    if (!now.empty()) {
      ans[lib_ans] = lib;
      ans_book[lib_ans] = now;
      lib_ans++;
    }
  }
  printf("%d\n", lib_ans);
  for (int i = 0; i < lib_ans; i++) {
    printf("%d %d\n", ans[i], ans_book[i].size());
    for (auto it : ans_book[i]) printf("%d ", it);
    printf("\n");
  }


  return 0;
}
