#include <bits/stdc++.h>

using namespace std;

const int N = 5e8;
const int MAX = 766;

bitset<N> done;
int sa, sb, sc;
map<int, vector<int>> mp;

int win[] = {0, 0, 1, 1, 2, 2};
int lose[] = {1, 2, 0, 2, 0, 1};

int code(int a, int b, int c) {
  return a * MAX * MAX + b * MAX + c;
}

tuple<int, int, int> decode(int num) {
  int a = num / (MAX * MAX);
  num = num % (MAX * MAX);
  int b = num / MAX;
  num = num % MAX;
  int c = num;
  return make_tuple(a, b, c);
}

bool cmp(vector<int> a, vector<int> b) {
  if(a.size() != b.size()) {
    return a.size() < b.size();
  }
  for(int i = 0; i < a.size(); i++) {
    if(a[i] != b[i]) {
      return a[i] < b[i];
    }
  }
  return 0;
}

int main() {
  scanf("%d %d %d", &sa, &sb, &sc);
  done[code(sa, sb, sc)] = 1;
  queue<pair<int, int>> q;
  q.emplace(code(sa, sb, sc), 0);
  
  int costmin = -1;
  vector<int> candidate;
  
  while(!q.empty()) {
    int now, cost, n[3], tn[3];
    vector<int> v, tv;
    
    tie(now, cost) = q.front();
    tie(n[0], n[1], n[2]) = decode(now);
    v = mp[now];
    q.pop();
    
    if(costmin != -1 && cost > costmin) {
      vector<int> best;
      best = mp[candidate[0]];
      for(int i = 1; i < candidate.size(); i++) {
        if(cmp(mp[candidate[i]], best)) {
          best = mp[candidate[i]];
        }
      }
      
      int num[] = {sa, sb, sc};
      printf("%d %d %d\n", num[0], num[1], num[2]);
      for(int i = 0; i < best.size(); i += 2) {
        num[best[i + 1]] -= num[best[i]];
        num[best[i]] += num[best[i]];
        printf("%d %d %d\n", num[0], num[1], num[2]);
      }
      return 0;
    }
    if(cost >= 12) {
      puts("Ok");
      return 0;
    }
    if(n[0] == 0 || n[1] == 0 || n[2] == 0) {
      costmin = cost;
      candidate.push_back(now);
      continue;
    }
    for(int i = 0; i < 6; i++) {
      if(n[win[i]] <= n[lose[i]]) {
        tv = v;
        tv.push_back(win[i]);
        tv.push_back(lose[i]);
        for(int j = 0; j < 3; j++) {
          tn[j] = n[j];
        }
        tn[lose[i]] -= n[win[i]];
        tn[win[i]] += n[win[i]];
        int near = code(tn[0], tn[1], tn[2]);
        if(!done[near]) {
          done[near] = 1;
          mp[near] = tv;
          q.emplace(near, cost + 1);
        } else if(cmp(tv, mp[near])) {
          mp[near] = tv;
        }
      }
    }
  }
  
  return 0;
}
