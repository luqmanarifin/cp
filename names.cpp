#include <bits/stdc++.h>

using namespace std;

char s[105][105];
vector<int> edge[30];
int got[30];
bool done[30];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for(int i = 0; i < n - 1; i++) {
    int aa = strlen(s[i]);
    int bb = strlen(s[i + 1]);
    for(int j = 0; j < min(aa, bb); j++) {
      if(s[i][j] != s[i + 1][j]) {
        edge[s[i][j] - 'a'].push_back(s[i + 1][j] - 'a');
        got[s[i + 1][j] - 'a']++;
        break;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      if(strlen(s[i]) <= strlen(s[j])) {
        continue;
      }
      bool pre = 1;
      int len = strlen(s[j]);
      for(int k = 0; k < len; k++) {
        if(s[i][k] != s[j][k]) {
          pre = 0;
        }
      }
      if(pre) {
        puts("Impossible");
        return 0;
      }
    }
  }
  queue<int> q;
  vector<int> topo;
  int edges = 0;
  for(int i = 0; i < 26; i++) {
    edges += edge[i].size();
    if(got[i] == 0) {
      q.push(i);
    }
  }
  while(!q.empty()) {
    int now = q.front();
    topo.push_back(now);
    q.pop();
    for(auto it : edge[now]) {
      got[it]--;
      if(got[it] == 0) {
        q.push(it);
      }
    }
    edges -= edge[now].size();
  }
  if(edges) {
    puts("Impossible");
    return 0;
  }
  for(auto it : topo) {
    done[it] = 1;
    printf("%c", it + 'a');
  }
  for(int i = 0; i < 26; i++) {
    if(!done[i]) {
      printf("%c", i + 'a');
    }
  }
  printf("\n");
  return 0;
}