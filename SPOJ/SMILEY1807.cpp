#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  char s[1000010];
  cin.getline(s, 1000010);
  int f[4] = {0, 0, 0, 0};
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == '1') {
      f[0]++;
    }
    if (s[i] == '8') {
      if (f[0] > 0) {
        f[1] = max(f[0], f[1]) + 1;
      }
    }
    if (s[i] == '0') {
      if (f[1] > 0) {
        f[2] = max(f[1], f[2]) + 1;
      }
    }
    if (s[i] == '7') {
      if (f[2] > 0) {
        f[3] = max(f[2], f[3]) + 1;
      }
    }
  }
  printf("%d\n", f[3]);
  return 0;
}