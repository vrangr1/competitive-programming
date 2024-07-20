# To Do List:

## Snippets:
* Write Modular Int class.
    * Variable mod??
    * tourist: (https://codeforces.com/contest/1992/submission/269939496) (static)
               (https://codeforces.com/contest/1943/submission/251730537) (variable)
        
* Rolling Hash (allowing for handling of multiple bases and primes simultaneously).
* Either use AtCoder's lib or write your own generic Segtree implementation.
* General ncr setup.
* Finding nth root using binary search.
* Y-combinator (neal: https://codeforces.com/contest/1983/submission/269241095, tourist: https://codeforces.com/contest/1984/submission/264893993, ecnerwala: https://codeforces.com/contest/1949/submission/253078193)
* DSU
* Ordered set (treap) setup
* Ordered multi set (treap) setup

## Scripts:
### rtest:
* Incorporate tletest
* Allow rtest to copy over test cases or at least run bruteforce on test cases stored for the stress tester source.
* Add option to delete test cases
### sfile:
* Allow for option of TEST1
* Allow for creation of topcoder style template
### helper.sh:
* Actually add helper functions to helper.sh
### list_scripts
* Fix list_scripts
### cpr:
* Create the option to overwrite the correct answer of a test case.
* Create the option to split after the test cases and save them
* cpr -g bug. When 5 test files and 4th deleted and new one saved, 5th one overwritten.
* Check if the update to stack memory applies to GCC compiler with the same flag as the one needed for CLang.
### Overall:
* Write a script for setting up the script system
* Write a script for testing the entire script system
~~* Write an editor script~~

## Topics:
* Manacher's Algo (problem : ??)
* Z Algo
* Tarjan's Algo for articulation / cut points and bridges (cut edges).
* Montmort Numbers
* Factorial Number System
* Policy base Data Structres
    * Cartesian Trees / Treap: Cartesian Trees -> Treap -> Ordered Set from PBDS
    * Implicit Cartesian tree -> rope
* Zobrist Hashing
* Practice Lazy propagation in segment trees
* Finish Lehmer Codes
* Maximal Independent Sets
* Low Link Algorithm (for measuring #disjoint sets after removal of edges in a graph?) (https://atcoder.jp/contests/abc334/editorial/8988)
    -> Similar to Tarjan's Algo? 
* Aho Corasik algo
* Sparse Tables (https://codeforces.com/contest/1987/submission/268209905)
* Disjoint Sparse Table (https://codeforces.com/blog/entry/79108, https://discuss.codechef.com/t/tutorial-disjoint-sparse-table/17404)
* https://codeforces.com/blog/entry/91608?#comment-801782
* Y-combinator (neal: https://codeforces.com/contest/1983/submission/269241095, tourist: https://codeforces.com/contest/1984/submission/264893993, ecnerwala: https://codeforces.com/contest/1949/submission/253078193)
* LCA Forest (tourist: https://codeforces.com/contest/1975/submission/262558741)
* DFS Forest (tourist: https://codeforces.com/contest/1975/submission/262526751)
* FFT (tourist: https://codeforces.com/contest/1967/submission/258916135)
* Hungarian? (tourist: https://codeforces.com/contest/1955/submission/255672975)
* Fast Input: (ecnerwala: https://codeforces.com/contest/1949/submission/253100542)
* Fenwick Tree (tourist: https://codeforces.com/contest/1946/submission/252762720)
* Mo's algo
* SQRT Decomp
* Link-cut tree (https://codeforces.com/blog/entry/80383)
* eertree
* HLD
* Barrett Reduction for Modular Multplication
* Efficient LCA by using Sparse Trees
* AVL trees
* Red-black trees
* 2-3 trees


## Segment Trees?:
* Lazy segment tree (tourist: https://codeforces.com/contest/341/submission/267807488)
* Dynamic Simple Segment Tree ?? (tourist: https://codeforces.com/contest/484/submission/266247743)
* Persistent Simple Segment Tree?? (tourist: https://codeforces.com/contest/1771/submission/266244623)
    (https://codeforces.com/blog/entry/125561)
* Simple Segment Tree (tourist: https://codeforces.com/contest/380/submission/265506319)
* segtree?? (tourist: https://codeforces.com/contest/1969/submission/258720683)
* https://codeforces.com/contest/1942/submission/254161327


## Theory
* Cook-Levin's Theorem
* Church Turing Thesis
* Polynomial Hierarchies


## Refer Solution:
* Get count of smaller nodes in the subtree for every node (problem: [Insomnia 2k24 finals problem I](https://codeforces.com/gym/510369/problem/I))
* 

## Blog Topics:
* Ordered Set intro and list of methods (and how to convert it into an ordered multiset)
* const, constexpr as it relates to class methods and variables