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
    int n, k; cin >> n >> k;
    vector<ll> a(n); forn(n){cin >> a[i];}
    //suffix for cost to upgrade + suffix for less than
    //n <= 1000... we CHILLIN
    //nlogk binary search!
    ll ans = 0;

    for(int i = 0; i < n-1; i++){
        //binary search for best
        ll l = a[i];
        ll h = a[i] + k;

        while(l <= h){
            ll m = l + (h-l)/2; //how much we think is possible
            ll moves = 0; //cover the difference
            ll goal = m;

            for(int j = i; j < n-1; j++){
                if(a[j] >= goal) break;

                moves += (goal - a[j]);
                goal--;

                if(j == n-2){
                    if(a[n-1] < goal)
                        moves = LLONG_MAX;
                }
            }

            if(moves <= k){
                ans = max(ans, m);
                l = m+1;
            }else{
                h = m-1;
            }
        }
    }

    ans = max(ans, a[n-1]); //check last

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
