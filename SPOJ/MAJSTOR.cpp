#include <bits/stdc++.h>
 
using namespace std;
 
int score[3][3] = {{1, 0, 2}, {2, 1, 0}, {0, 2, 1}};
string rn[51];
 
int battle(char a, char b) {
  int i = a == 'P' ? 0 : (a == 'S' ? 1 : 2);
  int j = b == 'P' ? 0 : (b == 'S' ? 1 : 2);
  return score[i][j];
}
 
int main() {
  int r, n;
  string rr;
  scanf("%d", &r);
  cin >> rr;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> rn[i];
  }
  int cs = 0, ms = 0;
  for (int i = 0; i < r; i++) {
    int ms1 = 0, ms2 = 0, ms3 = 0;
    for (int j = 0; j < n; j++) {
      cs += battle(rr[i], rn[j][i]);
      ms1 += battle('P', rn[j][i]);
      ms2 += battle('S', rn[j][i]);
      ms3 += battle('R', rn[j][i]);
    }
    ms += max(ms1, max(ms2, ms3));
  }
  printf("%d\n%d\n", cs, ms);
  return 0;
}