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

const int MOD = (int) 1e9 + 7;

long long mod_pow (int a, int b) {
    long long ans = 1;
    long long prev = a%MOD;
    while (b) {
        if(b & 1){
            ans = ((long long) ans * prev) % MOD;
        }
        prev = (prev*prev)%MOD;
        b>>=1;
    }
    return ans;
}

void solution(){
    int n, m; cin >> n >> m;
    ll t = mod_pow(2, m)-1;
    cout << mod_pow(t, (ll) n);
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
