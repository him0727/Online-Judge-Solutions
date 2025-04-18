#include <bits/stdc++.h>

using namespace std;

struct Rectangle {
  int id, x1, y1, x2, y2;
  
  bool vertical_overlap(Rectangle& another) {
    return y1 < another.y2 && y2 > another.y1;
  }
};

class Dsu {
private:
  vector<int> p, rank;

public:
  Dsu(int n) {
    p.resize(n);
    rank.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  int find(int x) {
    if (p[x] == x) {
      return x;
    }
    return p[x] = find(p[x]);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      if (rank[x] < rank[y]) {
        swap(x, y);
      }
      p[y] = x;
      if (rank[x] == rank[y]) {
        rank[x]++;
      }
    }
  }
};

int scan(Dsu& dsu, vector<Rectangle>& boxes, bool check_vertical) {
  sort(boxes.begin(), boxes.end(), [&](Rectangle& l, Rectangle& r) {
    if (check_vertical) {
      return l.x1 == r.x1 ? l.x2 < r.x2 : l.x1 < r.x1;
    }
    return l.y1 == r.y1 ? l.y2 < r.y2 : l.y1 < r.y1;
  });
  int ans = 0, last = 0;
  for (int i = 1; i < (int) boxes.size(); i++) {
    if (check_vertical ? boxes[i].x1 < boxes[last].x2 : boxes[i].y1 < boxes[last].y2) {
      if (dsu.find(boxes[i].id) != dsu.find(boxes[last].id)) {
        dsu.unite(boxes[i].id, boxes[last].id);
        ans += 1;
      }
    }
    if (check_vertical ? boxes[i].x2 >= boxes[last].x2 : boxes[i].y2 >= boxes[last].y2) {
      last = i;
    }
  }
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int N;
    cin >> N;
    Dsu overlap_set(N);
    vector<Rectangle> rectangles(N);
    vector<tuple<int, int, bool>> events(N * 2);
    for (int i = 0; i < N; i++) {
      rectangles[i].id = i;
      cin >> rectangles[i].x1 >> rectangles[i].y1 >> rectangles[i].x2 >> rectangles[i].y2;
      events[i * 2] = {rectangles[i].x1, i, true};
      events[i * 2 + 1] = {rectangles[i].x2, i, false};
    }
    sort(events.begin(), events.end(), [](tuple<int, int, bool>& l, tuple<int, int, bool>& r) {
      return get<0>(l) == get<0>(r) ? !get<2>(l) : get<0>(l) < get<0>(r);
    });
    set<pair<int, int>, greater<pair<int, int>>> active;
    for (tuple<int, int, bool> event : events) {
      int id = get<1>(event);
      if (get<2>(event)) {
        auto it = active.lower_bound(make_pair(rectangles[id].y2, -1));
        while (it != active.end()) {
          if (rectangles[(*it).second].vertical_overlap(rectangles[id])) {
            overlap_set.unite(id, (*it).second);
          }
          it++;
        }
        active.insert(make_pair(rectangles[id].y1, id));
      } else {
        active.erase(make_pair(rectangles[id].y1, id));
      }
    }
    unordered_map<int, vector<int>> components;
    for (int i = 0; i < N; i++) {
      int id = overlap_set.find(i);
      if (components.find(id) == components.end()) {
        components[id] = {rectangles[i].x1, rectangles[i].y1, rectangles[i].x2, rectangles[i].y2};
      } else {
        components[id][0] = min(components[id][0], rectangles[i].x1);
        components[id][1] = min(components[id][1], rectangles[i].y1);
        components[id][2] = max(components[id][2], rectangles[i].x2);
        components[id][3] = max(components[id][3], rectangles[i].y2);
      }
    }
    vector<Rectangle> bounding_boxes;
    int M = 0;
    for (auto it : components) {
      bounding_boxes.push_back({M++, it.second[0], it.second[1], it.second[2], it.second[3]});
    }
    Dsu box_set(M);
    int ans = scan(box_set, bounding_boxes, true) + scan(box_set, bounding_boxes, false);
    unordered_set<int> dedup;
    for (int i = 0; i < M; i++) {
      dedup.insert(box_set.find(i));
    }
    ans += ((int) dedup.size() - 1) * 2;
    cout << ans << "\n";
  }
  return 0;
}
