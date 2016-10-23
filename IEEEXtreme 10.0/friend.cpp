#include <bits/stdc++.h>

using namespace std;

const int N = 15;

map<char, int> mp;
string str = "rgb";

vector<int> all_conf;
int ans[N];
int a[N], cnt[3];

struct Word {
  Word(int _type, int _color, int _val) {
    type = _type;
    color = _color;
    val = _val;
  }
  int tyoe;   // 0 color, 1 count
  int color;  // r g b
  int val;    // at if color, value if count
};

struct Sentence {
  Sentence(int _type) {
    type = _type;
  }
  int type;       // 0 AND, 1 OR
  vector<Word> words;
};

int main() {
  for (int i = 0; i < 3; i++) mp[str[i]] = i;
  
  int t;
  cin >> t;
  while (t--) {
    all_conf.clear();
    
    int num_sencentes, k, n = 10;
    cin >> num_sencentes >> k;
    cin.ignore();
    vector<Sentence> sentences;
    for (int i = 0; i < num_sencentes; i++) {
      string buf, tmp;
      getline(cin, buf);
      stringstream ss(buf);
      int now = 0;
      Sentence sentence(0);
      while (ss >> tmp) {
        if (now == 0) {
          Word word(type == "count");
          sentence.words.push_back(word);
        } else if (now == 1) {
          if (sentence.words.back().type) {
            sentence.words.back().color = mp[tmp[0]];
          } else {
            sentence.words.back().val = atoi(tmp.c_str());
          }
        } else if (now == 2) {
          if (sentence.words.back().type) {
            sentence.words.back().val = atoi(tmp.c_str());
          } else {
            sentence.words.back().color = mp[tmp[0]];
          }
        } else {
          sentence.type = (tmp == "or");
        }
        now = (now + 1) % 4;
      }
      sentences.push_back(sentence);
    }
    int all = 1;
    for (int i = 0; i < n; i++) all *= 3;
    for (int mask = 0; mask < all; mask++) {
      memset(cnt, 0, sizeof(cnt));
      for (int i = 0; i < n; i++) {
        a[i] = mask % 3;
        mask /= 3;
        cnt[a[i]]++;
      }
      int lies = 0;
      for (auto sentence : sentences) {
        int num_words = sentence.words.size();
        int correct = 0;
        for (auto word : sentence.words) {
          
        }
      }
    }
  }
  return 0;
}
