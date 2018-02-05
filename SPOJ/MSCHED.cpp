#include <bits/stdc++.h>
 
using namespace std;
 
vector<pair<int, int>> C;
bool used[10001];
 
bool compare(const pair<int,int> &a, const pair<int,int> &b) {
  return a.first > b.first;
}
 
int main() {
  int N;
  scanf("%d", &N);
  C.clear();
  while (N--) {
    pair<int, int> cow;
    scanf("%d %d", &cow.first, &cow.second);
    C.push_back(cow);
  }
  sort(C.begin(), C.end(), compare);
  int ans = 0;
  for (auto &v : C) {
    int bound = v.second;
    while (bound) {
      if (!used[bound]) {
        ans += v.first;
        used[bound] = true;
        break;
      }
      bound--;
    }
  }
  printf("%d\n", ans);
  return 0;
}