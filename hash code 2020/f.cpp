#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const double eps = 1e-7;
const int LIB = 1005;
const int DAYS = 705;

int B, L, D;
int score[N];
int ttime[N], ship[N]; // L
vector<int> books[N]; // L
bool done_lib[N];      // L
bool done_book[N];    // B
vector<int> idx[N];   // B

long long pre[LIB][DAYS];
long long sum[DAYS * 2];
vector<pair<int, int> > sorted[N];   // value - book ID // L

long long subs[LIB];

int lib_ans;
vector<int> ans_book[N];
int ans[N]; 

bool func(int l, int r) {
  // printf("l %d r %d\n", l, r);
  return score[l] > score[r];
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
      assert(0 <= v && v < 100000);
      idx[v].push_back(i);
    }
    sort(books[i].begin(), books[i].end(), func);
  }

  for (int i = 0; i < L; i++) {
    vector<int> got;
    for (auto book : books[i]) {
      got.push_back(score[book]);
      sum[i] += score[book];
      // sorted[i].emplace_back(score[book], book);
      assert(0 <= book && book < 100000);
    }
    // sort(sorted[i].begin(), sorted[i].end());
    // reverse(sorted[i].begin(), sorted[i].end());
    // for (int j = 0; j < sorted[i].size(); j++) {
    //   assert(0 <= sorted[i][j].second && sorted[i][j].second < 100000);
    // }

    sort(got.begin(), got.end());
    reverse(got.begin(), got.end());
    memset(sum, 0, sizeof(sum));
    for (int j = 1; j < DAYS; j++) {
      sum[j] = sum[j - 1];
      for (int k = 0; k < ship[i]; k++) {
        int id = (j - 1) * ship[i] + k;
        sum[j] += id < got.size()? got[id] : 0;
      }
    }
    for (int day = 0; day < DAYS; day++) {
      int rem = D - day;
      pre[i][day] = sum[rem];
    }
  }

  int time_now = 0;
  while (time_now < D) {
    int chosen = -1;
    double value = -1;
    vector<pair<double, int>> cur;
    for (int i = 0; i < L; i++) {
      if (done_lib[i]) continue;
      double cur_value = (double) (pre[i][time_now] - subs[i]) / ttime[i];
      cur.emplace_back(cur_value, i);
    }
    sort(cur.begin(), cur.end());
    reverse(cur.begin(), cur.end());
    if (cur.size()) {
      chosen = rand() % min(3, (int)cur.size());
      bool end = time_now > D / 2;
      if (end) chosen = 0;
      chosen = cur[chosen].second;
    }
    // printf("time_now %d choose %d\n", time_now, chosen);
    if (chosen == -1) break;
    done_lib[chosen] = 1;
    ans[lib_ans] = chosen;
    int rem = D - time_now;
    int must_get = rem * ship[chosen];
    // puts("before");
    // printf("chosen %d\n", chosen);
    for (int i = 0; i < (int)books[chosen].size() && (int)ans_book[lib_ans].size() < must_get; i++) {
      int book = books[chosen][i];
      if (done_book[book]) continue;
      ans_book[lib_ans].push_back(book);
      done_book[book] = 1;
      // printf("%d\n", idx[book].size());
      int count = 0;
      for (auto lib : idx[book]) {
        count += 1;
        // printf("%d ", count);
        subs[lib] += score[book];
      }
      // printf("\n");
    }
    time_now += ttime[chosen];
    lib_ans++;
    // puts("done");
  }

  printf("%d\n", lib_ans);
  for (int i = 0; i < lib_ans; i++) {
    printf("%d %d\n", ans[i], ans_book[i].size());
    for (auto it : ans_book[i]) printf("%d ", it);
    printf("\n");
  }


  return 0;
}
