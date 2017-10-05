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

int l, r;
long long cur;
int cnt[N], a[N];

void maju_r() {
  r++;
  cur += cnt[a[r]];
  cnt[a[r]]++;
}

void mundur_r() {
  cnt[a[r]]--;
  cur -= cnt[a[r]];
  r--;
}

void maju_l() {
  cnt[a[l]]--;
  cur -= cnt[a[l]];
  l++;
}

void mundur_l() {
  l--;
  cur += cnt[a[l]];
  cnt[a[l]]++;
}

void cocok(int le, int ri) {
  ri--;
  while (r < ri) maju_r();
  while (le < l) mundur_l();
  while (r > ri) mundur_r();
  while (le > l) maju_l();
}

long long dp[N], v[N];

void solve(int to_lef, int to_rig, int from_lef, int from_rig) {
  if (to_lef > to_rig) return;
  //printf("%d %d: %d %d\n", to_lef, to_rig, from_lef, from_rig);
  if (from_lef == from_rig) {
    for (int i = to_lef; i <= to_rig; i++) {
      cocok(from_lef, i);
      dp[i] = v[from_lef] + cur;
    }
    return;
  }
  int mid = (to_lef + to_rig) >> 1, p = -1;
  dp[mid] = 1e18;
  for (int i = from_lef; i <= from_rig && i < mid; i++) {
    cocok(i, mid);
    long long ncur = v[i] + cur;
    if (ncur < dp[mid]) {
      dp[mid] = ncur;
      p = i;
    }
  }
  solve(to_lef, mid - 1, from_lef, p);
  solve(mid + 1, to_rig, p, from_rig);
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  cnt[a[0]]++;
  for (int i = 0; i < n; i++) {
    cocok(0, i + 1);
    dp[i + 1] = cur;
  }
  for (int it = 1; it < k; it++) {
    for (int i = 0; i < N; i++) {
      v[i] = dp[i];
    }
    solve(1, n, 0, n - 1);
  }
  cout << dp[n] << endl;
  return 0;
}
