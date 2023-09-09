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

ll l2 (ll n){
    ll ans = 1;
    for(ll i = 0; i < 62; i++){
        if(n <= (1 << i))
            break;
        if(n % (1 << i) == 0)
            ans = (1 << i);
    }
    return ans;
}

void solution(){
    ll x; cin >> x; //sus
    vector<int> ans;
    ll s = x;

    if(x % 2){
        ans.push_back(1);
        x--;
    }

    while(x > 1){
        if(x == 2){
            ans.push_back(1);
            break;
        }

        ans.push_back(l2(x));
        x-=ans[ans.size()-1];
    }
    cout << (ans.size()+1) << endl;
    cout << s << " ";
    for(auto i : ans){
        s -= i;
        cout << s << " ";
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
