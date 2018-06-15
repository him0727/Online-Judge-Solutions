#include <bits/stdc++.h>
 
using namespace std;
 
int ans, cnt, pos, dlevel;
string s;
 
void solve(int level) {
  if (level > dlevel) {
    dlevel = level;
    ans = cnt;
  }
  if (pos >= s.size() || s[pos++] == '0') {
    return;
  }
  cnt++;
  level++;
  solve(level);
  solve(level);
}
 
int main() {
  for (int qq = 0; qq < 10; qq++) {
    int n;
    scanf("%d", &n);
    cin >> s;
    ans = cnt = pos = dlevel = 0;
    solve(0);
    printf("%d\n", ans);
  }
  return 0;
}