/*

We walked with our shoulders in line,
Laughing about things that didn't matter as we looked onward toward the same dream.
If I listen carefully, I can still hear it:
Your voice, staining this city orange.

When you're not around, I'm so bored,
But when I say I'm lonely, you just laugh at me.
I just keep counting up the things I have left,
That shine brightly and never fade away.

Like the sky after the rain lets up... like clearing up one's heart...
I remember your smile; it floats up in my mind and I can't help but smile.
Surely, just as we were that day... like innocent children,
We'll run through the passing seasons, seeing each of our many tomorrows.

Whenever I was alone and started to feel uneasy...
On nights I didn't want to sleep, we'd just go on talking.

I wonder what you'll go on to see from here,
And what I'll see right here.
I'll try to entrust my tears,
To this city where the setting sun stains everything orange.

This single love was born among a million rays of light;
Even if you never change... even if you happen to change... you're you, so I'm not worried.
Someday we'll both become adults and meet wonderful people;
At that time, I hope we can bring along our irreplaceable families and meet here again...

Like the sky after the rain lets up... like clearing up one's heart...
I remember your smile; it floats up in my mind and I can't help but smile.
This single love was born among a million rays of light...
We run through the passing seasons, seeing each of our many tomorrows;
Choosing from each of our many dreams.

*/

#include <bits/stdc++.h>

using namespace std;

int solve_1(int n, int pos, int l, int r) {
  int ans = 0;
  if (l > 1) {
    ans += abs(pos - l) + 1;
    pos = l;
  }
  if (r + 1 <= n) {
    ans += abs(pos - r) + 1;
    pos = r;
  }
  return ans;
}

int solve_2(int n, int pos, int l, int r) {
  int ans = 0;
  if (r + 1 <= n) {
    ans += abs(pos - r) + 1;
    pos = r;
  }
  if (l > 1) {
    ans += abs(pos - l) + 1;
    pos = l;
  }
  return ans;
}

int main() {
  int n, pos, l, r;
  scanf("%d %d %d %d", &n, &pos, &l, &r);
  printf("%d\n", min(solve_1(n, pos, l, r), solve_2(n, pos, l, r)));
  return 0;
}
