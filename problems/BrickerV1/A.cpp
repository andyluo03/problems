//wecu's template -- works with c++17

#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <map>
#include <math.h>
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

ll gcd(ll a, ll b){
    return b ? gcd (b, a % b) : a;
}

void solution(){
    ll x; cin >> x;
    
    ll ans = LLONG_MAX;
    pair<ll, ll> ret;
    for(ll i = 1; i <= sqrtl(x) + 4; i++){
        if(x % i == 0){
            ll other = x/i;
            if(gcd(other, i) == 1){
                ll m = max(other, i);
                if(m < ans){
                    ret = {other, i};
                    ans = m;
                }
            }
        }
    }

    cout << ret.first << " " << ret.second;
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
