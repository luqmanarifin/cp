#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

#define ll unsigned long long

ll a[N];
vector<int> num;
vector<int> at[100];

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i < n; i++) {
    ll t = (a[i] ^ a[i - 1]);
    for(int j = 0; j < 64; j++) {
      if(t & (1LL << j)) {
        num.push_back(j);
        break;
      }
    }
  }
  for(int i = 0; i < num.size(); i++) {
    at[num[i]].push_back(i);
  }
  for(int i = 0; i < 64; i++) {
    for(auto it : at[i]) {
      for(auto jt : at[i]) {
        if(abs(it - jt) > 1) {
          puts("Dapat");
          return 0;
        }
      }
    }
  }
  puts("Tidak");
  return 0;
}
