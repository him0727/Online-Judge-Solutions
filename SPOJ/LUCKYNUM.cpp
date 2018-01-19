#include <bits/stdc++.h>
 
using namespace std;
 
struct Node {
  int n6, n8;
  int mod;
};
 
void bfs(int n) {
  queue<Node> q;
  Node cur;
  q.push(Node {1, 0, 6});
  q.push(Node {0, 1, 8});
  while (!q.empty()) {
    cur = q.front();
    q.pop();
    if (cur.n6 + cur.n8 > 200) {
      while (!q.empty()) {
        q.pop();
      }
      printf("-1\n");
      return;
    }
    if (cur.mod % n == 0) {
      while (!q.empty()) {
        q.pop();
      }
      for (int i = 0; i < cur.n8; i++) {
        printf("8");
      }
      for (int i = 0; i < cur.n6; i++) {
        printf("6");
      }
      printf("\n");
      return;
    }
    if (cur.n6 > 0) {
      int mod = (cur.mod * 10 + 6) % n;
      q.push(Node {cur.n6 + 1, cur.n8, mod});
    } else {
      int mod = (cur.mod * 10 + 6) % n;
      q.push(Node {cur.n6 + 1, cur.n8, mod});
      mod = (cur.mod * 10 + 8) % n;
      q.push(Node {cur.n6, cur.n8 + 1, mod});
    }
  }
}
 
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    if (n % 5 == 0) {
      printf("-1\n");
      continue;
    } 
    bfs(n);
  }
  return 0;
}