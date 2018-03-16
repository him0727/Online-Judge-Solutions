#include <bits/stdc++.h>
 
using namespace std;
 
char g[201][201];
 
int main() {
  int t, dist = 0, len = 0;
  string s;
  scanf("%d", &t);
  cin.ignore();
  cin.ignore();
  for (int i = 0; i < t; i++) {
    getline(cin, s);
    len = max(len, (int) s.size());
    for (int j = 0; j < s.size(); j++) {
      g[i][j] = s[j];
      if (s[j] == '_' || s[j] == '/' || s[j] == '\\') {
        dist++;
      }
    }
  }
  printf("Total Walk Distance = %d\n", dist);
  vector<char> p;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < t; j++) {
      if (g[j][i] == '_' || g[j][i] == '/' || g[j][i] == '\\') {
        p.push_back(g[j][i]);
        break;
      }
    }
  }
  char pre = p[0];
  int pre_v = 1, p_sz = p.size();
  for (int i = 1; i < p_sz; i++) {
    if (p[i] != pre || i == p_sz - 1) {
      bool finish = false;
      if (p[i] == pre && i == p_sz - 1) {
        pre_v++;
        finish = true;
      }
      if (pre == '_') {
        printf("Walk %d steps\n", pre_v);
      } else if (pre == '/') {
        printf("Up %d steps\n", pre_v);
      } else {
        printf("Down %d steps\n", pre_v);
      }
      if (!finish && i == p_sz - 1) {
        if (p[i] == '_') {
          printf("Walk 1 steps\n");
        } else if (p[i] == '/') {
          printf("Up 1 steps\n");
        } else {
          printf("Down 1 steps\n");
        }
      }
      pre_v = 1;
      pre = p[i];
    } else {
      pre_v++;
    }
  }
  for (int i = 0; i < t; i++) {
    g[i][0] = 0;
  }
  return 0;
}