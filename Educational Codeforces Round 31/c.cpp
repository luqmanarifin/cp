/*

We walked with our shoulders in line,
Laughing about things that didn't matter as we looked onward toward the same dream.
If I listen carefully, I can still hear it,
Your voice, staining this city orange.

When you're not around, I'm so bored,
But when I say I'm lonely, you just laugh at me.
I just keep counting up the things I have left,
That shine brightly and never fade away.

Like the sky after the rain lets up, like clearing up one's heart.
I remember your smile, it floats up in my mind and I can't help but smile.
Surely, just as we were that day, like innocent children,
We'll run through the passing seasons, seeing each of our many tomorrows.

Whenever I was alone and started to feel uneasy,
On nights I didn't want to sleep, we'd just go on talking.

I wonder what you'll go on to see from here,
And what I'll see right here.
I'll try to entrust my tears,
To this city where the setting sun stains everything orange.

This single love was born among a million rays of light.
Even if you never change, even if you happen to change, you're you, so I'm not worried.
Someday we'll both become adults and meet wonderful people.
At that time, I hope we can bring along our irreplaceable families and meet here again.

Like the sky after the rain lets up, like clearing up one's heart.
I remember your smile, it floats up in my mind and I can't help but smile.
This single love was born among a million rays of light.
We run through the passing seasons, seeing each of our many tomorrows,
Choosing from each of our many dreams.

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> el[N];
int par[N];

bool done[N];

void merge(int u, int v) {
  if (par[u] != par[v]) {
    if (el[par[u]].size() < el[par[v]].size()) {
      swap(u, v);
    }
    for (auto it : el[par[v]]) {
      el[par[u]].push_back(it);
      par[it] = par[u];
    }
  }
}

int main() {
  for (int i = 0; i < N; i++) {
    par[i] = i;
    el[i].push_back(i);
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int p;
    scanf("%d", &p);
    merge(i, p);
  }
  vector<int> num;
  for (int i = 1; i <= n; i++) {
    if (!done[par[i]]) {
      num.push_back(el[par[i]].size());
      done[par[i]] = 1;
    }
  }
  sort(num.begin(), num.end());
  if (num.size() >= 2) {
    int i = num.back(); num.pop_back();
    int j = num.back(); num.pop_back();
    num.push_back(i + j);
  }
  long long ans = 0;
  for (auto it : num) ans += 1LL * it * it;
  cout << ans << endl;
  return 0;
}
