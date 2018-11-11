#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;

  point rotate(int angle) {
    double rad = (double) angle / 180.0 * acos(-1);
    int dx = (int) round(x * cos(rad) - y * sin(rad));
    int dy = (int) round(x * sin(rad) + y * cos(rad));
    return point {dx, dy};
  }

  point operator + (const point& add) {
    return point {x + add.x, y + add.y};
  }

  point operator - (const point& sub) {
    return point {x - sub.x, y - sub.y};
  }
  
  point& operator -= (const point& sub) {
    x -= sub.x; y -= sub.y;
    return *this;
  }

  bool operator == (const point& p) const {
    return x == p.x && y == p.y;
  }
};

bool done;
int total_dist, tile_dist, n_tile;
int dest[110], cache[21][110];
point vtx[21], pos[110];
vector<point> rotation[21][4];
vector<int> tile_pointer;

bool hit(point from, point to, int dist) {
  point head = pos[dist];
  point tail = vtx[dest[dist]];
  if (from == to) {
    return true;
  }
  if ((head.y == tail.y) != (from.y == to.y)) {
    return false;
  }
  if (head.y == tail.y) {
    if (head.x > tail.x && to.x <= head.x && to.x >= tail.x) return true;
    if (head.x < tail.x && to.x >= head.x && to.x <= tail.x) return true;
  } else {
    if (head.y > tail.y && to.y <= head.y && to.y >= tail.y) return true;
    if (head.y < tail.y && to.y >= head.y && to.y <= tail.y) return true;
  }
  return false;
}

void match(int mask, int dist) {
  if (done) {
    return;
  }

  for (int cur = 0; cur < n_tile; cur++) {
    if (((mask >> cur) & 1) == 0) {
      int i = tile_pointer[cur];
      bool is_fit;
      if (cache[i][dist] == 0) {
        continue;
      }
      if (cache[i][dist] > 0) {
        match(mask | (1 << cur), cache[i][dist]);
      }
      if (cache[i][dist] == -1) {
        for (int j = 0; j < 4; j++) {
          is_fit = true;
          int sz = rotation[i][j].size();
          int cur_dist = dist;
          point offset = pos[cur_dist];
          for (int k = 1; k < sz; k++) {
            point from = rotation[i][j][k - 1] + offset;
            point to = rotation[i][j][k] + offset;
            if (!hit(from, to, cur_dist)) {
              is_fit = false;
              break;
            }
            cur_dist += abs(to.x - from.x) + abs(to.y - from.y);
          }
          if (!is_fit) {
            is_fit = true;
            cur_dist = dist;
            point offset = pos[cur_dist] - rotation[i][j][sz - 1];
            for (int k = sz - 1; k > 0; k--) {
              point from = rotation[i][j][k] + offset;
              point to = rotation[i][j][k - 1] + offset;
              if (!hit(from, to, cur_dist)) {
                is_fit = false;
                break;
              }
              cur_dist += abs(to.x - from.x) + abs(to.y - from.y);
            }
          }
          if (is_fit) {
            if (cur_dist == total_dist) {
              done = true;
              return;
            }
            cache[i][dist] = cur_dist + 1;
            break;
          }
        }
        if (is_fit) {
          match(mask | (1 << cur), cache[i][dist]);
        } else {
          cache[i][dist] = 0;
        }
      }
    }
  }
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int longest_edge = 2;
    n_tile = 0;
    total_dist = 0, tile_dist = 0;
    done = false;

    char dir;
    int dist;
    {
      int n;
      scanf("%d", &n);
      int cur_x = 0, cur_y = 0;
      vtx[1] = pos[0] = point {0, 0};
      for (int i = 1; i <= n; i++) {
        scanf(" %c %d", &dir, &dist);
        longest_edge = max(longest_edge, dist);
        int dx = dir == 'U' ? 1 : dir == 'D' ? -1 : 0;
        int dy = dir == 'R' ? 1 : dir == 'L' ? -1 : 0;
        cur_x += dist * dx;
        cur_y += dist * dy;
        point offset = point {dx, dy};
        for (int j = 1; j <= dist; j++) {
          pos[total_dist + j] = pos[total_dist + j - 1] + offset;
        }
        for (int j = 1; j < dist; j++) {
          dest[total_dist + j] = i + 1;
        }
        dest[total_dist + dist] = i + 2;
        if (i == 1) {
          for (int j = 1; j <= dist; j++) {
            pos[total_dist + j] -= offset;
          }
          cur_x -= dx;
          cur_y -= dy;
        }
        total_dist += dist;
        if (!(cur_x == vtx[i].x && cur_y == vtx[i].y)) {
          vtx[i + 1] = point {cur_x, cur_y};
        }
      }
      dest[total_dist] = dest[total_dist - 1];
    }

    int m;
    {
      int t, v;
      int good = 0;
      scanf("%d", &m); 
      for (int i = 0; i < m; i++) {
        scanf("%d %d", &t, &v);
        int cur_x = 0, cur_y = 0;
        int temp_dist = 0;
        bool is_bad = false;
        for (int j = 0; j < 4; j++) {
          rotation[good][j].push_back(point {0, 0});
        }
        for (int j = 1; j <= v; j++) {
          scanf(" %c %d", &dir, &dist);
          if (dist > longest_edge) {
            is_bad = true;
          }
          if (!is_bad) {
            int dx = dir == 'U' ? 1 : dir == 'D' ? -1 : 0;
            int dy = dir == 'R' ? 1 : dir == 'L' ? -1 : 0;
            cur_x += dist * dx;
            cur_y += dist * dy;
            if (j == 1) {
              cur_x -= dx;
              cur_y -= dy;
            }
            rotation[good][0].push_back(point {cur_x, cur_y});
            temp_dist += dist;
          }
        }
        if (!is_bad) {
          for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= v; k++) {
              rotation[good][j].push_back(rotation[good][j - 1][k].rotate(j * 90));
            }
          }
          for (int j = 0; j < t; j++) {
            tile_pointer.push_back(good);
          }
          tile_dist += temp_dist * t;
          n_tile += t;
          good++;
        } else {
          for (int j = 0; j < 4; j++) {
            rotation[good][j].clear();
          }
        }
      }
      m = good;
    }

    if (tile_dist >= total_dist) {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j <= tile_dist; j++) {
          cache[i][j] = -1;
        }
      }
      match(0, 1);
    }

    printf(done ? "YES\n" : "NO\n");

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < 4; j++) {
        rotation[i][j].clear();
      }
    }
    tile_pointer.clear();
  }
  return 0;
}