#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
  int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
  int a, b, c, d;
  while (scanf("%d %d %d %d", &a, &b, &c, &d) != EOF) {
    if (a == c && b == d) {
      printf("0\n");
      continue;
    }
    vector<vector<int>> board(8, vector<int> (8, -1));
    auto cmp = [&] (pair<pair<int, int>, int> l, pair<pair<int, int>, int> r) {
      return l.second > r.second;
    };
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, decltype(cmp)> pq(cmp);
    board[a][b] = 0;
    pq.push({{a, b}, 0});
    while (!pq.empty()) {
      pair<pair<int, int>, int> cur = pq.top();
      pq.pop();
      if (board[c][d] != -1 && board[cur.first.first][cur.first.second] >= board[c][d]) {
        continue;
      }
      for (int i = 0; i < 8; i++) {
        int xx = cur.first.first + dx[i];
        int yy = cur.first.second + dy[i];
        if (xx >= 8 || xx < 0 || yy >= 8 || yy < 0) {
          continue;
        }
        int dist = cur.first.first * xx + cur.first.second * yy;
        if (board[xx][yy] == -1 || board[xx][yy] > board[cur.first.first][cur.first.second] + dist) {
          board[xx][yy] = board[cur.first.first][cur.first.second] + dist;
          pq.push({{xx, yy}, dist});
        }
      }
    }
    printf("%d\n", board[c][d]);
  }
  return 0;
}