#include <bits/stdc++.h>

using namespace std;

struct Gift {
  long long w, h, d;
};

vector<long long> solve(vector<Gift>& cur_gift, vector<Gift>& prev_gift, vector<long long> prev_ans) {
  vector<long long> ans(6);
  for (int now = 0; now < 6; now++) {
    long long cur_max = 0;
    Gift cur = cur_gift[now];
    for (int other = 0; other < 6; other++) {
      long long dh = 0, dd = 0;
      Gift prev = prev_gift[other];
      if (cur.h > prev.h) {
        dh = (cur.h - prev.h) * cur.d;
        if (cur.d <= prev.d) {
          dh <<= 1;
        }
      }
      if (cur.d > prev.d) {
        dd = (cur.d - prev.d) * cur.h;
        if (cur.h <= prev.h) {
          dd <<= 1;
        }
      }
      if (cur.h > prev.h && cur.d > prev.d) {
        dh -= (cur.d - prev.d) * (cur.h - prev.h);
        dh <<= 1;
        dd <<= 1;
      }
      cur_max = max(cur_max, cur.w * cur.d * 2 + cur.w * cur.h + prev_ans[other] + dd + dh);
    }
    ans[now] = cur_max;
  }
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<Gift>> gifts(n, vector<Gift>(6));
    for (int i = 0; i < n; i++) {
      long long w, h, d;
      cin >> w >> h >> d;
      gifts[i][0] = Gift {w, h, d};
      gifts[i][1] = Gift {w, d, h};
      gifts[i][2] = Gift {d, h, w};
      gifts[i][3] = Gift {d, w, h};
      gifts[i][4] = Gift {h, d, w};
      gifts[i][5] = Gift {h, w, d};
    }
    vector<long long> f(6);
    for (int i = 0; i < 6; i++) {
      Gift cur = gifts[0][i];
      f[i] = cur.w * cur.d * 2 + cur.h * cur.d * 2 + cur.w * cur.h;
    }
    for (int i = 1; i < n; i++) {
      f = solve(gifts[i], gifts[i - 1], f);
    }
    cout << *max_element(f.begin(), f.end()) << '\n';
  }
  return 0;
}