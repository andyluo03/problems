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
    vector<pair<int, string>> a;
    forn(n){
        int t; string u;
        cin >> t >> u;
        a.push_back({t, u});
    }

    //case 1:
    int ans = INT_MAX;
    forn(n){
        if(a[i].second == "11")
            ans = min(ans, a[i].first);
    }

    //case 2:
    int mn_1 = INT_MAX;
    int mn_2 = INT_MAX;
    forn(n){
        if(a[i].second[0] == '1'){
            mn_1 = min(mn_1, a[i].first);
        }

        if(a[i].second[1] == '1'){
            mn_2 = min(mn_2, a[i].first);
        }
    }

    if(mn_1 == INT_MAX || mn_2 == INT_MAX){
        cout << -1;
        return;
    }

    cout << min(mn_1+mn_2, ans);
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
