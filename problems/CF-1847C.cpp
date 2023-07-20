//wecu's template -- works with c++17

#include <algorithm>
#include <bitset>
#include <climits>
#include <cstdlib>
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
    int n; cin >> n;
    vi a(n);
    forn(n){cin>>a[i];}
    vector<bool> prefix(256);
    int ans = 0;

    forn(a.size()){
        for(int can = 0; can < 256; can++){
            if(prefix[can])
                ans = max(ans, can^a[i]);
        }
        ans=max(ans, a[i]);
        vector<bool> tp(256);
        for(int can = 0; can < 256; can++){
            if(prefix[can]){
                tp[can^a[i]] = true;
            }
            tp[a[i]] = true;
        }
        prefix = tp;
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
