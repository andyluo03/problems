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
    int n, m; cin >> n >> m;
    map<int, vector<int>> mp;
    forn(n){
        int cur;
        for(int j = 0; j < m; j++){
            int t; cin >> t;
            if(j == 0){
                cur = t;
            }
            mp[cur].push_back(t);
        }
    }

    forn(m){
        for(int j = 0; j < n; j++){
            int t; cin >> t;
            if(mp.find(t) != mp.end()){
                for(auto f : mp[t]){
                    cout << f << " ";
                }
                cout << endl;
            }
        }
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
