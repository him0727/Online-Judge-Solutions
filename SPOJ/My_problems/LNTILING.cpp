#include <bits/stdc++.h>

using namespace std;

string input(int n) {
  string tile = "";
  while (n--) {
    char dir;
    int len;
    cin >> dir >> len;
    tile += string(len, dir);
  }
  return tile;
}

bool match(int cur, string& gap, string& tile) {
  int n = (int) tile.size();
  if (cur + n > (int) gap.size()) {
    return false;
  }
  map<char, int> turn = {{'L', 0}, {'D', 1}, {'R', 2}, {'U', 3}};
  auto get_turn = [&](char a, char b) {
    return (turn[a] - turn[b] + 4) % 4;
  };
  bool fail = false;
  for (int i = 1; i + 1 < n && !fail; i++) {
    if (get_turn(tile[i], tile[i + 1]) != get_turn(gap[cur + i], gap[cur + i + 1])) {
      fail = true;
    }
  }
  if (!fail) {
    return true;
  }
  fail = false;
  for (int i = n - 1; i > 1 && !fail; i--) {
    if (get_turn(tile[i], tile[i - 1]) != get_turn(gap[cur + n - i], gap[cur + n - i + 1])) {
      fail = true;
    }
  }
  return !fail;
}

bool solve(int cur, int mask, vector<int>& f, string& gap, vector<string>& tiles) {
  if (cur == (int) gap.size()) {
    return f[mask] = 1;
  }
  if (f[mask] != -1) {
    return f[mask];
  }
  for (int i = 0; i < (int) tiles.size(); i++) {
    if ((mask & (1 << i)) != 0) {
      continue;
    }
    if (match(cur, gap, tiles[i])) {
      if (solve(cur + (int) tiles[i].size(), (mask | (1 << i)), f, gap, tiles)) {
        return f[mask] = 1;
      }
    }
  }
  return f[mask] = 0;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string gap = input(n);
    int m;
    cin >> m;
    vector<string> tiles;
    for (int i = 0; i < m; i++) {
      int k, c;
      cin >> k >> c;
      string tile = input(c);
      while (k--) {
        tiles.push_back(tile);
      }
    }
    vector<int> f(1 << (int) tiles.size(), -1);
    cout << (solve(0, 0, f, gap, tiles) ? "YES" : "NO") << '\n';
  }
}