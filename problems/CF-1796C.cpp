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

const int MOD = 998244353;

int msize(int start, int end){
    int itr = end;
    int ans = 0;
    while(start <= itr){
        ans++;
        itr >>= 1;
    }
    return ans;
}

long long calc (ll start, ll end, ll count) {
    ll mult_2 = 1 << (count-1);

    ll ans = (end/mult_2)-start+1;
    //swap 3's!
    mult_2/=2;
    mult_2*=3;
    if(mult_2)
        ans += max(0ll, (count-1)*((end/mult_2)-start+1));
    return ans;
}

void solution(){
    int l, r; cin >> l >> r;

    int max_size = msize(l, r);

    cout << max_size << " " << calc(l, r, max_size);
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
