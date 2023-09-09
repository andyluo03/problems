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

bool works(pair<int, int> trap, int k){
    return (2*(k-trap.first) < trap.second);
}

void solution(){
    int n; cin >> n;
    vector<pair<int, int>> traps(n);

    forn(n){
        cin >> traps[i].first;
        cin >> traps[i].second;
    }

    int l = 1;
    int h = 500;
    int ans = 1;

    while(l <= h){
        int m = l + (h-l)/2;

        bool good = true;
        for(auto i : traps){
            if(!works(i, m)){
                good = false;
            }
        }

        if(good){
            ans = max(ans, m);
            l = m+1;
        }else{
            h = m-1;
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
