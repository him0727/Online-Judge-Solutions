#include <bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
const ll SIZE = 1000007;
ll f, s, g, u, d;
bool visited[SIZE];
 
int main() {
  bool arrive = false;
  ll times = 0;
  scanf("%lli %lli %lli %lli %lli", &f, &s, &g, &u, &d); 
  for (ll i = 1; i <= f; i++) {
    visited[i] = false;
  }
  while (1) {
    if (visited[s]) break;
    visited[s] = true;
    if (s == g) {
      arrive = true;
      break;
    }
    if (s > g) {
      if (s - d >= 1) s -= d;
      else if (s + u <= f) s += u;
      times++;
    }
    if (s < g) {
      if (s + u <= f) s += u;
      else if (s - d >= 1) s -= d;
      times++;
    }
  }
  if (arrive) printf("%lli\n", times);
  else printf("use the stairs\n");
  return 0;
}