#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
bool done[N];

int main() {
  freopen("highcard.in","r",stdin);
  freopen("highcard.out","w",stdout);
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    done[a[i]] = 1;
  }
  set<int> ada;
  for(int i = 1; i <= 2 * n; i++) {
    if(!done[i]) {
      ada.insert(i);
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    auto it = ada.lower_bound(a[i]);
    if(it == ada.end()) {
      ada.erase(ada.begin());
    } else {
      ans++;
      ada.erase(it);
    }
  }
  cout << ans << endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
