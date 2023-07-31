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
using ll  = uint64_t;
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
    vector<ll> dp(n);

    ll ans = 0;
    long long z = LLONG_MIN;

    forn(n){
        long long t; cin >> t;
        z=max(z,t);
        if(t > 0)
            dp[i] = (uint64_t) t;
        if(i >= 2){
            dp[i] += dp[i-2];
        }

        ans = max(ans, dp[i]);
    }

    if(z>=0){
        cout << ans;
    }else{
        cout << z;
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
