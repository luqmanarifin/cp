#include <bits/stdc++.h>

using namespace std;

long long lef[2005], rig[2005];
char s[2005];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for(int mid = 1; mid <= n; mid++) {
    for(int i = 0; mid + i <= n && mid - i >= 1; i++) {
      if(s[mid + i] != s[mid - i]) {
        break;
      } else {
        lef[mid + i]++;
        rig[mid - i]++;
      }
    }
  }
  for(int mid = 1; mid <= n; mid++) {
    for(int i = 0; mid - i >= 1 && mid + 1 + i <= n; i++) {
      if(s[mid - i] != s[mid + 1 + i]) {
        break;
      } else {
        lef[mid + 1 + i]++;
        rig[mid - i]++;
      }
    }
  }
  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
      ans += lef[i] * rig[j];
    }
  }
  cout << ans << endl;
  return 0;
}
