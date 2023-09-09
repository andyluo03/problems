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

bool verify(set<ll>& toys, ll distance){
    //COULD BSEARCH, but iteration will pass!
    //assume toys is sorted !
    ll mx = *toys.rbegin();
    ll end_one = *toys.begin() + (2 * distance);
    if(end_one >= mx)
        return true;
    ll end_two = *toys.upper_bound(end_one) + (2*distance);
    if(end_two >= mx)
        return true;
    ll end_three = *toys.upper_bound(end_two) + (2*distance);

    return end_three >= mx;
}

void solution(){
    int n; cin >> n;
    //binary search !
    set<ll> a;
    forn(n){
        ll t; cin >> t;
        a.insert(t);
    }

    ll l = 0;  //safety first!
    ll h = 1e9;
    ll ans = 1e9;

    while(l <= h){
        ll m = l + (h-l)/2;

        if(verify(a, m)){
            ans = min(ans, m);
            h = m-1;
        }else{
            l = m+1;
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
