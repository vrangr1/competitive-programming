#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

void pmfac(lli n, vector<pair<lli, lli>> &pm){
    lli count = 0;
    while(n % 2 == 0){
        ++count;
        n = n / 2;
    }
    pm.push_back(make_pair(2, count));
    count = 0;
    for (lli i = 3; i <= sqrt(n); i += 2){
        while (n % i == 0){
            count++;
            n = n / i;
            
        }
        pm.push_back(make_pair(i, count));
        count = 0;
    }
    if (n > 2){
        pm.push_back(make_pair(n, 1));
    }
}
void pmfac(int n, vector<pair<int, int>> &pm){
    int count = 0;
    while(n % 2 == 0){
        ++count;
        n = n / 2;
    }
    pm.push_back(make_pair(2, count));
    count = 0;
    for (int i = 3; i <= sqrt(n); i += 2){
        while (n % i == 0){
            count++;
            n = n / i;
            
        }
        pm.push_back(make_pair(i, count));
        count = 0;
    }
    if (n > 2){
        pm.push_back(make_pair(n, 1));
    }
}

int main() {
	int T;
	int q;
	lli p, x, a, b, rem1, rem2, ans, num1, num2;
	vector<pair<lli,lli>> pfr;
	vector<pair<int, int>> pfb;
	cin >> T;
	bool chance, ansf;
	while(T--){
	    cin >> p >> q;
	    if (p % q != 0){
	        cout << p << endl;
	    }
	    else if(p == q){
	        lli cop = p, count = 0;
	        while(cop % 2 == 0){
	            count++;
	            cop = cop/2;
	        }
	        num1 = 2;
	        rem1 = pow(2, count);
	        count = 0;
	        chance = true;
	        for (lli i = 0; i <= sqrt(cop); i += 2){
	            while(cop % i == 0){
	                count++;
	                cop = cop/ i;
	            }
	            
	            if(chance){
	                if (i > rem1){
	                    ansf = true;
	                    ans = p/rem1;
	                    break;
	                }
	                rem2 = pow(i, count);
	                if (rem1 < rem2){
	                    ansf = true;
	                    ans = p / rem1;
	                    break;
	                }
	                else{
	                    rem1 = rem2;
	                    continue;
	                }
	            }
	            
	            count = 0;
	        }
	        cout << ans << endl;
	    }
	    else{
	       // cout << "here1\n";
	        rem1 = -1;
	        rem2 = -1;
	        pmfac(q, pfb);
	        pmfac(p / q, pfr);
	        a = pfb.size();
	        b = pfr.size();
	        lli i = 0, j = 0;
	        if(pfb[i].first == pfr[j].first){
	            rem1 = pow(pfb[i].first, pfb[i].second + pfr[j].second);
	            i++;
	            j++;
	           // num1 = pfb[
	        }
	        else{
	            rem1 = pow(pfb[i].first, pfb[i].second);
	            ++i;
	        }
	        
	       // cout << "values: i , j " << i << " " << j << " " << a <<" " << b << endl;
	        while(true){
	           // cout <<"times\n";
	            if (i == a){
	                cout << p/rem1 << endl;
	                break;
	            }
	           // if(rem1 != -1){
	                
	           // }
	            while(j < b && pfb[i].first > pfr[j].first){
	                ++j;
	            }
	            if(j == b){
	               // cout << "reached here\n";
	                rem2 = pow(pfb[i].first, pfb[i].second);
	                if(rem1 < rem2)
	                cout << p/rem1 << endl;
	                else
	                cout << p/rem2 << endl;
	                break;
	            }
	            if (pfb[i].first == pfr[j].first){
	                rem2 = pow(pfb[i].first, pfb[i].second + pfr[j].second);
	                // if (j + 1 == b || i+1 == a){
	                //     cout << (p/rem1) << endl;
	                //     break;
	                // }
	                if (rem1 < pfb[i].first){
	                    cout << p/rem1 << endl;
	                    break;
	                }
	                else if(rem1 > rem2){
	                    rem1 = rem2;
	                    ++i;
	                    ++j;
	                    continue;
	                }
	                ++i; 
	                ++j;
	                continue;
	               // if (pfb[i+1].first == pfr[j+1].first){
	               //     rem2 = pow(pfb[i+1].first, pfb[i+1].second + pfr[j+1].second);
	               //     if (rem1 < pfb[i+1].first){
	               //         cout << p/rem1 << endl;
	               //         break;
	               //     }
	               //     else if( rem1 > rem2){
	               //         rem1 = rem2;
	               //         ++i;
	               //         ++j;
	               //         continue;
	               //     }
	               //     ++i;
	               //     ++j;
	               //     continue;
	                    
	               // }
	               // rem2 = pow(pfb[i+1].first, pfb[i+1].second);
	               // if (rem1 < pfb[i+1].first){
	               //         cout << p/rem1 << endl;
	               //         break;
	               // }
	               // else if( rem1 > rem2){
	               //     rem1 = rem2;
	               //     ++i;
	               //     ++j;
	               //     continue;
	               // }
	               // ++i;
	               // ++j;
	               // continue;
	            }
	            rem2 = pow(pfb[i].first, pfb[i].second);
	            if (rem1 < pfb[i].first){
	                cout << p/rem1 << endl;
	                break;
	            }
	            else if (rem1 > rem2){
	                rem1 = rem2;
	                i++;
	                continue;
	               // while(j < b && pfb[i].first < pfr[j].first ){
	               //     ++j;
	               // }
	            }
	            // if (i+1 == a){
	            //     cout << (p/rem1) << endl;
	            //     break;
	            // }
	           // else if(j+1 == b){
	           //     if(pfb[i+1].first == pfr[j].first){
	           //         rem2 = pow(pfb[i + 1].first, pfb[i + 1].second + pfr[j].second);
	           //         if (rem1 < pfb[i+1].first){
	           //             cout << p/rem1 << endl;
	           //             break;
	           //         }
	           //         else if (rem1 > rem2){
	           //             rem1 = rem2;
	           //             i++;
	           //             continue;
	           //         }
	           //         i++;
	           //         continue;
	           //     }
	           // }
	        }
	    }
	    pfb.clear();
	    pfr.clear();
	}
	return 0;
}

