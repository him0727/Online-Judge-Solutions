#include <bits/stdc++.h>
 
using namespace std;
 
int sz = 0;
string hasht[110];
string os, what, key;
 
int hash_key(const string &k) {
  int pos = 0;
  for (int i = 1; i <= k.size(); i++) {
    pos += k[i - 1] * i; 
  }
  return (pos * 19) % 101;
}
 
int rehash(const int &base, const int &t) {
  return t > 19 ? base : (base + t * t + 23 * t) % 101;
}
 
int exist(const string &k, const int &v) {
  int j = 1, pos = v;
  if (!hasht[pos].empty() && hasht[pos] == k) {
    return pos;
  }
  do {
    pos = rehash(v, j++);
    if (!hasht[pos].empty() && hasht[pos] == k) {
      return pos;
    }
  } while (j <= 19);
  return -1;
}
 
void add(const string &k) {
  int pos = hash_key(k);
  if (exist(k, pos) != -1) {
    return;
  }
  int j = 1, pos2 = pos;
  while (!hasht[pos2].empty() && j <= 19) {
    pos2 = rehash(pos, j++);
    if (hasht[pos2].empty()) {
      pos = pos2;
      break;
    }
  }
  if (hasht[pos].empty()) {
    hasht[pos] = k;
    sz++;
  }
}
 
void del(const string &k) {
  int idx = exist(k, hash_key(k));
  if (idx != -1) {
    hasht[idx].clear();
    sz--;
  }
}
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 101; i++) {
      hasht[i].clear();
    }
    sz = 0;
    while (n--) {
      cin >> os;
      what = os.substr(0, 3);
      key = os.substr(4 , os.size());
      if (what == "ADD") {
        if (key.size() == 0) {
          continue;
        }
        add(key);
      } else if (what == "DEL") {
        del(key);
      }
    }
    printf("%d\n", sz);
    for (int i = 0; i < 101; i++) {
      if (!hasht[i].empty()) {
        cout << i << ":" << hasht[i] << "\n";
      }
    }
  }
  return 0;
}