//wecu's template -- works with c++17
#pragma optimize("O3")
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

string& dfs(int l, int r, vector<int>& weights, vector<vector<string>>& dp){
    //substring dp !
    if(dp[l][r] != "") return dp[l][r];
    if(l >= r) return dp[l][r]; //defaults to ""
    if(weights[l] < weights[r]){
        dp[l][r] = "E";
        return dp[l][r];
    }
    
    string jesse = dfs(l+1, r, weights, dp);
    string jerry = dfs(l, r-1, weights, dp);

    if(jerry != "E"){
        dp[l][r] = 'B' + jerry;
        return dp[l][r];
    }
    else if(jesse != "E"){
        dp[l][r] = 'A' + jesse;
        return dp[l][r];
    }else{
        dp[l][r] = "E";
        return dp[l][r];
    }
}

void solution(){
    int n; cin >> n;
    vi a;
    a.push_back(0);
    forn(n){int t; cin >> t; a.push_back(t);}
    a.push_back(0);
    vector<vector<string>> dp(a.size(), vector<string>(a.size(), ""));
    cout << dfs(0, a.size()-1, a, dp);
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
