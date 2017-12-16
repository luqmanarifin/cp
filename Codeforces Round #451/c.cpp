/**

Heart beats fast
Colours and promises
How to be brave?
How can I love when I'm afraid to fall?
But watching you stand alone,
All of my doubt suddenly goes away somehow.

One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

Time stands still
Beauty in all she is
I will be brave
I will not let anything take away
What's standing in front of me
Every breath
Every hour has come to this

One step closer
One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

And all along I believed I would find you
Time has brought your heart to me
I have loved you for a thousand years
I'll love you for a thousand more

*/

#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> mp;

vector<string> normalize(vector<string> a) {
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j + 1 < a.size(); j++) {
      if (a[j].size() < a[j+1].size()) {
        swap(a[j], a[j + 1]);
      }
    }
  }
  vector<string> ret;
  for (auto it : a) {
    bool ada = 0;
    for (auto i : ret) if (i.substr(i.size() - it.size()) == it) {
      ada = 1;
      break;
    }
    if (!ada) ret.push_back(it);
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    string name;
    int k;
    cin >> name >> k;
    while (k--) {
      string buf;
      cin >> buf;
      mp[name].push_back(buf);
    }
  }
  printf("%d\n", mp.size());
  for (auto it : mp) {
    vector<string> num = normalize(it.second);
    printf("%s %d", it.first.c_str(), num.size());
    for (auto i : num) printf(" %s", i.c_str());
    printf("\n");
  }
  return 0;
}
