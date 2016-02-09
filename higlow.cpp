#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int CONST = 5;

bool done[N];
vector<int> me, you;
int n;

int solve(vector<int>& a, vector<int>& b) {
  //puts("KENTANG");
  set<int> ada;
  for(auto it : b) {
    //printf("me %d\n", it);
    ada.insert(it);
  }
  int ret = 0;
  for(auto it : a) {
    //printf("you %d\n", it);
    auto iter = ada.lower_bound(it);
    if(iter == ada.end()) {
      ada.erase(ada.begin());
    } else {
      ret++;
      ada.erase(iter);
    }
  }
  return ret;
}

int solve(int p) {
  vector<int> a_b, b_b, a_e, b_e;
  for(int i = 0; i < p; i++) {
    a_b.push_back(you[i]);
    b_b.push_back(me[i]);
  }
  for(int i = p; i < n; i++) {
    a_e.push_back(-you[i]);
    b_e.push_back(-me[i]);
  }
  return solve(a_b, b_b) + solve(a_e, b_e);
}

int main() {
  freopen("cardgame.in","r",stdin);
  freopen("cardgame.out","w",stdout);
  
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    you.push_back(v);
    done[v] = 1;
  }
  for(int i = 1; i <= 2 * n; i++) {
    if(!done[i]) {
      me.push_back(i);
    }
  }
  sort(me.begin(), me.end());
  reverse(me.begin(), me.end());
  
  int l = 0, r = n;
  while(r - l > 3) {
    int lt = l + (r - l) / 3;
    int rt = r - (r - l) / 3;
    //printf("%d %d\n", l, r);
    if(solve(lt) <= solve(rt)) {
      l = lt;
    } else {
      r = rt;
    }
  }
  int ans = 0;
  for(int i = l; i <= r; i++) {
    ans = max(ans, solve(i));
  }
  for(int i = 0; i <= min(n, CONST); i++) {
    ans = max(ans, solve(i));
  }
  for(int i = n; i >= max(0, n - CONST); i--) {
    ans = max(ans, solve(i));
  }
  /*
  for(int i = 0; i <= n; i++) {
    printf("%d ", solve(i));
  }
  printf("\n");
  */
  cout << ans << endl;
  return 0;
}
