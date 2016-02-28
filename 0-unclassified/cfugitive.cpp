#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

#define x first
#define y second

vector<pair<pair<long long, long long>, int>> need;
pair<long long, long long> p[N];
int ans[N];
pair<long long, int> a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%I64d %I64d", &p[i].x, &p[i].y);
  }
  for(int i = 0; i < m; i++) {
    scanf("%I64d", &a[i].x);
    a[i].y = i;
  }
  for(int i = 1; i < n; i++) {
    long long bg = p[i].y - p[i - 1].x;
    long long sm = p[i].x - p[i - 1].y;
    need.push_back({{sm, bg}, i - 1});
  }
  sort(need.begin(), need.end());
  sort(a, a + m);
  
  set<pair<long long, int>> ada;
  int in = 0;
  for(int i = 0; i < m; i++) {
    while(in < need.size() && need[in].x.x <= a[i].x) {
      ada.insert({need[in].x.y, need[in].y});
      in++;
    }
    if(!ada.empty()) {
      set<pair<long long, int>>::iterator it = ada.begin();
      if(it->first < a[i].x) {
        puts("No");
        return 0;
      }
      ans[it->second] = a[i].y;
      ada.erase(it);
    }
  }
  if(!ada.empty() || in != need.size()) {
    puts("No");
    return 0;
  }
  puts("Yes");
  for(int i = 0; i < n - 1; i++) {
    printf("%d ", ans[i] + 1);
  }
  
  return 0;
}
