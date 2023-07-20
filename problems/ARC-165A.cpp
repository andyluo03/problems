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

ll fn(ll n){
    ll base = 1;
    while(base < n)
        base *= 3;
    ll ans = 0;
    while(base){
        ans += n/base;
        n=n%base;
        base/=3;
    }
    return ans;
}

void solution(){
    ll n, k; cin >> n >> k;
    int digit_sum = fn(n);
    if(digit_sum > k){
        cout << "No";
        return;
    }
    if((k-digit_sum)%2 == 0){
        cout << "Yes";
    }else{
        cout << "No";
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
