#include <bits/stdc++.h>
 
using namespace std;
 
int n;
char s1[100001], s2[100001];
bool skip[4];
 
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) {
    scanf(" %c", &s1[i]);
  }
  for (int i = 0; i < 4; i++) {
    skip[i] = false;
  }
  skip[s1[0] - 'A'] = true;
  skip[s1[1] - 'A'] = true;
  for (int i = 0, j = 0; i < 4; i++) {
    if (!skip[i]) s2[j++] = (char) (i + 'A');
  }
  for (int i = 2; i < 2 * n; i += 2) {
    for (int j = 0; j < 4; j++) {
      skip[j] = false;
    }
    skip[s1[i] - 'A'] = true;
    skip[s1[i + 1] - 'A'] = true;
    for (int j = 0, k = 0; j < 4 && k < 2; j++) {
      if (!skip[j]) {
        s2[i + k++] = (char) (j + 'A');
      }
    }
    if (s2[i] == s2[i - 1]) swap(s2[i], s2[i + 1]);
  }
  for (int i = 0; i < 2 * n; i++) {
    printf("%c", s2[i]);
  }
  printf("\n");
  return 0;
}