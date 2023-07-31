//wecu's template -- works with c++17

#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define forn(n) for(int i = 0; i < n; i++)
#define endl '\n'

using namespace std;
using ll  = long long;
using pi  = pair<int, int>;
using vi  = vector<int>;
using vvi = vector<vector<int>>;

void pv(vi a) {
    #ifdef DEBUG 
    forn(a.size()){cout << a[i] << ", ";} cout << endl; 
    #endif
}

void solution(){
    int n; cin >> n;
    vector<int> a(n);
    bool has_pos = false;
    bool has_neg = false;
    forn(n){
        cin >> a[i];
        if(a[i] > 0) has_pos = true;
        if(a[i] < 0) has_neg = true;
    }

    if(!has_pos && !has_neg){
        cout << 0;
        return;
    }

    vector<pair<int, int>> ans;
    if(has_pos == false){
        for(int i = a.size()-2; i >= 0; i--){
            if(a[i] > a[i+1]){
                a[i] += a[i+1];
                ans.push_back({i, i+1});
            }
        }
    }else{
        int mxv = INT_MIN; 
        int mxi = -1;

        for(int i = 0; i < a.size(); i++){
            if(mxv < a[i]){
                mxi = i;
                mxv = a[i];
            }
        }

        while(a[mxi] < 20){
            a[mxi] *= 2;
            ans.push_back({mxi, mxi});
        }

        for(int i = 0; i < a.size(); i++){
            if(i != mxi){
                a[i] += a[mxi];
                ans.push_back({i, mxi});
            }
        }

        for(int i = 1; i < a.size(); i++){
            if(a[i] < a[i-1]){
                a[i] += a[i-1];
                ans.push_back({i, i-1});
            }
        }
    }

    pv(a);
    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i.first+1 << " " << i.second+1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
    cin >> tc;
    for(int i = 1; i <= tc; i++){
        solution();
        cout << endl;
    }
}
