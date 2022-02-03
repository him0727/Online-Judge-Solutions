#include <bits/stdc++.h>

using namespace std;

const set<string> ADP = {"and", "in", "on", "at", "to", "of", "from", "for", "with"};

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string acr;
    cin >> n;
    cin >> acr;
    vector<string> w(n);
    for (int i = 0; i < n; i++) {
      cin >> w[i];
    }
    int acr_len = (int) acr.size();
    vector<int> prev(acr_len, 0);
    for (int i = 0; i < min((int) w[0].size(), acr_len) && w[0][i] == acr[i]; i++) {
      prev[i] = 1;
    }
    for (int i = 1; i < n; i++) {
      int cur_len = (int) w[i].size();
      vector<int> cur(acr_len, 0);
      string cur_word = "";
      bool fail = true;
      if (ADP.find(w[i]) != ADP.end()) {
        cur = prev;
        fail = false;
      }
      for (int cur_at = 0; cur_at < min(cur_len, acr_len); cur_at++) {
        cur_word += w[i][cur_at];
        for (int acr_at = cur_at + 1; acr_at < acr_len; acr_at++) {
          if (prev[acr_at - cur_at - 1] > 0 && cur_word == acr.substr(acr_at - cur_at, cur_at + 1)) {
            cur[acr_at] += prev[acr_at - cur_at - 1];
            fail = false;
          }
        }
      }
      swap(cur, prev);
      if (fail) {
        break;
      }
    }
    cout << prev.back() << '\n';
  }
  return 0;
}