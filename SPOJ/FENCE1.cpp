#include <bits/stdc++.h>
 
using namespace std;
 
const double PI = acos(-1);
int l;
 
int main() {
  while (1) {
    scanf("%d", &l);
    if (!l) break;
    double r = l / PI;
    printf("%.2f\n", r * r * PI / 2);
  }
  return 0;
} 