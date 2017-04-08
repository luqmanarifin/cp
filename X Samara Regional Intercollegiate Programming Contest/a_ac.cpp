#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct segment {
  segment(string s, int id) : id(id) {
    int now = 0;
    lowest = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') now++;
      else now--;
      lowest = min(lowest, now);
    }
    gain = now;
    
    now = 0;
    rev_lowest = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
      if (s[i] == '(') now--;
      else now++;
      rev_lowest = min(rev_lowest, now);
    }
  }
  int gain, lowest, rev_lowest, id;
};

bool cmp_positive(segment l, segment r) {
  return l.lowest > r.lowest;
}

bool cmp_negative(segment l, segment r) {
  return l.rev_lowest < r.rev_lowest;
}

int main() {
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  vector<segment> pos, neg, nol;
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    segment seg = segment(s, i);
    if (seg.gain > 0) {
      pos.push_back(seg);
    } else if (seg.gain < 0) {
      neg.push_back(seg);
    } else {
      nol.push_back(seg);
    }
    tot += seg.gain;
  }
  if (tot != 0) {
    puts("NO");
    return 0;
  }
  sort(pos.begin(), pos.end(), cmp_positive);
  sort(neg.begin(), neg.end(), cmp_negative);
  vector<int> ans;
  int now = 0;
  for (int i = 0; i < pos.size(); i++) {
    if (now + pos[i].lowest < 0) {
      puts("NO");
      return 0;
    }
    now += pos[i].gain;
    ans.push_back(pos[i].id);
  }
  for (int i = 0; i < nol.size(); i++) {
    if (now + nol[i].lowest < 0) {
      puts("NO");
      return 0;
    }
    now += nol[i].gain;
    ans.push_back(nol[i].id);
  }
  for (int i = 0; i < neg.size(); i++) {
    if (now + neg[i].lowest < 0) {
      puts("NO");
      return 0;
    }
    now += neg[i].gain;
    ans.push_back(neg[i].id);
  }
  puts("YES");
  for (auto it : ans) printf("%d ", it);

  return 0;
}
