#include <stdio.h>
#include <stdlib.h>
#define ll long long int
 
int compare(const void* a, const void* b) {
  return (*(ll*)a - *(ll*)b);
}
 
int main(void) {
  ll n;
  scanf("%lli", &n);
 
  for (ll current = 0; current < n; current++) {
    char blank[1];
    gets(blank);
    
    ll m;
    scanf("%lli", &m);
    ll rank[m];
    
    for (ll i = 0; i < m; i++) {
      char name[1000];
      scanf("%s %lli", &name, &rank[i]);
    }
    
    qsort(rank, m, sizeof(ll), compare);
    
    ll ans = 0;
    
    for (ll i = 0; i < m; i++) {
      ans += abs(i + 1 - rank[i]);
    }
    
    printf("%lli\n", ans);
  }
  return 0;
}  
