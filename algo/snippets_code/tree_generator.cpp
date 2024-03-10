/*
Details for snippet generator program:
title       : Tree Generator Snippet
prefix      : import_tree_generator
description : Tree Generator Snippet
*/
#ifndef TREE_GENERATOR_SNIPPET
#define TREE_GENERATOR_SNIPPET
#include <vector>
#include <assert.h>
#include <random>
#include <chrono>
std::mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
unsigned long long int grng(const unsigned long long int maxval){return rng()%maxval;}
/*
Returns: vector<vector<int>> : size n+1 -> Adjacency List
Every edge (u,v) is represented twice (once in each of their adjacency lists)
1 <= u,v <= n
*/
std::vector<std::vector<int>> generate_tree(const int maxn, const int maxdepth = INT_MAX){
    assert(maxn >= 1 && maxdepth >= 1);
    int n = ((int)grng(maxn))+1, d = ((int)grng(std::min(maxdepth,n))) + 1;
    if (n == 1) return {{},{}};
    std::vector<int> nodes(n);
    std::iota(nodes.begin(), nodes.end(),1);
    shuffle(nodes.begin(), nodes.end(),rng);
    int root = nodes.back();
    nodes.pop_back();
    std::vector<std::vector<int>> g(n+1);
    auto dfs = [&](auto &&self, int node, int depth) -> void {
        if (nodes.empty()) return;
        if ((int)(nodes.size()) == d-depth){
            int v = nodes.back();
            nodes.pop_back();
            g[node].push_back(v);
            g[v].push_back(node);
            self(self,v,depth+1);
            return;
        }
        int ct = ((int)grng(std::min((int)(nodes.size()),(int)(nodes.size())-(d-depth)+1))) + 1;
        while(ct--){
            assert(!nodes.empty());
            g[node].push_back(nodes.back());
            g[nodes.back()].push_back(node);
            nodes.pop_back();
        }
        for (int v : g[node])
            self(self,v,depth+1);
    };
    dfs(dfs,root,1);
    assert(nodes.empty());
    return g;
}
#endif