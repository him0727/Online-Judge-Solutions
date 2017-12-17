#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
string plate;
vector<string> words(5000);
vector<array<vector<int>, 26>> d(5000);
 
int main() {
  scanf("%d %d", &n, &m);
  int id = 0;
  while (n--) {
    cin >> words[id];
    for (int i = 0; i < words[id].size(); i++) {
      d[id][words[id][i] - 'a'].push_back(i);
    }
    id++;
  }
  while (m--) {
    cin >> plate;
    transform(plate.begin(), plate.end(), plate.begin(), ::tolower);
    bool find = false;
    string find_s = "";
    for (int s = 0; s < id; s++) {
      if (d[s][plate[0] - 'a'].empty() || d[s][plate[1] - 'a'].empty() || d[s][plate[2] - 'a'].empty()) continue;
      for (int i = 0; i < d[s][plate[1] - 'a'].size(); i++) {
        if (d[s][plate[1] - 'a'][i] > d[s][plate[0] - 'a'][0]) {
          for (int j = 0; j < d[s][plate[2] - 'a'].size(); j++) {
            if (d[s][plate[2] - 'a'][j] > d[s][plate[1] - 'a'][i]) {
              find = true;
              find_s = words[s];
              break;
            }
          }
          break;
        }
      }
      if (find) break;
    }
    if (find) cout << find_s << "\n";
    else cout << "No valid word\n";
  }
  return 0;
}