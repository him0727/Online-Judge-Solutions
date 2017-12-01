#include <bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
ll val[6] = {1, 4, 6, 5, 2, 0};
int t;
 
int main() {
  scanf("%d", &t);
  while (t--) {
    ll n;
    scanf("%lli", &n);
    printf("%d\n", val[--n % 6]);
  }
  return 0;
}