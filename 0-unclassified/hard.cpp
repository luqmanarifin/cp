#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int par[N];
int a[N];
int d[N][N];
int st[N];

int find(int u) {
  return par[u] == u? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  for(int i = 0; i < N; i++) {
    par[i] = i;
  }
  
  int n;
  scanf("%d", &n);
  set<pair<int, int>> s;
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    sum += a[i];
    s.insert(make_pair(a[i], i));
  }
  if(sum % 2) {
    puts("No");
    return 0;
  }
  for(int i = 0; i < n; i++) {
    if(sum - a[i] < a[i]) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  
  for(int it = 0; it < n - 1; it++) {
    auto now = (s.begin())->second;
    auto sec = (s.rbegin())->second;
    
    d[now][sec]++; d[sec][now]++;
    a[now]--;
    a[sec]--;
    //printf("merge %d %d\n", now, sec);
    s.erase(*(s.begin()));
    s.erase(*(s.rbegin()));
    if(a[sec]) s.insert(make_pair(a[sec], sec));
  }
  
  sum -= 2 * (n - 1);
  
  vector<pair<int, int>> lef, rig, p;
  for(int i = 0; i < n; i++) {
    if(a[i]) {
      p.emplace_back(a[i], i);
      //printf("dada %d %d\n", a[i], i);
    }
  }
  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  long long now = 0, cnt = 0;
  for(int i = 0; i < p.size(); i++) {
    if(now + p[i].first <= sum / 2) {
      lef.push_back(p[i]);
      now += p[i].first;
    } else {
      lef.emplace_back(sum / 2 - now, p[i].second);
      rig.emplace_back(p[i].first - lef.back().first, p[i].second);
      for(int j = i + 1; j < p.size(); j++) {
        rig.push_back(p[j]);
      }
      break;
    }
  }
  /*
  puts("JNA");
  for(auto it : lef) {
    printf("%d %d\n", it.first, it.second);
  }
  printf("\n");
  puts("JNB");
  for(auto it : rig) {
    printf("%d %d\n", it.first, it.second);
  }
  printf("\n\n");
  */
  for(int i = 0, j = 0; i < lef.size() && j < rig.size(); ) {
    int add = min(lef[i].first, rig[j].first);
    d[lef[i].second][rig[j].second] += add;
    d[rig[j].second][lef[i].second] += add;
    lef[i].first -= add;
    rig[j].first -= add;
    if(lef[i].first == 0) i++;
    if(rig[j].first == 0) j++;
  }  
  
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      printf("%d ", d[i][j]);
    }
    printf("\n");
  }
  return 0;
}