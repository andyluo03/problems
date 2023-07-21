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

vector<pi> directions = {{0,1}, {1,0}, {0,-1}, {-1, 0}};

int dfs(int i , int j, vector<vector<int>>& g, vector<vector<bool>>& seen){
    if(i < 0 || j < 0 || j > g[0].size()-1 || i > g.size()-1)
        return 0;
    if(seen[i][j] || g[i][j] == 0)
        return 0;
    
    seen[i][j] = true;
    int ans = g[i][j];
    for(auto d : directions){
        ans += dfs(i+d.first, j+d.second, g, seen);
    }
    return ans;
}

void solution(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    forn(n){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }

    int ans = 0;
    vector<vector<bool>> seen(n, vector<bool>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans = max(ans, dfs(i, j, g, seen));
        }
    }

    cout << ans;
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
