#include <bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
ll n, q, from, to;
int population[100007];
 
int main() {
  population[0] = 0;
  scanf("%lld", &n);
  for (ll i = 1; i <= n; i++) {
    scanf("%d", &population[i]);
    population[i] += population[i - 1];
  }
  scanf("%d", &q);
  while (q--) {
    scanf("%lld %lld", &from, &to);
    printf("%lld\n", population[to] - population[from - 1]);
  }
  return 0;
}  