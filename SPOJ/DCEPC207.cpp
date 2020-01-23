#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  cin >> tt;
  cin.ignore();
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ":" << '\n';
    string input;
    getline(cin, input);
    input.push_back(' ');
    vector<string> names;
    string tmp;
    for (int i = 0; i < (int) input.size(); i++) {
      if (input[i] == ' ') {
        names.push_back(tmp);
        tmp.clear();
      } else {
        tmp.push_back(input[i]);
      }
    }
    vector<int> cnt(26, 0);
    for (string s : names) {
      for (char c : s) {
        cnt[c - 'a']++;
      }
    }
    int max_idx = 0;
    for (int i = 1; i < 26; i++) {
      if (cnt[i] > cnt[max_idx]) {
        max_idx = i;
      }
    }
    for (string s : names) {
      vector<int> freq(26, 0);
      for (char c : s) {
        freq[c - 'a']++;
      }
      bool ok = true;
      for (char c = 'a'; c <= 'z'; c++) {
        if (c != max_idx + 'a') {
          ok &= (freq[c - 'a'] < freq[max_idx]);
        }
      }
      if (ok) {
        cout << s << '\n';
      }
    }
  }
  return 0;
}