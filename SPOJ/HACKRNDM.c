#include <stdio.h>
#include <stdlib.h>
#define ll long long int
 
int compare(const void* a, const void* b) {
  return (*(ll*)a - *(ll*)b);
}
 
int main(void) {
  ll n, k;
  scanf("%lli %lli", &n, &k);
  ll *pairs;
  pairs = malloc(n * sizeof(ll));
  for (ll i = 0; i < n; i++) {
    scanf("%lli", &pairs[i]);
  }
  int ans = 0;
  qsort(pairs, n, sizeof(ll), compare);
  for (ll i = 0; i < n; i++) {
    ll a_offset = pairs[i] + k;
    ll b_offset = pairs[i] - k;
    ll a_pos = (int*) bsearch(&a_offset, pairs, n, sizeof(ll), compare);
    ll b_pos = (int*) bsearch(&b_offset, pairs, n, sizeof(ll), compare);
    
    if (a_pos) ans++;
    if (b_pos) ans++;
  }
  ans /= 2;
  printf("%d", ans);
  return 0;
}