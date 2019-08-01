#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


const int N = 1e5 + 5;

int bit_max[N], bit_min[N];

void update_max(int i, int val) {
  for (; i < N; i |= i + 1) {
    bit_max[i] = max(bit_max[i], val);
  }
}

int find_max(int i) {
  int ret = -1;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    ret = max(ret, bit_max[i]);
  }
  return ret;
}

void update_min(int i, int val) {
  for (; i < N; i |= i + 1) {
    bit_min[i] = min(bit_min[i], val);
  }
}

int find_min(int i) {
  int ret = N;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    ret = min(ret, bit_min[i]);
  }
  return ret;
}

vector<int> all;

int find_index(int val)  {
  return lower_bound(all.begin(), all.end(), val) - all.begin();
}

int lef[N], rig[N];

int solve(int l, int i, int r) {
  if (l == -1 && r == -1) return -1;
  if (l == -1) return r;
  if (r == -1) return l;
  int dis_l = i - l;
  int dis_r = r - i;
  if (dis_l <= dis_r) {
    return l;
  } else {
    return r;
  }
}

vector<int> predictAnswer(vector<int> a, vector<int> q) {
  int n = a.size();
  for (int i = 0; i < N; i++) {
    bit_min[i] = N;
    bit_max[i] = -1;
  }
  for (auto it : a) all.push_back(it);
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  for (int i = 0; i < a.size(); i++) {
    int idx = find_index(a[i]);
    int ret = find_max(idx);
    if (ret == -1) {
      lef[i] = -1;
    } else {
      lef[i] = ret;
    }
    update_max(idx + 1, i);
  }
  for (int i = (int) a.size() - 1; i >= 0; i--) {
    int idx = find_index(a[i]);
    int ret = find_min(idx);
    if (ret == N) {
      rig[i] = -1;
    } else {
      rig[i] = ret;
    }
    update_min(idx + 1, i);
  }
  vector<int> ans;
  for (auto it : q) {
    it--;
    if (it >= n) {
      ans.push_back(-1);
    } else {
      int e = solve(lef[it], it, rig[it]);
      if (e != -1) e++
      ans.push_back(e);
    }
  }
  return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string stockData_count_temp;
    getline(cin, stockData_count_temp);

    int stockData_count = stoi(ltrim(rtrim(stockData_count_temp)));

    vector<int> stockData(stockData_count);

    for (int i = 0; i < stockData_count; i++) {
        string stockData_item_temp;
        getline(cin, stockData_item_temp);

        int stockData_item = stoi(ltrim(rtrim(stockData_item_temp)));

        stockData[i] = stockData_item;
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<int> result = predictAnswer(stockData, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
