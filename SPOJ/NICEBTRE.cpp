#include <bits/stdc++.h>
 
using namespace std;
 
string s;
int p;
 
int dfs() {
  if (s[p] == 'l' || p >= s.size()) {
    return 0;
  }
  p++;
  int left = dfs();
  p++;
  int right = dfs();
  return max(left, right) + 1;
}
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    cin >> s;
    p = 0;
    printf("%d\n", dfs());    
  }
  return 0;
}