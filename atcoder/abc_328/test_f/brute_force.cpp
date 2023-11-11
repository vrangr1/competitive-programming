// https://atcoder.jp/users/qiuzx_
// qiuzx_ 's solution. Obtained after the end of the contest to test my solution.
//ANMHLIJKTJIY!
// #pragma GCC optimize(2)
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
// #pragma GCC diagnostic error "-fwhole-program"
// #pragma GCC diagnostic error "-fcse-skip-blocks"
// #pragma GCC diagnostic error "-funsafe-loop-optimizations"
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
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,q,fa[N],sz[N],faed[N];
ll getf(ll x)
{
	return x==fa[x]?x:getf(fa[x]);
}
ll calc(ll x)
{
	return x==fa[x]?0:faed[x]+calc(fa[x]);
}
int main(){
	ll i,x,y,w;
	scanf("%lld%lld",&n,&q);
	for(i=0;i<n;i++)
	{
		fa[i]=i;
		sz[i]=1;
		faed[i]=0;
	}
	vector<ll> ans;
	for(i=0;i<q;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&w);
		x--,y--;
		ll fx=getf(x),fy=getf(y),vx=calc(x),vy=calc(y);
		if(fx==fy)
		{
			if(vy-vx==w)
			{
				ans.push_back(i);
			}
			continue;
		}
		ans.push_back(i);
		if(sz[fx]<sz[fy])
		{
			swap(fx,fy);
			swap(vx,vy);
			w=-w;
		}
		fa[fy]=fa[fx];
		faed[fy]=w+vx-vy;
		sz[fx]+=sz[fy];
	}
	for(i=0;i<ans.size();i++)
	{
		printf("%lld ",ans[i]+1);
	}
    printf("\n");
	return 0;
}