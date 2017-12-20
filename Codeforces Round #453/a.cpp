/*

I will leave my heart at the door
I won't say a word
They've all been said before, you know
So why don't we just play pretend
Like we're not scared of what is coming next
Or scared of having nothing left

Look, don't get me wrong
I know there is no tomorrow

All I ask is if this is my last night with you
Hold me like I'm more than just a friend
Give me a memory I can use
Take me by the hand while we do what lovers do
It matters how this ends
'Cause what if I never love again?

I don't need your honesty
It's already in your eyes
And I'm sure my eyes, they speak for me
No one knows me like you do
And since you're the only one that matters
Tell me who do I run to?

Let this be our lesson in love
Let this be the way we remember us
I don't wanna be cruel or vicious
And I ain't asking for forgiveness

All I ask is if this is my last night with you
Hold me like I'm more than just a friend
Give me a memory I can use
Take me by the hand while we do what lovers do
It matters how this ends
'Cause what if I never love again? 

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], p1[N], p2[N];
vector<int> el[N];

int main() {
  int h;
  scanf("%d", &h);
  for (int i = 0; i <= h; i++) scanf("%d", a + i);
  int now = 0;
  for (int i = 0; i <= h; i++) {
    for (int j = 0; j < a[i]; j++) {
      now++;
      el[i].push_back(now);
    }
  }
  //printf("nodes %d\n", now);
  bool ok = 1;
  for (int i = 1; i <= h; i++) {
    if (a[i-1] > 1 && a[i] > 1) {
      ok = 0;
      puts("ambiguous");
      break;
    }
  }
  if (ok) {
    puts("perfect");
    return 0;
  }
  for (int i = 1; i <= h; i++) {
    if (a[i] > 1 && a[i-1] > 1) {
      for (auto it : el[i]) {
        p1[it] = el[i-1][0];
      }
      p2[el[i][0]] = el[i-1][0];
      for (int j = 1; j < el[i].size(); j++) {
        p2[el[i][j]] = el[i-1][1];
      }
    } else {
      for (auto it : el[i]) {
        p1[it] = p2[it] = el[i-1][0];
      }
    }
  }
  for (int i = 1; i <= now; i++) printf("%d ", p1[i]); printf("\n");
  for (int i = 1; i <= now; i++) printf("%d ", p2[i]); printf("\n");
  return 0;
}
