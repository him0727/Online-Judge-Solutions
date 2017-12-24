#include <bits/stdc++.h>
 
using namespace std;
 
int t;
string s1, s2;
 
int main() {
  scanf("%d", &t);
  while (t--) {
    cin >> s1 >> s2;
    bool neg1 = s1[0] == '-', neg2 = s2[0] == '-';
    int s1s = s1.size(), s2s = s2.size();
    if ((s1s <= 4 && s2s <= 4) || (s1 == "0" || s2 == "0")) {
      printf("%d\n", stoi(s1) * stoi(s2));
      continue;
    }
    if (neg1) {
      s1.erase(0, 1);
      s1s--;
    }
    if (neg2) {
      s2.erase(0, 1);
      s2s--;
    }
    int size = (s1s + s2s) * 2;
    int num[s2s + 1][size];
    for (int i = 0; i <= s2s; i++) {
      for (int j = 0; j < size; j++) {
        num[i][j] = 0;
      }
    }
    int carry = 0, length = size - 1;
    for (int i = 0, j = s2s - 1, k = size - 1; j >= 0; j--, i++, k--) {
      carry = 0;
      for (int x = s1s - 1, y = 0; x >= 0; x--, y++) {
        int nn = (s1[x] - '0') * (s2[j] - '0') + carry;
        if (carry > 0) carry = 0;
        if (nn > 9) {
          carry += nn / 10;
          nn %= 10;
        }
        num[i][k - y] = nn;
        if (x == 0 && carry > 0) num[i][k - (++y)] = carry;
        length = min(length, k - y);
      }
    }
    carry = 0;
    for (int i = size - 1; i >= length; i--) {
      int nn = 0;
      for (int j = 0; j < s2s; j++) {
        nn += num[j][i] + carry;
        if (carry > 0) carry = 0;
      }
      if (nn > 9) {
        carry += nn / 10;
        nn %= 10;
      }
      num[s2s][i] = nn;
      if (i == length && carry > 0) {
        num[s2s][i - 1] = carry;
        length--;
      }
    }
    if ((neg1 && !neg2) || (!neg1 && neg2)) printf("-");
    for (int i = size - (size - length); i < size; i++) {
      printf("%d", num[s2s][i]);
    }
    printf("\n");
  }
  return 0;
}