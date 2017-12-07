#include <bits/stdc++.h>
 
using namespace std;
 
int t;
 
int main() {
  scanf("%d", &t);
  while (t--) {
    int ng, nm, cg, cm;
    multiset<int> g;
    multiset<int> m;
    scanf("%d %d", &ng, &nm);
    for (int i = 0; i < ng; i++) {
      scanf("%d", &cg);
      g.insert(cg);
    }
    for (int i = 0; i < nm; i++) {
      scanf("%d", &cm);
      m.insert(cm);
    }
    while (1) {
      if (!g.size() || !m.size()) break;
      cg = *g.begin(), cm = *m.begin();
      if (cg < cm) g.erase(g.begin());
      else if (cg == cm || cm < cg) m.erase(m.begin());
    }
    if (!g.size() && !m.size()) printf("uncertain\n");
    else if (!g.size()) printf("MechaGodzilla\n");
    else printf("Godzilla\n");
  }
  return 0;
}