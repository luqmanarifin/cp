#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int big = 1e6 + 6;

#define x first
#define y second
#define mp make_pair

// island
vector<pair<pair<long long, long long>, int>> need;

// position
pair<long long, long long> p[N];
vector<long long> pos;
pair<long long, int> ladder[N];

int ans[N];

int id(long long a) {
  return lower_bound(pos.begin(), pos.end(), a) - pos.begin();
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%I64d %I64d", &p[i].first, &p[i].second);
  }
  sort(p, p + n);
  for(int i = 1; i < n; i++) {
    long long sm = p[i].x - p[i - 1].y;
    long long bg = p[i].y - p[i - 1].x;
    pos.push_back(sm);
    pos.push_back(bg);
    need.push_back({{sm, bg}, i - 1});
  }
  sort(need.begin(), need.end());
  for(int i = 0; i < m; i++) {
    scanf("%I64d", &ladder[i].x);
    ladder[i].y = i;
    pos.push_back(ladder[i].x);
  }
  sort(ladder, ladder + m);
  sort(pos.begin(), pos.end());
  pos.resize(distance(pos.begin(), unique(pos.begin(), pos.end())));
  
  // ladder
  set<pair<long long, int>> ava;
  int in = 0, il = 0;
  for(int iter = 0; iter < pos.size(); iter++) {
    while(in < need.size() && need[in].x.x == pos[iter]) {
      ava.insert({need[in].x.y, need[in].y});
      in++;
    }
    while(il < m && ladder[il].x == pos[iter]) {
      if(!ava.empty()) {
        set<pair<long long, int>>::iterator it = ava.begin();
        if(it->first < pos[iter]) {
          puts("No");
          return 0;
        }
        ans[it->second] = ladder[il].second;
        ava.erase(it);
      }
      il++;
    }
  }
  if(!ava.empty()) {
    puts("No");
    return 0;
  }
  puts("Yes");
  for(int i = 0; i < n - 1; i++) {
    printf("%d ", ans[i] + 1);
  }
  return 0;
}
