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

int dfs(int node, map<int, int>& mem, vvi& graph){
    if(mem.find(node) != mem.end())
        return mem[node];
    int ans = 0;
    for(auto i : graph[node])
        ans += dfs(i, mem, graph) + 1;
    mem[node] = ans;
    return ans;
}

void solution(){
    int n; cin >> n; //just subtrees [!] (recurse!)

    vvi graph(n+1);

    forn(n-1){
        int t; cin >> t;
        graph[t].push_back(i+2);
    }

    map<int, int> subtree; //# of nodes in the subtree!
    for(int i = 1; i <= n; i++){
        dfs(i, subtree, graph);
    }

    ll ans = 0;

    for(int i = 1; i <= 1; i++){
        ans += subtree[i]/2 * (subtree[i]+1)/2;
    }

    cout << ans;
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
