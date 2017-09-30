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
encountered 
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

map<pair<int, int>, int> cache;
int nyawa = 16;
vector<int> ans;

int ask(int l, int r) {
  if (cache.count({l, r})) return cache[{l, r}];
  nyawa--;
  printf("%d", r - l + 1);
  for (int i = l; i <= r; i++) {
    printf(" %d", i);
  }
  printf("\n");
  fflush(stdout);
  int k;
  scanf("%d", &k);
  return k;
}

void dfs(int l, int r) {
  if (l == r) {
    ans.push_back(l);
    return;
  }
  int mid = (l + r) >> 1;
  int k = ask(l, mid);
  cache[{l, mid}] = k;
  cache[{mid + 1, r}] = cache[{l, r}] - k; 
  if (cache[{l, r}] == 2) {
    if (k == 0) {
      dfs(mid + 1, r);
    } else if (k == 1) {
      dfs(l, mid);
      dfs(mid + 1, r);
    } else {
      dfs(l, mid);
    }
  } else {
    if (k == 0) {
      dfs(mid + 1, r);
    } else {
      dfs(l, mid);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  cache[{1, n}] = 2;
  dfs(1, n);
  /*
  if (nyawa < 0) {
    printf("%d\n", nyawa);
    puts("MATIO COK NYAWAMU ABIS");
    assert(0);
  }
  */
  while (nyawa > 0) {
    printf("0\n");
    fflush(stdout);
    int k;
    scanf("%d", &k);
    nyawa--;
  }
  
  printf("%d %d\n", ans[0], ans[1]);
  return 0;
}
