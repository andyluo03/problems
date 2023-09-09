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

ll square_range(int n){
    return ((n*(n+1)) * (2*n + 1))/6;
}

ll swap_range(int l, int h){
    //7, 8, 9, 10 --> 70, 70, 72, 72 SUBTRACT THE MAX
    if(l >= h)
        return 0;
    ll ans = 0;
    if((h-l)%2 == 0){
        for(int i = 0; i <= ((h-l)/2)-1; i++){
            ans += 2*(l+i)*(h-i);
        }
    }else{
        int mx = 0;
        for(int i = 0; i <= (h-l)/2; i++){
            ans += 2*(l+i)*(h-i);
            mx = max(mx, (l+i)*(h-i));
        }
        ans-=mx;
    }
    return ans;
}

void solution(){
    int n; cin >> n;
    ll ans = 0; //switch last two ?!

    //n bound by 500...
    for(int i = 0; i <= n; i++){
        ll t = square_range(i) + swap_range(i+1, n);
        if(i == n)
            t -= i*i;
        ans = max(ans, t);
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
