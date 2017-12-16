#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, o, x, y;
int s[100001];
struct Node {
  int l_max, r_max, c_max, total;
} sg[800001];
 
int max2(int a, int b, int c) {
  return max(a, max(b, c));
}
 
void build(int node, int x, int y) {
  if (x == y) {
    sg[node] = Node {s[x], s[x], s[x], s[x]};
    return;
  }
  int mid = x + (y - x) / 2;
  build(2 * node, x, mid);
  build(2 * node + 1, mid + 1, y);
  Node left = sg[2 * node];
  Node right = sg[2 * node + 1];
  sg[node].total = left.total + right.total;
  sg[node].l_max = max2(left.l_max, left.total, left.total + right.l_max);
  sg[node].r_max = max2(right.r_max, right.total, right.total + left.r_max);
  sg[node].c_max = max2(left.c_max, right.c_max, left.r_max + right.l_max);
}
 
Node query(int node, int start, int end, int x, int y) {
  if (start == x && end == y) return sg[node];
  int mid = start + (end - start) / 2;
  int left = 2 * node, right = left + 1;
  if (x > mid) return query(right, mid + 1, end, x, y);
  if (y <= mid) return query(left, start, mid, x, y);
  Node l_node = query(left, start, mid, x, mid);
  Node r_node = query(right, mid + 1, end, mid + 1, y);
  Node res;
  res.total = l_node.total + r_node.total;
  res.l_max = max(l_node.l_max, l_node.total + r_node.l_max);
  res.r_max = max(r_node.r_max, r_node.total + l_node.r_max);
  res.c_max = max2(l_node.c_max, r_node.c_max, l_node.r_max + r_node.l_max);
  return res;
}
 
void update(int node, int start, int end, int index, int val) {
  if (start == index && end == index) {
    sg[node] = Node {val, val, val, val};
    return;
  }
  int mid = start + (end - start) / 2;
  int left = 2 * node, right = left + 1;
  if (index > mid) update(right, mid + 1, end, index, val);
  if (index <= mid) update(left, start, mid, index, val);
  Node l_node = sg[left];
  Node r_node = sg[right];
  sg[node].total = l_node.total + r_node.total;
  sg[node].l_max = max(l_node.l_max, l_node.total + r_node.l_max);
  sg[node].r_max = max(r_node.r_max, r_node.total + l_node.r_max);
  sg[node].c_max = max2(l_node.c_max, r_node.c_max, l_node.r_max + r_node.l_max);
}
 
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &s[i]);
  }
  build(1, 1, n);
  scanf("%d", &m);
  while (m--) {
    scanf("%d %d %d", &o, &x, &y);
    if (o) printf("%d\n", query(1, 0, n - 1, x - 1, y - 1).c_max);
    else update(1, 0, n - 1, x - 1, y);
  }
  return 0;
} 