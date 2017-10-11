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

const int N = 5005;

int cnt[N];
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i), cnt[a[i]]++;
  long long ans = 0;
  ans += 1LL * cnt[0] * (cnt[0] - 1) * (cnt[0] - 2) / 6;
  for (int i = 1; i < N; i++) {
    // 0 + i
    ans += 1LL * cnt[0] * cnt[i] * (cnt[i] - 1) / 2;
    for (int j = 1; j + j < i; j++) {
      ans += 1LL * cnt[i] * cnt[j] * cnt[i - j];
    }
    // j + j == i
    if (i % 2 == 0) {
      int j = i / 2;
      ans += 1LL * cnt[i] * cnt[j] * (cnt[j] - 1) / 2;
    }
  }
  cout << ans << endl;
  return 0;
}
