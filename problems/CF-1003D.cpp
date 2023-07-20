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

int mn(int n, map<int, int, greater<int>>& mp){
    int ans = 0;
    for(auto i : mp){
        if((ll) i.first * (ll) i.second > (ll) n){
            ans += n/i.first;
            n -= n/i.first * i.first;
        }else{
            ans += i.second;
            n -= i.first*i.second;
        }
    }
    return n == 0 ? ans : -1;
}

void solution(){
    int n, q; cin >> n >> q;
    map<int, int, greater<int>> mp;
    forn(n){
        int t; cin >> t;
        mp[t]++;
    }

    forn(q){
        int t; cin >> t;
        cout << mn(t, mp) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
    //cin >> tc;
    for(int i = 1; i <= tc; i++){
        solution();
        cout << endl;
    }
}
