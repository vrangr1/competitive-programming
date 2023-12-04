/**
 *    author:  tourist
 *    created: 07.11.2023 09:57:06       
**/
#include <iostream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <set>
#include <stdlib.h>
#include <map>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cmath>
#include <array>
#include <queue>
#include <stack>
#include <list>
#include <forward_list>
#include <bit>
#include <bitset>
#include <assert.h>

using namespace std;

#ifdef LOCAL
// #include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int m;
    cin >> m;
    vector<int> n(m);
    vector<long long> l(m), r(m);
    vector<vector<long long>> a(m);
    vector<vector<long long>> c(m);
    long long max_a = -1;
    vector<array<long long, 3>> all;
    vector<long long> tot(m);
    for (long long i = 0; i < m; i++) {
      cin >> n[i] >> l[i] >> r[i];
      a[i].resize(n[i]);
      for (int j = 0; j < n[i]; j++) {
        cin >> a[i][j];
        max_a = max(max_a, a[i][j]);
      }
      c[i].resize(n[i]);
      tot[i] = 0;
      for (int j = 0; j < n[i]; j++) {
        cin >> c[i][j];
        tot[i] += c[i][j];
      }
      for (int j = 0; j < n[i]; j++) {
        all.push_back({a[i][j], c[i][j], i});
      }
    }
    sort(all.rbegin(), all.rend());
    long long sum_l = 0;
    long long sum_r = 0;
    long long ans = (long long) 4e18;
    for (int i = 0; i < m; i++) {
      sum_l += l[i];
      sum_r += r[i];
      if (sum_r > max_a) {
        ans = 0;
        break;
      }
    }
    if (ans > 0) {
      int ptr = 0;
      while (ptr < (int) all.size() && all[ptr][0] > sum_r) {
        ptr += 1;
      }
      for (long long len = sum_r; len >= sum_l; len--) {
        long long sl = sum_l;
        long long sr = sum_r;
        long long must = 0;
        while (ptr < (int) all.size() && all[ptr][0] == len) {
          int i = all[ptr][2];
          long long cc = all[ptr][1];
          long long other = tot[i] - cc;
          if (other < r[i]) {
            sl -= l[i];
            sr -= r[i];
            if (other >= l[i]) {
              sl += l[i];
              sr += other;
//              can += r[i] - other;
            } else {
              sl += l[i];
              sr += l[i];
              must += l[i] - other;
            }
          }
          ptr += 1;
        }
        if (len > sr) {
          must += len - sr;
        }
        ans = min(ans, must);
        if (ans == 0) {
          break;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
