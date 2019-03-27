#include <bits/stdc++.h>
 
using namespace std; 
 
int main() {
  stack<int> left;
  queue<int> right;
  int d;
  while (scanf("%d", &d) != EOF) {
    if (d == 0) {
      while (!left.empty()) {
        left.pop();
      }
      while (!right.empty()) {
        right.pop();
      }
      printf("\n");
    } else if (d == -1) {
      int v = left.top();
      left.pop();
      printf("%d\n", v);
      if (right.size() > left.size()) {
        v = right.front();
        right.pop();
        left.push(v);
      }
    } else {
      if (left.size() == 0) {
        left.push(d);
      } else if (left.size() > right.size()) {
        right.push(d);
      } else if (left.size() <= right.size()) {
        right.push(d);
        int v = right.front();
        right.pop();
        left.push(v);
      }
    }
  }
  return 0;
}