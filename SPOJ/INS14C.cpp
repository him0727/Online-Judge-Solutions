#include <bits/stdc++.h>
 
using namespace std;
 
int t, n, k;
string source;
 
int main() {
  scanf("%d", &t);
  while (t--) {
    vector<int> s(1001);
    int one = 0, zero = 0;
    scanf("%d %d", &n, &k);
    cin >> source;
    for (int i = 0; i < n; i++) {
      s[i] = source[i];
      if (s[i] == '1') one++;
      else zero++;
    }
    int j = 1;
    while (n > k) {
      for (int i = 0; i < n; i++) {
        auto b = s.begin() + i;
        if (!one || !zero) {
          s.erase(b);
          break;
        }
        if (j & 1 && s[i] == '1') {
          s.erase(b);
          one--;
          break;
        }
        if (!(j & 1) && s[i] == '0') {
          s.erase(b);
          zero--;
          break;
        }
      }
      n--;
      j++;
    }
    for (int i = 0; i < k; i++) {
      printf("%c", s[i]);
    }
    printf("\n");
  }
  return 0;
}