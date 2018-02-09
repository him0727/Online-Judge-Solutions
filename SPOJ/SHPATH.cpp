#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 10001;
 
map<string, int> cities;
int d[MAX];
vector<pair<int, int>> adj[MAX];
 
void dijkstra(int from, int to) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push(make_pair(0, from));
  d[from] = 0;
  while (!pq.empty()) {
    int v = pq.top().second;
    pq.pop();
    if (v == to) {
      printf("%d\n", d[v]);
      return;
    }
    for (int i = 0; i < adj[v].size(); i++) {
      int n = adj[v][i].first;
      int w = adj[v][i].second;
      if (d[v] + w < d[n]) {
        d[n] = d[v] + w;
        pq.push(make_pair(d[n], n));
      }
    }
  }
}
 
int main() {
  int t, nc, p, nr, cost, nq;
  string c, c1, c2;
  scanf("%d", &t);
  while (t--) {
    cities.clear();
    d[0] = INT_MAX;
    scanf("%d", &nc);
    for (int i = 1; i <= nc; i++) {
      cin >> c;
      cities[c] = i;
      d[i] = INT_MAX;
      scanf("%d", &p);
      for (int j = 0; j < p; j++) {
        scanf("%d %d", &nr, &cost);
        adj[i].push_back(make_pair(nr, cost));
      }
    }
    scanf("%d", &nq);
    while (nq--) {
      cin >> c1 >> c2;
      dijkstra(cities[c1], cities[c2]);
      for (int i = 0; i <= nc; i++) {
        d[i] = INT_MAX;
      }
    }
    for (int i = 0; i <= nc; i++) {
      adj[i].clear();
    }
  }
  return 0;
}