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
    int n; cin >> n;
    vi a(n), b(n);
    forn(n){cin >> a[i];}
    forn(n){cin >> b[i];}

    vector<int> val(n);

    int mx = INT_MIN;
    forn(n){
        val[i] = a[i]-b[i];
        mx = max(mx, val[i]);
    }

    vector<int> ans;
    forn(n){
        if(val[i] == mx){
            ans.push_back(i+1);
        }
    }

    cout << ans.size() << endl;
    forn(ans.size()){
        cout << ans[i] << " ";
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
