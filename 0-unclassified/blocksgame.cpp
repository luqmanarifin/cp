#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int n, b;
int s[N], r[N], c[N];
char d[N];
bool vis[N][N];

long long code(int at) {
  long long ret = at;
  for(int i = 0; i < b; i++) {
    ret = ret * 6 + (d[i] == 'V' ? r[i] : c[i]);
  }
  return ret;
}

int relax(long long val) {
  for(int i = b - 1; i >= 0; i--) {
    if(d[i] == 'V') {
      r[i] = val % 6;
    } else {
      c[i] = val % 6;
    }
    val /= 6;
  }
  return (int) val;
}

bool valid(int i) {
  return 0 <= i && i < n;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    set<long long> done;
    int at;
    scanf("%d %d %d", &at, &n, &b);
    at++;
    for(int i = 0; i < b; i++) {
      scanf("%d %c %d %d", s + i, d + i, r + i, c + i);
    }
    queue<pair<long long, int>> q;
    long long st = code(at);
    done.insert(st);
    q.emplace(st, 0);
    while(!q.empty()) {
      long long now;
      int cost;
      tie(now, cost) = q.front();
      q.pop();
      
      at = relax(now);
      if(at == n - 1) {
        printf("%d\n", cost);
        break;
      }
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          vis[i][j] = 0;
        }
      }
      vis[2][at] = 1;
      vis[2][at - 1] = 1;
      for(int i = 0; i < b; i++) {
        if(d[i] == 'V') {
          for(int j = 0; j < s[i]; j++) {
            vis[r[i] + j][c[i]] = 1;
          }
        } else {
          for(int j = 0; j < s[i]; j++) {
            vis[r[i]][c[i] + j] = 1;
          }
        }
      }
      if(!vis[2][at + 1]) {
        long long near = code(at + 1);
        if(!done.count(near)) {
          done.insert(near);
          q.emplace(near, cost + 1);
        }
      }
      if(valid(at - 2) && !vis[2][at - 2]) {
        long long near = code(at - 1);
        if(!done.count(near)) {
          done.insert(near);
          q.emplace(near, cost + 1);
        }
      }
      for(int i = 0; i < b; i++) {
        if(d[i] == 'V') {
          if(valid(r[i] - 1) && !vis[r[i] - 1][c[i]]) {
            r[i]--;
            long long near = code(at);
            if(!done.count(near)) {
              done.insert(near);
              q.emplace(near, cost + 1);
            }            
            r[i]++;
          }
          if(valid(r[i] + s[i]) && !vis[r[i] + s[i]][c[i]]) {
            r[i]++;
            long long near = code(at);
            if(!done.count(near)) {
              done.insert(near);
              q.emplace(near, cost + 1);
            }  
            r[i]--;
          }
        } else {
          if(valid(c[i] - 1) && !vis[r[i]][c[i] - 1]) {
            c[i]--;
            long long near = code(at);
            if(!done.count(near)) {
              done.insert(near);
              q.emplace(near, cost + 1);
            }            
            c[i]++;
          }
          if(valid(c[i] + s[i]) && !vis[r[i]][c[i] + s[i]]) {
            c[i]++;
            long long near = code(at);
            if(!done.count(near)) {
              done.insert(near);
              q.emplace(near, cost + 1);
            }  
            c[i]--;
          }
        }
      }
    }
  }
  
  return 0;
}
