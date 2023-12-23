/*
Author: abhinav4279 (codechef)
*/
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
#include <queue>
#include <stack>
#include <list>
#include <forward_list>
#include <bit>
#include <bitset>
#include <array>
#include <assert.h>
using namespace std;

using ll = long long;
#define all(x) x.begin(), x.end()
#define dbg(x) cout << #x << ": " << x << endl;

const ll mod = 1e9 + 7;
const int L = 1e5 + 5;
ll dp[L][2];

ll rec(int l, int turn) {
  if(l <= 0)
    return 0;

  ll& ways = dp[l][turn];
  if(ways != -1)
    return ways;

  ways = rec(l - 1, 1 - turn);
  for(int rem = 2; rem < 4; rem++) {
    ways +=rec(l - rem, turn);
    ways %=mod;
  }
  if(l - 4 <= 0 && turn == 0)
    ways++;
  else 
    ways +=rec(l - 4, turn);
  ways %=mod;

  return ways;
}

void solve() {
  int l;
  cin >> l;

  cout << rec(l, 0) << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  memset(dp, -1, sizeof(dp));
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
}