#include <bits/stdc++.h>
 
using namespace std;
 
const int upper = 1000000100;
 
struct NODE {
  int val;
  NODE *left, *right;
};
 
NODE *init(int v) {
  NODE *n = (NODE*) malloc(sizeof(NODE));
  n -> val = v;
  n -> left = n -> right = NULL;
  return n;
} 
 
int get_val(NODE *&root) {
  return root ? root -> val : 0;
}
 
void add(int low, int high, int val, NODE *&root) {
  if (!root) {
    root = init(0);
  }
  if (low == high) {
    root -> val++;
    return;
  }
  int mid = low + (high - low) / 2;
  if (val <= mid) {
    add(low, mid, val, root -> left);
  } else {
    add(mid + 1, high, val, root -> right);
  }
  root -> val = get_val(root -> left) + get_val(root -> right);
}
 
int cnt(int low, int high, int val, NODE *&root) {
  if (!root || low > val  || high < 1) {
    return 0;
  }
  if (low >= 1 && high <= val) {
    return get_val(root);
  }
  int mid = low + (high - low) / 2;
  return cnt(low, mid, val, root -> left) + cnt(mid + 1, high, val, root -> right);
}
 
int ksmall(int low, int high, int k, NODE *&root) {
  if (low == high) {
    return low;
  }
  int mid = low + (high - low) / 2;
  if (k <= get_val(root -> left)) {
    return ksmall(low, mid, k, root -> left);
  }
  return ksmall(mid + 1, high, k - get_val(root -> left), root -> right);
}
 
int main() {
  NODE *root = init(0);
  int n, q, foo, bar;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", &foo);
    add(1, upper, foo, root);
  }
  while (q--) {
    scanf("%d %d", &foo, &bar);
    if (foo == 1) {
      add(1, upper, cnt(1, upper, bar, root) + bar, root);
    }
    if (foo == 2) {
      printf("%d\n", cnt(1, upper, bar, root));
    }
    if (foo == 3) {
      if (bar > get_val(root)) {
        printf("invalid\n");
      } else {
        printf("%d\n", ksmall(1, upper, bar, root));
      }
    }
  }
  return 0;
}