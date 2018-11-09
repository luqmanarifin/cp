#include <bits/stdc++.h>

using namespace std;

const int N = 205;

bool com[N];
bool semi[N];
bool ans[N];

int main() {
  com[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!com[i]) {
      for (int j = i * i; j < N; j += i) {
        com[j] = 1;
      }
    }
  }
  for (int i = 2; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (!com[i] && !com[j] && i * j < N) {
        semi[i * j] = 1;
      } 
    }
  }
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      if (semi[i] && semi[j] && i + j < N) {
        ans[i + j] = 1;
      }
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    puts(ans[n]? "YES" : "NO");
  }
  
  return 0;
}
