#include <stdio.h>
#include <stdlib.h>
#define ll long long int
 
using namespace std;
 
int main() {
  int total;
  scanf("%d", &total);
  while (total--) {
    ll n;
    bool wrong = false;
    scanf("%lli", &n);
    ll *heights;
    heights = (ll*) malloc(n * sizeof(ll));
    for (ll i = 0; i < n; i++) {
      scanf("%lli", &heights[i]);
      if (heights[i] > i) wrong = true;
    }
    if (wrong) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
  return 0;
}