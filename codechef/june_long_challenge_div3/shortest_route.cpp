/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st_val, n) for (int i = st_val; i <= n; ++i)
#define push_back(a) pb(a)
#define pass (void)0
typedef long long int ll;


int main(){
  fastIO;
  int T;
  cin >> T;
  while(T--){
    int n, m, target;
    cin >> n >> m;
    vector<int> city(n), ans(n, -1);
    forn(i, n)
      cin >> city[i];
    int last = -1;
    forn(i, n){
      if (city[i] > 0){
        ans[i] = 0;
        if (city[i] == 1)
          last = i;
      }
      else{
        if (last != -1)
          ans[i] = i - last;
      }
    }
    last = -1;
    for(int i = n - 1; i >= 0; --i){
      if (city[i] == 2){
        last = i;
        continue;
      }
      if (city[i] == 0 && last != -1){
        if (ans[i] == -1)
          ans[i] = last - i;
        else
          ans[i] = min(ans[i], last - i);
      }

    }
    forn(i, m){
      cin >> target;
      target--;
      if (target == 0)
        cout << 0 << " ";
      else
        cout << ans[target] << " ";
    }
    cout << bline;
  }
  return 0;
}