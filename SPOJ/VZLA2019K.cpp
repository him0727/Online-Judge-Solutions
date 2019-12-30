#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n, d, p;
  cin >> n >> d >> p;
  vector<pair<int, int>> D, P;
  for (int i = 0; i < n; i++) {
    int b, c;
    char t;
    cin >> b >> c >> t;
    if (t == 'D') {
      D.push_back(make_pair(b, c));
    } else {
      P.push_back(make_pair(b, c));
    }
  }
  sort(D.begin(), D.end(), [](const pair<int, int> &l, pair<int, int> &r) {
    if (l.second == r.second) {
      return l.first < r.first;
    }
    return l.second < r.second;
  });
  sort(P.begin(), P.end(), [](const pair<int, int> &l, pair<int, int> &r) {
    if (l.second == r.second) {
      return l.first < r.first;
    }
    return l.second < r.second;
  });
  map<int, pair<int, int>> cntD;
  map<int, pair<int, int>> cntP;
  {
    int maxv = -1, minv = -1;
    for (int i = 0; i < (int) D.size(); i++) {
      if (D[i].first >= maxv) {
        minv = maxv;
        maxv = D[i].first;
      } else if (D[i].first < maxv && D[i].first > minv) {
        minv = D[i].first;
      }
      cntD[D[i].second] = make_pair(maxv, minv);
    }
  }
  {
    int maxv = -1, minv = -1;
    for (int i = 0; i < (int) P.size(); i++) {
      if (P[i].first >= maxv) {
        minv = maxv;
        maxv = P[i].first;
      } else if (P[i].first < maxv && P[i].first > minv) {
        minv = P[i].first;
      }
      cntP[P[i].second] = make_pair(maxv, minv);
    }
  }
  int ans = -1;
  {
    int posD = -1;
    int posP = -1;
    if ((int) D.size() > 0 && d >= D[0].second) {
      posD = lower_bound(D.begin(), D.end(), make_pair(100010, d)) - D.begin();
      posD = min(posD, (int) D.size() - 1);
      if (posD > 0 && D[posD].second > d) {
        posD--;
      }
      if (D[posD].second > d) {
        posD = -1;
      }
    }
    if ((int) P.size() > 0 && p >= P[0].second) {
      posP = lower_bound(P.begin(), P.end(), make_pair(100010, p)) - P.begin();
      posP = min(posP, (int) P.size() - 1);
      if (posP > 0 && P[posP].second > p) {
        posP--;
      }
      if (P[posP].second > p) {
        posP = -1;
      }
    }
    if (posD != -1 && posP != -1) {
      ans = max(ans, cntD[D[posD].second].first + cntP[P[posP].second].first);
    }
  }
  for (int i = 0; i < (int) D.size(); i++) {
    if (d - D[i].second <= 0) {
      continue;
    }
    int pos = lower_bound(D.begin(), D.end(), make_pair(100010, d - D[i].second), [](const pair<int, int> l, pair<int, int> r) -> bool {
    if (l.second == r.second) {
      return l.first < r.first;
    }
    return l.second < r.second;
  }) - D.begin();
    pos = min(pos, (int) D.size() - 1);
    if (pos > 0 && D[pos].second > d - D[i].second) {
      pos--;
    }
    if (D[pos].second > d - D[i].second) {
      continue;
    }
    pair<int, int> cur = cntD[D[i].second];
    pair<int, int> another = cntD[D[pos].second];
    if (another.first != cur.first || another.first == another.second) {
      ans = max(ans, another.first + cur.first);
    } else { 
      if (another.second != -1) {
        ans = max(ans, another.second + cur.first);
      }
      if (cur.second != -1) {
        ans = max(ans, another.first + D[i].second);
      }
    }
  }
  for (int i = 0; i < (int) P.size(); i++) {
    if (p - P[i].second <= 0) {
      continue;
    }
    int pos = lower_bound(P.begin(), P.end(), make_pair(100010, p - P[i].second), [](const pair<int, int> l, pair<int, int> r) -> bool {
    if (l.second == r.second) {
      return l.first < r.first;
    }
    return l.second < r.second;
  }) - P.begin();
    pos = min(pos, (int) P.size() - 1);
    if (pos > 0 && P[pos].second > p - P[i].second) {
      pos--;
    }
    if (P[pos].second > p - P[i].second) {
      continue;
    }
    pair<int, int> cur = cntP[P[i].second];
    pair<int, int> another = cntP[P[pos].second];
    if (another.first != cur.first || another.first == another.second) {
      ans = max(ans, another.first + cur.first);
    } else { 
      if (another.second != -1) {
        ans = max(ans, another.second + cur.first);
      }
      if (cur.second != -1) {
        ans = max(ans, another.first + D[i].second);
      }
    }
  }
  if (ans == -1) {
    cout << "sad:(" << '\n';
  } else {
    cout << ans << '\n';
  }
  return 0;
}