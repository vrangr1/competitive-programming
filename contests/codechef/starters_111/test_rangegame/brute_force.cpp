/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <unordered_set>
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
#include <unordered_map>
#include <bit>
#include <bitset>
#include <random>
#include <assert.h>
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#endif

using namespace std;

const long long INF = 2e18 + 69;

int t;
long long L, R, p;

int main() {
  cin >> t;
  while (t--) {
    // scanf("%lld %lld %lld", &L, &R, &p);
    cin >> L >> R >> p;
    vector <long long> tot;
    long long power = p;
    while (true) {
      tot.emplace_back(R / power - (L - 1) / power);
      if (power > INF / p) break; power *= p;
    }
    tot.emplace_back(0);
    int sum = 0;
    for (int i = 1; i < (int)tot.size(); ++i) {
      long long here = tot[i] - tot[i - 1];
      if (here & 1) sum ^= i;
    }
    // puts(sum ? "First" : "Second");
    if (sum) cout << "First\n";
    else cout << "Second\n";
  }
  return 0;
}

