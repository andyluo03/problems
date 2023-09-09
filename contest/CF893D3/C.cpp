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
#include <math.h>

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

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

void solution(){
    int l, r; cin >> l >> r;
    //ALWAYS MAKE GCD 2 (OR SAME?)
    if(r <= 3)
        cout << -1;
    else if(l == r && r % 2 == 1){
        //sometimes -1, sometimes not!
        for(int i = 1; i <= min((int) sqrtl(r) + 3, r); i++){
            if(r - i == 0)
                break;
            if(gcd(r-i, i) != 1){
                cout << i << " " << (r-i);
                return;
            }
        }
        
        cout << -1;
    }
    else {
        int ans = r/2;
        cout << ans << " " << ans;
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
