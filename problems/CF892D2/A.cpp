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
    map<int, int, less<int>> mp;
    int mx = INT_MIN;
    forn(n){
        int t; cin >> t;
        mp[t]++;
        mx = max(mx, t);
    }

    if(mp.size() == 1){
        cout << -1;
        return;
    }

    cout << (n - mp[mx]) << " " << mp[mx] << endl;

    for(auto i : mp){
        if(i.first == mx)   
            continue;
        for(int j = 0; j < i.second; j++)
            cout << i.first << " ";
    }

    cout << endl;

    for(int i = 0; i < mp[mx]; i++)
        cout << mx << " ";
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
