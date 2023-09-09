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

ll summate(ll l, ll r){
    ll n = (r-l)+1;

    return ((l+r) * (n))/2;
}

ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

ll lcm (ll a, ll b) {
    return a / gcd(a, b) * b;
}

void solution(){
    ll n, x, y; cin >> n >> x >> y;

    //rearrange so there are x tops and y bottom (then remove intersections!)
    ll intersection = n / lcm(x,y); //actually change this to LCM!
    ll top = n / x;
    ll bottom = n / y;
    top -= intersection;
    bottom -= intersection;

    top = max(top, 0ll);
    bottom = max(bottom, 0ll);

    ll add = summate(n-top+1, n);
    ll subtract = summate(1, bottom);

    cout << (add-subtract);
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
