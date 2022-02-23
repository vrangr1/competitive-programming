#include <stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st_val, n) for (int i = st_val; i <= n; ++i)
#define forr(i, n) for (int i = n - 1; i >= 0; --i)
#define forsr(i, st_val, n) for (int i = st_val; i >= n; --i)
#define pb1(a) push_back(a)
#define pb2(a,b) push_back({a, b})
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define pb(...) GET_MACRO(__VA_ARGS__, pb1, pb2)(__VA_ARGS__)
#define pass (void)0
#define space " "
template <typename type> void print(const vector<vector<type> > &arr);
template <typename type> void print(const vector<type> &arr);
template <typename t1, typename t2> void print(const vector<pair<t1,t2> > &arr);
template <typename t1, typename t2> void print(const vector<vector<pair<t1,t2> > > &arr);
template <typename t1, typename t2> void print(const pair<t1, t2> &p);
#define print_var(x) cout << #x << ": " << x << "\n";
#define DEBUG_MODE true
class Solution {
public:
    inline int findOverallIndex(int ind1, int ind2){
        return (ind1 + ind2);
    }

    inline int overallIndicesToGo(int oInd, int mInd){
        return (mInd - oInd);
    }

    inline bool reachedMedian(int ind1, int ind2, int mInd){
        return (mInd == ind1 + ind2);
    }

    inline bool reachedMedian(int oInd, int mInd){
        return (mInd == oInd);
    }

    inline int findMiddle(int st, int end){
        return (st + end)/2;
    }

    void updateInds(vector<int> &nums1, vector<int> &nums2, int &ind1, int &ind2, int &s1, int &e1, int &s2, int &e2, bool increase){
        #if DEBUG_MODE
            print_var(increase);
            print_var(ind1);
            print_var(ind2);
        #endif
        if (nums1[ind1] < nums2[ind2]){
            if (increase){
                s1 = ind1;
                ind1 = findMiddle(ind1, e1);
                #if DEBUG_MODE
                    cout << "1\n";
                #endif
            }
            else{
                e2 = ind2;
                ind2 = findMiddle(s2, ind2);
                #if DEBUG_MODE
                    cout << "2\n";
                #endif
            } 
        }
        else{
            if (increase){
                s2 = ind2;
                ind2 = findMiddle(ind2, e2);
                #if DEBUG_MODE
                    cout << "3\n";
                #endif
            } 
            else{
                e1 = ind1;
                ind1 = findMiddle(s1, ind1);
                #if DEBUG_MODE
                    cout << "4\n";
                #endif
            } 
        }
        #if DEBUG_MODE
            cout << "after:\n";
            print_var(ind1);
            print_var(ind2);
        #endif
    }
    
    
    // bool updateIndsAfterMedianIndexReached(vector<int> &nums1, vector<int> &nums2, int &ind1, int &ind2, bool direction){
    //     // if (direction) ind1 = findMiddle(ind1, nums1.size() - 1);
    //     // else 
    // }


    bool actuallyReachedMedian(vector<int> &nums1, vector<int> &nums2, int ind1, int ind2){
        if (nums1[ind1] < nums2[ind2]){
            if (ind1 + 1 < nums1.size()-1 && nums1[ind1 + 1] < nums2[ind2]) return false;
            if (ind2 - 1 > 0 && nums2[ind2-1] > nums1[ind1]) return false;
        }
        else{
            if (ind2 + 1 < nums2.size()-1 && nums2[ind2 + 1] < nums1[ind1]) return false;
            if (ind1 - 1 > 0 && nums1[ind1-1] > nums2[ind2]) return false;
        }
        return true;
    }


    inline bool direction(vector<int> &nums1, vector<int> &nums2, int ind1, int ind2){
        return (nums1[ind1] < nums2[ind2]);
    }


