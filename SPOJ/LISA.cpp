#include <bits/stdc++.h>
 
using namespace std; 
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    string s;
    cin >> s;
    vector<bool> is_add;
    vector<int> dg;
    string sdg = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '+' || s[i] == '*') {
        dg.push_back(stoi(sdg));
        sdg = "";
        is_add.push_back(s[i] == '+');
      } else {
        sdg += s[i];
      }
    }
    if (sdg.size() != 0) {
      dg.push_back(stoi(sdg));
    }
    int N = dg.size();
    vector<vector<unsigned long long>> m_min(N, vector<unsigned long long> (N, numeric_limits<unsigned long>::max()));
    vector<vector<unsigned long long>> m_max(N, vector<unsigned long long> (N, 0));
    for (int i = 0; i < N; i++) {
      m_max[i][i] = m_min[i][i] = dg[i];
    }
    for (int len = 1; len < N; len++) {
      for (int i = 0; i < N - len; i++) {
        int j = i + len;
        for (int k = i; k < j; k++) {
          unsigned long long ret_max = 0;
          unsigned long long ret_min = 0;
          if (is_add[k]) {
            ret_max = m_max[i][k] + m_max[k + 1][j];
            ret_min = m_min[i][k] + m_min[k + 1][j];
          } else {
            ret_max = m_max[i][k] * m_max[k + 1][j];
            ret_min = m_min[i][k] * m_min[k + 1][j];
          }
          m_max[i][j] = max(m_max[i][j], ret_max);
          m_min[i][j] = min(m_min[i][j], ret_min);
        }
      }
    }
    printf("%llu %llu\n", m_max[0][N - 1], m_min[0][N - 1]);
  }
  return 0;
}