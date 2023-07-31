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
    string t; cin >> t;
    vector<int> a(n);
    forn(n){a[i] = t[i]-'0';}

    vi zeros(n);
    vi ones(n);

    zeros[0] = a[0] == 0 ? 0 : INT_MIN;
    for(int i = 1; i < n; i++){
        if((zeros[i] == 0 && zeros[i-1] == 1) || a[i] == 1){
            zeros[i] = i;
        }else{
            zeros[i] = zeros[i-1];
        }
    }

    ones[n-1] = a[n-1] == 1 ? n-1 : INT_MAX;
    for(int i = n-2; i >= 0; i--){
        if((ones[i] == 1 && ones[i+1] == 0) || a[i] == 0)
            ones[i] = i;
        else
            ones[i] = ones[i+1];
    }

    pv(ones);
    pv(zeros);

    set<pair<int, int>> seen;

    forn(m){
        int l, r; cin >> l >> r;
        l--; r--;
        seen.insert({zeros[l], ones[r]});
    }

    cout << seen.size();
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
