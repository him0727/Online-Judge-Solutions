#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    long long n;
    cin >> n;
    cout << "Case " << qq << ": " << (n * (n + 1) / 2) % 2 << '\n';
  }
  return 0;
}