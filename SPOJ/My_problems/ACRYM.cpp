#include <bits/stdc++.h>

using namespace std;

const set<string> ADP = {"and", "in", "on", "at", "to", "of", "from", "for", "with"};

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int N;
    string ACR;
    cin >> N;
    cin >> ACR;
    vector<string> W(N);
    for (int i = 0; i < N; i++) {
      cin >> W[i];
    }
    int acr_len = (int) ACR.size();
    vector<int> prev(acr_len, 0);
    for (int i = 0; i < (int) W[0].size(); i++) {
      if (i >= acr_len || W[0][i] != ACR[i]) {
        break;
      }
      prev[i] = 1;
    }
    assert(ADP.find(W[0]) == ADP.end());
    for (int i = 1; i < (int) W.size(); i++) {
      int cur_len = (int) W[i].size();
      vector<int> cur(acr_len, 0);
      string cur_word = "";
      bool fail = true;
      if (ADP.find(W[i]) != ADP.end()) {
        cur = prev;
        fail = false;
      }
      for (int cur_at = 0; cur_at < min(cur_len, acr_len); cur_at++) {
        cur_word += W[i][cur_at];
        for (int acr_at = cur_at + 1; acr_at < acr_len; acr_at++) {
          if (prev[acr_at - cur_at - 1] > 0 && cur_word == ACR.substr(acr_at - cur_at, cur_at + 1)) {
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
    cout << prev[acr_len - 1] << '\n';
  }
  return 0;
}