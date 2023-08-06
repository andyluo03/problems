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

ll dfs(ll i , vector<map<ll, ll>>& graph, vector<ll>& dp, vector<ll>& coins){
    if(dp[i] != -1)
        return dp[i];
    ll ans = coins[i];

    if(graph[i].size() == 0){
        dp[i] = coins[i];
        return coins[i];
    }

    ll candidate = 0;
    for(auto t : graph[i]){
        candidate += t.second * dfs(t.first, graph, dp, coins);
        if(candidate > coins[i])
            break;
    }

    dp[i] = min(coins[i], candidate);
    return dp[i];
}

void solution(){
    int n, k; cin >> n >> k;
    vector<ll> c(n);
    vector<ll> dp(n, -1);
    forn(n){cin >> c[i];}
    forn(k){
        ll t; cin >> t;
        t--;
        c[t] = 0;
        dp[t]= 0;
    }

    vector<map<ll, ll>> graph(n);

    forn(n){
        ll m; cin >> m;
        for(int j = 0; j < m; j++){
            ll f; cin >> f; f--;
            graph[i][f]++;
        }
    }

    forn(n){
        dfs(i, graph, dp, c);
    }

    forn(n){
        cout << dp[i] << " ";
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
