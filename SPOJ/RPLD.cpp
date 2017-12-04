#include <bits/stdc++.h>
 
using namespace std;
 
int t, n, r;
int id, subject;
int tt = 1;
 
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &r);
    set<pair<int, int>> record;
    for (int i = 0; i < r; i++) {
      scanf("%d %d", &id, &subject);
      record.insert(make_pair(id, subject));
    }
    if (record.size() == r) printf("Scenario #%d: possible\n", tt++);
    else printf("Scenario #%d: impossible\n", tt++);
  }
  return 0;
}