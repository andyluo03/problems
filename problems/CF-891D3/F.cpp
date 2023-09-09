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
#include <cmath>

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

pair<ll, ll> dim_edge(ll x, ll y) {
    if(x > 0){ //search NEG ?

    }else{ //search POS ? 

    }
}

pair<ll, ll> dim(ll x, ll y){
    //a + b = x
    //a - b = y

    //binary search !
    ll l = 1;
    ll h = x-1; //find determinant (b^2 - 4ac)

    if(y < 0){
        return dim_edge(x, y);
    }
    bool neg = false;
    if(x < 0){
        neg = true;
        x = abs(x);
    }


    //both positive
    while(l <= h){
        ll m = l + (h-l)/2;

        ll t = x-m;

        if(m * t == y){
            if(neg)
                return {-m, -t};
            return {m, t};
        }
        
        if(m * t < y){
            l = m+1;
        }else{
            h = m-1;
        }
    }

    
    return {LLONG_MIN, LLONG_MIN};
}

void solution(){
    int n; cin >> n;
    map<ll, ll> a;
    forn(n){
        ll t; cin >> t;
        a[t]++;
    }

    int q; cin >> q;

    //handle +, + | -, + | -, - | !!!
    while(q > 0){
        ll x, y; cin >> x >> y;
        auto res = dim(x, y);
        if(res.first == res.second)
            cout << ((a[res.first] * (a[res.first]-1))/2) << " ";
        else
            cout << (a[res.first] * a[res.second]) << " ";
        q--;
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
