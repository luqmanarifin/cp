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
int x[N], y[N], n; 

long long solve(int mid) {
  long long ret = 0;
  for (int i = 0; i < n; i++) {
    if (x[i] <= mid && mid <= y[i]) continue;
    ret += min(abs(mid - x[i]), abs(mid - y[i]));
  } 
  return ret;
} 

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d", x + i, y + i);
  int l = -1e9, r = 1e9;
  long long ans = 1e18;
  while (r - l > 3) {
    int lf = (l + l + r) / 3;
    int rf = (r + r + l) / 3;
    long long retl = solve(lf);
    long long retr = solve(rf);
    if (retl < retr) {
      r = rf;
      ans = min(ans, retl);
    } else {
      l = lf;
      ans = min(ans, retr);
    }
  }
  for (int i = l; i <= r; i++) ans = min(ans, solve(i));
  cout << ans << endl;
  return 0;
}
