/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"

typedef long long ll;

class TheUltimatePackages{
	vector <int> count(int N, int D, vector <int> Xprefix, vector <int> Yprefix, int L, int seed){


	}
};


int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int T;
	cin >> T;

	return 0;
}




// Problem Statement
// You are maintaining a repository that contains N software packages.

// Each software package x may have some dependencies: other packages that need to be installed before you can install x.

// There are no cyclic dependencies between the packages. You know this, because internally you have given the packages IDs from 0 to N-1 according to one possible way in which all of them can be installed. Hence, whenever package x depends on package y, you can be sure that x > y.


// You are now interested in ultimate packages. These are the packages that are related to everything in the whole repository.

// Formally, we say that a package x needs package y if either x directly depends on y, or x depends on some package z that needs y.

// Then, we say that a package u is an ultimate package if for each other package x either u needs x or x needs u.


// You are given the number of packages and all dependencies between them (as specified below). Find all ultimate packages in the repository. Return a with two elements: { the number of ultimate packages, the sum of IDs of ultimate packages }.


// The dependencies are given in arrays X and Y, each of length D. For each valid i, package X[i] depends on package Y[i]. Note that the same dependency may be listed multiple times.

// In order to keep the input size small, for large inputs X and Y will be generated pseudorandomly. Below we give pseudocode, Java code and C++ code that generates X and Y from the data you are given.


// Pseudocode:

// X, Y = two empty arrays of length D
// XL = length(Xprefix)
// for i = 0 to XL-1:
//     X[i] = Xprefix[i]
//     Y[i] = Yprefix[i]

// state = seed
// for i = XL to D-1:
//     state = (state * 1103515245 + 12345) modulo 2^31
//     elen = 1 + (state modulo L)
//     state = (state * 1103515245 + 12345) modulo 2^31
//     Y[i] = state modulo (N - elen)
//     X[i] = Y[i] + elen

// -----------------------------------------------------

// Java:

// int[] X = new int[D];
// int[] Y = new int[D];
// int XL = Xprefix.length;
// for (int i=0; i<XL; ++i) {
//     X[i] = Xprefix[i];
//     Y[i] = Yprefix[i];
// }

// long state = seed;
// for (int i=XL; i<D; ++i) {
//     state = (state * 1103515245 + 12345) % (1L << 31);
//     int elen = (int)(1 + state%L);
//     state = (state * 1103515245 + 12345) % (1L << 31);
//     Y[i] = (int)(state % (N - elen));
//     X[i] = Y[i] + elen;
// }

// -----------------------------------------------------

// C++:

// vector<int> X(D), Y(D);
// int XL = Xprefix.size();

// for (int i=0; i<XL; ++i) {
//     X[i] = Xprefix[i];
//     Y[i] = Yprefix[i];
// }

// long long state = seed;
// for (int i=XL; i<D; ++i) {
//     state = (state * 1103515245 + 12345) % (1LL << 31);
//     int elen = 1 + state%L;
//     state = (state * 1103515245 + 12345) % (1LL << 31);
//     Y[i] = state % (N - elen);
//     X[i] = Y[i] + elen;
// }

// Definition
// Class: TheUltimatePackages
// Method: count
// Parameters: int, int, vector <int>, vector <int>, int, int
// Returns: vector <int>
// Method signature: vector <int> count(int N, int D, vector <int> Xprefix, vector <int> Yprefix, int L, int seed)
// (be sure your method is public)
// Limits
// Time limit (s): 2.000
// Memory limit (MB): 256
// Notes
// - The reference solution does not depend on the input being pseudorandom.
// Constraints
// - N will be between 2 and 65,000, inclusive.
// - D will be between 0 and 300,000, inclusive.
// - Xprefix will contain between 0 and min(500,D) elements, inclusive.
// - Yprefix will contain the same number of elements as Xprefix.
// - For each i, N-1 >= Xprefix[i] > Yprefix[i] >= 0.
// - L will be between 1 and N-1, inclusive.
// - seed will be between 0 and 2^31 - 1, inclusive.
// Examples
// 0)
// 5
// 4
// {1, 3, 2, 4}
// {0, 2, 1, 3}
// 1
// 47
// Returns: {5, 10 }
// There are five packages and four dependencies: 4 depends on 3, 3 depends on 2, 2 depends on 1, and 1 depends on 0. Each of these five packages is ultimate.
// 1)
// 5
// 6
// {1, 2, 3, 4, 4, 4}
// {0, 0, 0, 1, 3, 2}
// 1
// 64
// Returns: {2, 4 }
// There are five packages: 1, 2, and 3 each depend on 0 and 4 depends on 1, 2, and 3.

// Ultimate packages are packages 0 and 4.

// 2)
// 5
// 4
// {2, 2, 3, 4}
// {0, 1, 2, 2}
// 1
// 32532
// Returns: {1, 2 }
// The only ultimate package here is package 2.
// 3)
// 4
// 3
// {3, 3, 2}
// {0, 2, 1}
// 1
// 2555
// Returns: {1, 3 }
// The only ultimate package here is package 3, because it needs all other packages.
// 4)
// 7
// 0
// {}
// {}
// 1
// 0
// Returns: {0, 0 }
// No ultimate packages here.
// 5)
// 2
// 4
// {1, 1, 1, 1}
// {0, 0, 0, 0}
// 1
// 0
// Returns: {2, 1 }
// A dependence listed four times is the same thing as a dependence listed once.
// 6)
// 7
// 12
// {2, 3, 4}
// {1, 2, 3}
// 5
// 4747
// Returns: {0, 0 }
// The generated arrays X and Y look as follows:

// X = { 2, 3, 4, 5, 6, 4, 4, 5, 4, 4, 5, 6 }
// Y = { 1, 2, 3, 1, 1, 1, 0, 1, 0, 1, 1, 1 }
// This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.