    double findMedianOdd(vector<int> &nums1, vector<int> &nums2, int desInd){
        int ind1 = nums1.size()/2, ind2 = nums2.size() / 2, curInd;
        int start1 = 0, end1 = nums1.size(), start2 = 0, end2=  nums2.size();
        int counter = 0;
        #if DEBUG_MODE
            print_var(desInd);
        #endif
        while(!reachedMedian(ind1, ind2, desInd) || !actuallyReachedMedian(nums1, nums2, ind1, ind2)){
            counter++;
            #if DEBUG_MODE
                print_var(ind1);
                print_var(ind2);
            #endif
            if (counter > 50) {
                cout << "counter break\n";
                break;
            }
            if (reachedMedian(ind1, ind2, desInd)){
                #if DEBUG_MODE
                    cout << "reached median index\n";
                #endif
                updateInds(nums1, nums2, ind1, ind2, start1, end1, start2, end2, direction(nums1, nums2, ind1, ind2));
                #if DEBUG_MODE
                    cout << endl;
                #endif
                continue;
            }
            curInd = findOverallIndex(ind1, ind2);
            if (curInd == desInd) break;
            if (curInd < desInd) updateInds(nums1, nums2, ind1, ind2, start1, end1, start2, end2, true);
            else updateInds(nums1, nums2, ind1, ind2, start1, end1, start2, end2, false);
            #if DEBUG_MODE
                cout << endl;
            #endif
        }
        #if DEBUG_MODE
            print_var(ind1);
            print_var(ind2);
        #endif
        assert(!((ind1 == nums1.size()-1 && ind2 == 0) || (ind1 == 0 && ind2 == nums2.size() - 1)));
        if (ind1 == nums1.size() - 1 || ind1 == 0) return nums2[ind2];
        else if (ind2 == nums2.size() - 1 || ind2 == 0) return nums1[ind1];
        if (nums1[ind1] < nums2[ind2]){
            #if DEBUG_MODE
                cout << "returning: " << nums1[ind1] << endl;
            #endif
            return nums1[ind1];
        }
        else{
            #if DEBUG_MODE
                cout << "returning: " << nums2[ind2] << endl;
            #endif
            return nums2[ind2];
        }
    }
    
    double findMedianInSingleArray(vector<int> &nums){
        if (nums.size() % 2 == 1) return nums[nums.size() /2];
        return ((double)nums[nums.size()/2 - 1] + nums[nums.size() / 2])/2.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0) return findMedianInSingleArray(nums2);
        else if (nums2.size() == 0) return findMedianInSingleArray(nums1);
        nums1.push_back(INT_MIN);
        nums2.push_back(INT_MIN);
        nums1.insert(nums1.begin(), INT_MAX);
        nums2.insert(nums2.begin(), INT_MAX);
        int n1 = nums1.size(), n2 = nums2.size();
        double ans;
        if ((n1 + n2) % 2 == 1) ans = findMedianOdd(nums1, nums2, (n1 + n2)/2);
        else ans = ((findMedianOdd(nums1, nums2, (n1 + n2)/2) + findMedianOdd(nums1, nums2, (n1 + n2)/2 - 1)) / 2.0);
        nums1.pop_back();
        nums2.pop_back();
        nums1.erase(nums1.begin());
        nums2.erase(nums2.begin());
        return ans;
    }
};

//   0   1  2  3  4   5
// [max, 2, 2, 4, 4, min]
// [max, 2, 2, 4, 4, min]

// [max, 1, 2, 3, 4, 5, min]
// [max, 6, 7, 8, 9, 10, 11, min]

int main(){
    Solution obj;
    vector<int> vec1(2, 0), vec2(2,0);
    vec1[0] = 1;
    vec1[1] = 2;
    vec2[0] = 3;
    vec2[1] = 4;
    print(vec1);
    print(vec2);
    cout << "ans: " << obj.findMedianSortedArrays(vec1, vec2) << endl;
    return 0;
}


template <typename type> void print(const vector<vector<type> > &arr){
	cout << "\n[";
	forn(i, arr.size()){
		cout << "[";
		forn(j, arr[i].size() - 1)
			cout << arr[i][j] << ", ";
		cout << arr[i][arr[i].size() - 1] << "]";
		if (i != arr.size() - 1)
			cout << "," << endl;
	}
	cout << "], 2D Vector\n";
}


template <typename type> void print(const vector<type> &arr){
	cout << "\n[";
	forn(i, arr.size()){
		cout << arr[i];
		if (i != arr.size() - 1)
			cout << ", ";
	}
	cout << "], 1D Vector\n";
}


template <typename t1, typename t2> void print(const vector<pair<t1,t2> > &arr){
	int n = arr.size();
	cout << "\n[";
	forn(i, n - 1){
		cout << "{" << arr[i].first << "," << arr[i].second << "}, ";
	}
	cout << "{" << arr[n - 1].first << "," << arr[n - 1].second << "}], 1D Vector of Pairs\n";
}


template <typename t1, typename t2> void print(const vector<vector<pair<t1,t2> > > &arr){
	cout << "\n[";
	forn(i, arr.size()){
		cout << "[";
		forn(j, arr[i].size()){
			cout << "{" << arr[i][j].first << "," << arr[i][j].second << "}";
			if (j != arr[i].size() - 1)
				cout << ", ";
		}
		cout << "]";
		if (i != arr.size() - 1)
			cout << "," << endl;
	}
	cout << "], 2D Vector of Pairs\n";
}


template <typename t1, typename t2> void print(const pair<t1, t2> &p){
	cout << "\n{" << p.first << "," << p.second << "}, Pair\n";
}