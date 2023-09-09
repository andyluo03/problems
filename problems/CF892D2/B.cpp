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

struct cmp {
    bool operator()(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
};

void solution(){
    int n; cin >> n; // just k greatest + min !
    vector<vector<int>> a(n);
    int mn = INT_MAX;

    forn(n){
        int m; cin >> m; // m >= 2 makes this a lot easier !
        for(int j = 0; j < m; j++){
            int t; cin >> t;
            a[i].push_back(t);
        }
        sort(a[i].begin(), a[i].end());
        mn = min(mn, a[i][0]);
    }

    sort(a.begin(), a.end(), cmp());

    ll ans = mn;

    for(int i = 1; i < a.size(); i++){
        ans += a[i][1];
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
