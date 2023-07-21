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
#include <numeric>

#define forn(n) for(int i = 0; i < n; i++)
#define endl '\n'

using namespace std;
using ll  = long long;
using pi  = pair<int, int>;
using vi  = vector<int>;
using vvi = vector<vector<int>>;

template <typename T>
void pv(vector<T> a) {
    #ifdef DEBUG 
    forn(a.size()){cout << a[i] << ", ";} cout << endl; 
    #endif
}

void solution(){
    ll a, b; cin >> a >> b;
    if(a > b)
        swap(a, b);
    ll offset = b-a;

    vector<ll> factors;
    for(int i = 1; i*i <= offset; i++){
        if(offset%i == 0){
            factors.push_back(i);
            if(i * i != offset)
                factors.push_back(offset/i);
        }
    }

    factors.push_back(0);
    sort(factors.begin(), factors.end());

    pv(factors);

    ll ans = LLONG_MAX;
    ll lcm = LLONG_MAX;
    for(ll i : factors){
        ll t_lcm = ((a+i) * (b+i))/gcd(a+i, b+i);
        if(t_lcm < lcm){
            lcm = t_lcm;
            ans = i;
        }
    }

    cout << ans;
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
