#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

// true if pair, false if int
bool is[N];
int n;

// -1 if not good
int dfs(int i) {
  if(i >= n) return -1;
  if(is[i] == 0) return i;
  int first = dfs(i + 1);
  if(first == -1) return -1;
  int second = dfs(first + 1);
  if(second == -1) return -1;
  return second;
}

// -1 if not good
int print(int i) {
  if(i >= n) return -1;
  if(is[i] == 0) {
    printf("int");
    return i;
  }
  printf("pair<");
  int first = print(i + 1);
  if(first == -1) return -1;
  printf(",");
  int second = print(first + 1);
  if(second == -1) return -1;
  printf(">");
  return second;
}

int main() {
  ios_base::sync_with_stdio(false);
  
  cin >> n;
  string str;
  
  n = 0;
  while(cin >> str) {
    is[n++] = (str == "pair");
  }
  if(dfs(0) < n - 1) {
    puts("Error occurred");
    return 0;
  }
  print(0);
  return 0;
}
