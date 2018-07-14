#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n, m;
  scanf("%d", &n);
  int cnt[n + 1];
  fill(cnt, cnt + n + 1, 0);
  string s1, s2;
  cin.ignore();
  getline(cin, s1);
  getline(cin, s2);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    cnt[l]++;
    cnt[r + 1]--;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += cnt[i];
    if (sum & 1) {
      swap(s1[i], s2[i]);
    }
  }
  cout << s1 << '\n';
  cout << s2 << '\n';
  return 0;
}