#include <bits/stdc++.h>
 
using namespace std;
 
unordered_map<long long, string> d;
unordered_map<string, int> k;
string op[100010];
char mro[6], mro2[6]; 
int p[100010];
 
int find(int i) {
  if (p[i] != i) {
    return p[i] = find(p[i]);
  }
  return i;
}
 
void uni(int i, int j) {
  int pi = find(i);
  int pj = find(j);
  if (pi != pj) {
    p[pi] = p[pj];
  }
}
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) { 
    int n, pid = 1;
    long long pesel;
    scanf("%d", &n);
    while (n--) {
      scanf("%lld %s", &pesel, mro);
      d[pesel] = mro;
      if (k[mro] == 0) {
        k[mro] = pid;
        op[pid++] = mro;
      }
    }
    for (int i = 1; i < pid; i++) {
      p[i] = i;
    }
    scanf("%d", &n);
    while (n--) {
      scanf("%s %s", mro, mro2);
      uni(k[mro], k[mro2]);
    }
    scanf("%d", &n);
    while (n--) {
      scanf("%lld", &pesel);
      printf("%lld %s\n", pesel, op[p[find(k[d[pesel]])]].c_str());
    }
    d.clear();
    k.clear();
  }
  return 0;
}