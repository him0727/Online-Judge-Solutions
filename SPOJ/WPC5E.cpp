#include <bits/stdc++.h>
typedef long long int ll;
 
using namespace std;
 
int t, n;
 
struct Coord {
  ll x, y;
} coords[100001], convex[200001];
 
ll dist(Coord a, Coord b) {
  return ll (abs((a.x * a.x) - (b.x * b.x))) + ll (abs((a.y * a.y) - (b.y * b.y)));
}
 
ll dir(Coord a, Coord b, Coord c) {
  return ll ((b.x - a.x) * (c.y - a.y)) - ll ((c.x - a.x) * (b.y - a.y));
}
 
int next(int i, int j) {
  return i == j - 1 ? 0 : i + 1;
}
 
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%lld", &coords[i].y);
      coords[i].x = i + 1;
    }
    int a = 0;
    for (int i = 0; i < n; i++) {
      while (a > 1 && dir(convex[a - 2], convex[a - 1], coords[i]) <= 0) a--;
      convex[a++] = coords[i];
    }
    for (int i = n - 2, j = a; i >= 0; i--) {
      while (a > j && dir(convex[a - 2], convex[a - 1], coords[i]) <= 0) a--;
      convex[a++] = coords[i];
    }
    a--;
    ll distance = 0;
    for (int i = 0, j = 0; i < a; i++) {
      while (dist(convex[i], convex[next(j, a)]) > dist(convex[i], convex[j])) j = next(j, a);
      distance = max(distance, dist(convex[i], convex[j]));
    }
    printf("%lld\n", distance);
  }
  return 0;
}