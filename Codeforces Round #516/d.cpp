/*

Hello, it's me
I was wondering if after all these weeks you'd like to meet
To go over everything
They say that time's supposed to heal ya
But I ain't done much healing

Hello, can you hear me
I'm here dreaming about who we used to be
When we were younger and free
I've forgotten how it felt before the world fell at our feet

There's such a difference between us
And a million miles

Hello from the other side
I must have called a thousand times
To tell you I'm sorry for everything that I've done
But when I call you never seem to be home

Hello from the outside
At least I can say that I've tried
To tell you I'm sorry for breaking your heart
But it don't matter it clearly doesn't tear you apart anymore

Hello, how are you?
It's so typical of me to talk about myself I'm sorry
I hope that you're well
Did you ever make it out of that town where nothing ever happened

It's no secret that the both of us
Are running out of time

So hello from the other side
I must have called a thousand times
To tell you I'm sorry for everything that I've done
But when I call you never seem to be home
Hello from the outside
At least I can say that I've tried
To tell you I'm sorry for breaking your heart
But it don't matter it clearly doesn't tear you apart anymore

Ooooohh, anymore
Ooooohh, anymore
Ooooohh, anymore
Anymore

Hello from the other side
I must have called a thousand times
To tell you I'm sorry for everything that I've done
But when I call you never seem to be home
Hello from the outside
At least I can say that I've tried
To tell you I'm sorry for breaking your heart
But it don't matter it clearly doesn't tear you apart anymore

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int inf = 1e9;

char s[N][N];
int n, m, r, c, x, y;

pair<int, int> cost[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int cx[] = {0, 0, 0, 1};
int cy[] = {0, 0, 1, 0};

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m && s[i][j] == '.';
}

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cost[i][j] = make_pair(inf, inf);
    }
  }

  scanf("%d %d %d %d %d %d", &n, &m, &r, &c, &x, &y);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  r--; c--;
  
  priority_queue<tuple<int, int, int>> q;
  q.emplace(0, r, c);
  cost[r][c] = make_pair(0, 0);
  while (!q.empty()) {
    int now, nx, ny;
    tie(now, nx, ny) = q.top();
    now = -now;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int tx = nx + dx[i];
      int ty = ny + dy[i];
      int ncos = now + cx[i] + cy[i];
      if (!valid(tx, ty)) continue;
      if (ncos < cost[tx][ty].first + cost[tx][ty].second) {
        cost[tx][ty] = cost[nx][ny];
        cost[tx][ty].first += cx[i];
        cost[tx][ty].second += cy[i];
        q.emplace(-(cost[tx][ty].first + cost[tx][ty].second), tx, ty);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // printf("(%d,%d) ", cost[i][j].first, cost[i][j].second);
      if (s[i][j] == '.' && cost[i][j].first <= x && cost[i][j].second <= y) {
        ans++;
      }
    }
    // printf("\n");
  }
  cout << ans << endl;
  return 0;
}
