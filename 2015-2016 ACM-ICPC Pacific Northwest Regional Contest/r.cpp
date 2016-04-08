#include <bits/stdc++.h>

using namespace std;

struct name {
  string first, second;
  bool operator<(const name& other) const {
    if(second != other.second) return second < other.second;
    return first < other.first;
  }
};

name a[105];

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a, a + n);
  for(int i = 0; i < n; i++) {
    printf("%s %s\n", a[i].first.c_str(), a[i].second.c_str());
  }
  return 0;
}