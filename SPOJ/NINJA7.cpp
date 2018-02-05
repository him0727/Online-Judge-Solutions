#include <bits/stdc++.h>
#define MAX 100001
typedef long long ll;
 
using namespace std;
 
int A[MAX], B[MAX];
int AB[MAX];
 
int main() {
  int t, N;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &N);
    int j = 0, ans = 0;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
      scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++) {
      scanf("%d", &B[i]);
      if (A[i] < B[i]) {
        AB[j++] = B[i] - A[i];
      } else {
        sum += A[i] - B[i];
        ans++;
      }
    }
    sort(AB, AB + j);
    for (int i = 0; i < j; i++) {
      if (sum < AB[i]) {
        break;
      }
      sum -= AB[i];
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}