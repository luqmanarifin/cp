/*

With our small shoulders next to each others,
we walked all alone
For a mere trivial matter, we burst in laughter
And also gazed for the same dreams
If I listen carefully, 
even now I still could hear
your voice is resounding 
in the middle of 
this orange-colored town

It's so boring, 
when you're nowhere
If I said I felt lonely, 
you'd laugh after me
But countless times, 

I've ensured
all things you left behind won't vanish, 
they'll continue to sparkling beautifully

I’ll smile in no time, 
if I remember, recall your smiling faces
Just like after rain sky,
relieves all troubles from my heart

I believe, 
we’ll be the same like those old days
still like innocent children
Run and dash away after the cycle of seasons
Face tomorrows of our own

If I was all alone, I felt uneasy
Sleepless nights, you were always by my side
kept telling me your story

What matters 
will you face from now on?
And also, 
what matters will I face from here?
Secretly, I try to entrust my tears
along with the setting down twilight
in the middle of this orange-colored town

In the midst of millions rays
was born a glimmer of love
Even though you’ve changed
or still the way you’re
You’re still yourself
Nothing to be worried of

It would be nice, 
if someday we’ve been adults
encountered ac
our dearest one,
brought along 
our irreplaceable families
and could meet again here, 
in this place

I’ll smile in no time, 
if I remember, recall your smiling faces
Just like after rain sky,
relieves all troubles from my heart

In the midst of millions rays
was born a glimmer of love
Run and dash away after the cycle of seasons
Face tomorrows of our own
Choose dreams of our own

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int T = 5105;

double a[N][T], b[N][T];
bool vis[N][T];
int f[N], s[N], p[N], butuh[N];
int n, r;

pair<double, double> solve(int i, int j) {
  if (vis[i][j]) return {a[i][j], b[i][j]};
  if (j + butuh[i] > r) return {1, 0};
  if (i == n) return {0, 0};
  vis[i][j] = 1;
  auto fast = solve(i + 1, j + f[i]);
  auto slow = solve(i + 1, j + s[i]);
  double d = fast.first;
  double e = fast.second;
  double g = slow.first;
  double h = slow.second;
  a[i][j] = d*p[i]/100 + g*(100-p[i])/100;
  b[i][j] = (e + f[i])*p[i]/100 + (h + s[i])*(100-p[i])/100;
  //printf("%d %d: %.15f\n", i, j, b[i][j]);
  return {a[i][j], b[i][j]};
}

int main() {
  scanf("%d %d", &n, &r);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", f + i, s + i, p + i);
  }
  for (int i = n - 1; i >= 0; i--) {
    butuh[i] = butuh[i + 1] + f[i];
  }
  pair<double, double> ret = solve(0, 0);
  double A = ret.first;
  double B = ret.second;
  printf("%.15f\n", B / (1 - A));
  return 0;
}
