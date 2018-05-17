#include <bits/stdc++.h>
 
using namespace std;
 
int asc[2010], desc[2010];
 
int main() {  
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    string s;
    cin >> s;
    int sz = (int) s.size();
    asc[0] = desc[sz + 1] = 0;
    for (int i = 1, j = sz; i <= sz && j >= 1; i++, j--) {
      asc[i] = asc[i - 1];
      if (s[i - 1] == 'K') {
        asc[i]++;
      }
      desc[j] = desc[j + 1];
      if (s[j - 1] == 'K') {
        desc[j]++;
      }
    }
    int ans = 0;
    for (int i = 1; i <= sz; i++) {
      if (s[i - 1] == 'E') {
        ans += asc[i] * desc[i];
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}