#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7;

vector<int> b_to_o[N]; // #org - #balon
int a[N][2];  // orang
bool skipped[N];  // orang
bool balloon[N];  // balon

bool vis[N];  // balon
bool done[N]; // orang
int goal;

int dfs(int now, int cnt) {
  int ans = 0;
  for (int i = 0; i < 2; i++) {
    int c = a[now][i];
    int d = a[now][i^1];
    if (!vis[c]) {
      if (cnt + 1 == goal) {
        ans++;
      } else {
        vis[c] = 1;
        done[now] = 1;
        bool found = 0;
        for (auto it : b_to_o[c]) {
          if (!done[it]) {
            ans += dfs(it, cnt + 1);
            found = 1;
          }
        }
        if (!found) {
          for (auto it : b_to_o[d]) {
            if (!done[it]) {
              ans += dfs(it, cnt + 1);
              break;
            }
          }
        }
        done[now] = 0;
        vis[c] = 0;
      }
    }
  }
  return ans;
}

long long num_org, num_bal;

void flood(int now) {
  skipped[now] = 1;
  num_org++;
  for (int i = 0; i < 2; i++) {
    int c = a[now][i];
    if (balloon[c]) continue;
    balloon[c] = 1;
    num_bal++;
    for (auto it : b_to_o[c]) {
      if (!skipped[it]) {
        flood(it);
      }
    }
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i][0], &a[i][1]);
    b_to_o[a[i][0]].push_back(i);
    b_to_o[a[i][1]].push_back(i);
  }
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    if (skipped[i]) continue;
    num_org = 0; num_bal = 0;
    flood(i);
    if (num_bal < num_org) {
      ans = 0;
      break;
    }
    if (num_bal == num_org) {
      ans *= 2;
    } else {
      ans *= num_bal;
    }
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
