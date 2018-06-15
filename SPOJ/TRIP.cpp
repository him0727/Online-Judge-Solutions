#include <bits/stdc++.h>
 
using namespace std;
 
int n;
int f[100][100];
set<string> ans;
char s1[100], s2[100];
map<string, bool> rep[100][100];
 
void gen(int a, int b, string s) {
  if (rep[a][b].find(s) != rep[a][b].end()) {
    return;
  }
  if (a == 0 || b == 0) {
    ans.insert(s);
    return;
  }
  if (s1[a - 1] == s2[b - 1]) {
    gen(a - 1, b - 1, s1[a - 1] + s);
  } else {
    if (f[a - 1][b] >= f[a][b - 1]) {
      gen(a - 1, b, s);
    }
    if (f[a][b - 1] >= f[a - 1][b]) {
      gen(a, b - 1, s);
    }
  }
  rep[a][b][s] = true;
}
 
int main() {
  for (int i = 0; i < 100; i++) {
    f[i][0] = f[0][i] = 0;
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s1);
    scanf("%s", s2);
    int sz1 = strlen(s1), sz2 = strlen(s2);
    for (int i = 1; i <= sz1; i++) {
      for (int j = 1; j <= sz2; j++) {
        rep[i][j].clear();
        if (s1[i - 1] == s2[j - 1]) {
          f[i][j] = f[i - 1][j - 1] + 1;
          continue;
        }
        f[i][j] = max(f[i - 1][j], f[i][j - 1]);
      }
    }
    gen(sz1, sz2, "");
    for (auto itr = ans.begin(); itr != ans.end(); itr++) {
      printf("%s\n", itr -> c_str());
    }
    printf("\n");
    ans.clear();
  }
  return 0;
}