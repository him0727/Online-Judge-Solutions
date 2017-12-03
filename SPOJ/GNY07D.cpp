#include <bits/stdc++.h>
 
using namespace std;
 
int t, r, c, id = 1;
char raw[22][22];
 
int main() {
  scanf("%d", &t);
  while (t--) {
    string s, s2 = "";
    cin >> r >> c >> s;
    int hl = 0, hu = c, vl = 0, vu = r;
    int cur = 0;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        raw[i][j] = s[cur++];
      }
    }
    while (vl < vu && hl < hu) {
      for (int i = hl; i < hu; i++) {
        s2 += raw[hl][i];
      }
      vl++;
      for (int i = vl; i < vu; i++) {
        s2 += raw[i][hu - 1];
      }
      hu--;
      if (vl < vu) {
        for (int i = hu - 1; i >= hl; i--) {
          s2 += raw[vu - 1][i];
        }
      }
      vu--;
      if (hl < hu) {
        for (int i = vu - 1; i >= vl; i--) {
          s2 += raw[i][hl];
        }
      }
      hl++;
    }
    printf("%d ", id++);
    for (int i = 0; i < s2.size() - (s2.size() % 5 ? s2.size() % 5 : 0); i += 5) {
      int dec = 0, base = 16;
      for (int j = 0; j < 5; j++) {
        dec += (s2[i + j] - '0') * base;
        base /= 2;
      }
      if (dec) printf("%c", 'A' + dec - 1);
      else printf(" ");
    }
    printf("\n");
  }
  return 0;
} 