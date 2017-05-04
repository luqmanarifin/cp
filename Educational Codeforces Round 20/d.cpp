#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N], lines, k;
string str;

bool can(int len) {
  int cur = 0;
  for (int i = 0; i < k; i++) {
    int now = a[i], j = i;
    while (j + 1 < k && now + a[j + 1] <= len) {
      now += a[j + 1];
      j++;
    }
    cur++;
    if (cur > lines || now > len) return 0;
    i = j;
  }
  return cur <= lines;
}

int main() {
  cin >> lines;
  cin.ignore();
  
  getline(cin, str);
  for (int i = 0; i < str.length(); i++) {
    int j = i;
    while (j + 1 < str.length() && str[j] != ' ' && str[j] != '-') j++;
    a[k++] = j - i + 1; 
    i = j;
  }
  //for (int i = 0; i < k; i++) printf("%d ", a[i]); printf("\n");
  
  int l = 1, r = N;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}
