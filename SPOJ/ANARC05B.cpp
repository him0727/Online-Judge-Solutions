#include <bits/stdc++.h>
 
using namespace std;
 
int arr1[10001], arr2[10001];
 
int main() {
  int n1, n2;
  while (1) {
    scanf("%d", &n1);
    if (n1 == 0) {
      break;
    }
    for (int i = 0; i < n1; i++) {
      scanf("%d", &arr1[i]);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
      scanf("%d", &arr2[i]);
    }
    int a = 0, b = 0;
    int sum1, sum2, ans = 0;
    while (a < n1 && b < n2) {
      sum1 = 0;
      sum2 = 0;
      do {
        if (arr1[a] == arr2[b]) {
          sum1 += arr1[a++];
          sum2 += arr2[b++];
        } else if (arr1[a] > arr2[b]) {
          sum2 += arr2[b++];
        } else if (arr2[b] > arr1[a]) {
          sum1 += arr1[a++];
        }
      } while (a < n1 && b < n2 && arr1[a] != arr2[b]);
      if (a >= n1) {
        while (b < n2) {
          sum2 += arr2[b++];
        }
      }
      if (b >= n2) {
        while (a < n1) {
          sum1 += arr1[a++];
        }
      }
      ans += max(sum1, sum2);
    }
    printf("%d\n", ans);
  }
  return 0;
}