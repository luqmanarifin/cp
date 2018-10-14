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

const int N = 1e5 + 5;

#define point pair<int, int>

vector<point> add[2 * N], sub[2 * N], row[2 * N], col[2 * N];
int x[N], y[N], ans[10];

int ada(vector<point>& all, point p) {
  int at = lower_bound(all.begin(), all.end(), p) - all.begin();
  return (at > 0) + (at + 1 < all.size());
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    add[a + b].emplace_back(a, b);
    sub[a - b + N].emplace_back(a, b);
    row[a].emplace_back(a, b);
    col[b].emplace_back(a, b);
    x[i] = a;
    y[i] = b;
  }
  for (int i = 0; i < 2 * N; i++) {
    sort(add[i].begin(), add[i].end());
    sort(sub[i].begin(), sub[i].end());
    sort(row[i].begin(), row[i].end());
    sort(col[i].begin(), col[i].end());
  }
  for (int i = 0; i < m; i++) {
    int cur = 0;
    int a = x[i];
    int b = y[i];
    point p(a, b);
    cur += ada(add[a + b], p);
    cur += ada(sub[a - b + N], p);
    cur += ada(row[a], p);
    cur += ada(col[b], p);
    ans[cur]++;
  }
  for (int i = 0; i <= 8; i++) printf("%d ", ans[i]); printf("\n");
  return 0;
}
