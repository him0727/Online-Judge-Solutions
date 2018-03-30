#include <bits/stdc++.h>
 
using namespace std;
 
struct Level {
  int h, e, a;
  int id;
} level[110];
 
bool compare(const Level &left, const Level &right) {
  if (left.h != right.h) {
    return left.h > right.h;
  }
  if (left.e != right.e) {
    return left.e < right.e;
  }
  return left.a > right.a;
}
 
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &level[i].h, &level[i].e, &level[i].a);
    level[i].id = i + 1;
  }
  sort(level, level + n, compare);
  int easiest = level[0].id;
  int hardest = level[n - 1].id;
  if (easiest == hardest) {
    printf("Easiest and Hardest is level %d\n", easiest);
  } else {
    printf("Easiest is level %d\n", easiest);
    printf("Hardest is level %d\n", hardest);
  }
  return 0;
}