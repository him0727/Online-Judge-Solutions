#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
int cur_s = 0, cur_w = 0;
char backyard[251][251];
bool visited[251][251];
 
void search(int i, int j) {
  if (visited[i][j] || backyard[i][j] == '#' || i >= n || j >= m) return;
  visited[i][j] = true;
  if (backyard[i][j] == 'k') cur_s++;
  else if (backyard[i][j] == 'v') cur_w++;
  if (i > 0) search(i - 1, j);
  if (i < n - 1) search(i + 1, j);
  if (j > 0) search(i, j - 1);
  if (j < m - 1) search(i, j + 1);
}
 
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &backyard[i][j]);
    }
  }
  int sheep = 0, wolve = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j] && backyard[i][j] != '#') {
        cur_s = 0, cur_w = 0;
        search(i, j);
        if (!i || !j || i == n - 1 || j == m - 1) {
          sheep += cur_s;
          wolve += cur_w;
        }
        else if (cur_s > cur_w) sheep += cur_s;
        else if (cur_s <= cur_w) wolve += cur_w;
      }
    }
  }
  printf("%d %d\n", sheep, wolve);
  return 0;
}