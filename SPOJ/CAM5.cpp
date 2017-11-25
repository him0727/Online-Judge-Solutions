#include <bits/stdc++.h>
#define l long int
#define ui unsigned int
 
using namespace std;
 
void dfs(l student, const vector<vector<l>> &relation, vector<bool> &visited) {
  visited[student] = true;
  for (ui i = 0; i < relation[student].size(); i++) {
    if (!visited[relation[student][i]]) {
      dfs(relation[student][i], relation, visited);
    }
  }
}
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    l no_peers, ans = 0;
    ui no_fd;
    scanf("%ld", &no_peers);
    scanf("%u", &no_fd);
    vector<vector<l>> relation(no_peers, vector<l>());
    vector<bool> visited(no_peers, false);
    for (ui i = 0; i < no_fd; i++) {
      l student1, student2;
      scanf("%ld %ld", &student1, &student2);
      relation[student1].push_back(student2);
      relation[student2].push_back(student1);
    }
    for (l i = 0; i < no_peers; i++) {
      if (!visited[i]) {
        dfs(i, relation, visited);
        ans++;
      }
    }
    printf("%ld\n", ans);
  }
  return 0;
}