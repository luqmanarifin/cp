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

int cnt[1 << 4];
int a[N][4], now[4];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    int cur = 0;
    for (int j = 0; j < k; j++) {
      scanf("%d", &a[i][j]);
      if (a[i][j]) {
        cur |= (1 << j);
      }
    }
    cnt[cur]++;
  }
  for (int p = 1; p <= n; p++) {
    //cout << p << endl;
    int wajib = 0;
    for (int j = 0; j < k; j++) {
      if ((now[j] + 1) > p / 2) {
        wajib |= (1 << j);
      }
    }
    for (int longgar = 0; longgar <= k; longgar++) {
      int take = -1;
      for (int mask = 0; mask < (1 << k); mask++) {
        if (cnt[mask] == 0) continue;
        if (__builtin_popcount(wajib & mask) != longgar) continue;
        take = mask;
        break;
      }
      if (take != -1) {
        cnt[take]--;
        for (int j = 0; j < k; j++) {
          if (take & (1 << j)) {
            now[j]++;
          }
        }
        break;
      }
    }
    bool ok = 1;
    for (int j = 0; j < k; j++) {
      if (now[j] > p / 2) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
