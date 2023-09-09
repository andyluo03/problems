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

ll calc(ll n, ll k){
    //# of subarrays of MINIMUM length k, inside n
    if(k > n){
        return 0;
    }
    ll ans = ((n-k)+2) * ((n-k)+1);
    ans/=2;
    return ans;
}

void solution(){
    ll n, k, q; cin >> n >> k >> q; //count subarrays!

    vector<ll> subsequences;
    ll cur = 0;
    forn(n){
        int t; cin >> t;
        if(t > q){
            subsequences.push_back(cur);
            cur = 0;
        }else{
            cur++;
        }
    }
    subsequences.push_back(cur);

    ll ans = 0;

    for(auto i : subsequences){
        ans += calc(i, k);
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
