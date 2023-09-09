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
#define popv(n, v) for(int i = 0; i < n; i++){cin >> v[i];}

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

void to_tree(int n, vvi& graph){
    vector<int> level(n, -1);

    queue<int> q;
    q.push(0);

    while(q.size()){
        for(auto i : graph[q.front()]){
            if(level[i] == -1){
                level[i] = level[q.front()]+1;
                q.push(i);
            }
        }
        q.pop();
    }

    for(int i = 0; i < graph.size(); i++){
        vector<int> tv;
        for(auto j : graph[i])
            if(level[j] < level[i])
                tv.push_back(j);
        graph[i] = tv;
    }
}

void dp(int node, vvi& graph, vector<ll>& flow, vector<ll>& pop){
    
}

void solution(){
    int n; cin >> n;
    ll m; cin >> m;

    vector<ll> pop(n); 
    vector<ll> hap(n);

    popv(n, pop);
    popv(n, hap);

    vvi graph(n);

    forn((n-1)){
        int a, b; 
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    to_tree(n, graph);

    //NOW GRAPH IS A TREE !
    vector<ll> flow(n);
    dp(0, graph, flow, pop);

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
