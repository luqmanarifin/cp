/**

Heart beats fast
Colours and promises
How to be brave?
How can I love when I'm afraid to fall?
But watching you stand alone,
All of my doubt suddenly goes away somehow.

One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

Time stands still
Beauty in all she is
I will be brave
I will not let anything take away
What's standing in front of me
Every breath
Every hour has come to this

One step closer
One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

And all along I believed I would find you
Time has brought your heart to me
I have loved you for a thousand years
I'll love you for a thousand more

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int last[N][N];
int bx[N][N], by[N][N];

int dx[] = {-2, -2, 0, 2, 2, 0};
int dy[] = {-1, 1, 2, 1, -1, -2};
string s[] = {"UL", "UR", "R", "LR", "LL", "L"};

int n;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < n;
}

int main() {
  scanf("%d", &n);
  memset(last, -1, sizeof(last));
  int si, sj, fi, fj;
  scanf("%d %d %d %d", &si, &sj, &fi, &fj);
  queue<pair<int, int>> q;
  last[si][sj] = 0;
  q.emplace(si, sj);
  while (!q.empty()) {
    int ni, nj;
    tie(ni, nj) = q.front();
    q.pop();
    for (int i = 0; i < 6; i++) {
      int ti = ni + dx[i];
      int tj = nj + dy[i];
      if (!valid(ti, tj)) continue;
      if (last[ti][tj] == -1) {
        last[ti][tj] = i;
        bx[ti][tj] = ni;
        by[ti][tj] = nj;
        q.emplace(ti, tj);
      }
    }
  }
  if (last[fi][fj] == -1) {
    puts("Impossible");
    return 0;
  }
  vector<string> ans;
  while (fi != si || fj != sj) {
    ans.push_back(s[last[fi][fj]]);
    int tx = bx[fi][fj];
    int ty = by[fi][fj];
    fi = tx;
    fj = ty;
  }
  reverse(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%s ", it.c_str());
  return 0;
}
