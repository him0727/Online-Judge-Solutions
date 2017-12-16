#include <bits/stdc++.h>
 
using namespace std;
 
string s;
int n, k, xk, yk;
char x, y;
int pos[26][2];
 
int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    k = s[i] - 'A';
    if (!pos[k][0]) {
      pos[k][0] = i + 1;
      pos[k][1] = i + 1;
    } else {
      pos[k][1] = i + 1;
    }
  }
  scanf("%d", &n);
  while (n--) {
    scanf(" %c %c", &x, &y);
    xk = x - 'A';
    yk = y - 'A';
    if (!pos[xk][0] || !pos[yk][0]) printf("TIDAK\n");
    else if (pos[yk][1] > pos[xk][0]) printf("YA\n");
    else printf("TIDAK\n");
  }
  return 0;
}