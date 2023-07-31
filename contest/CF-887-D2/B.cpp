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

void pv(vector<ll> a) {
    #ifdef DEBUG 
    forn(a.size()){cout << a[i] << ", ";} cout << endl; 
    #endif
}


vector<ll> dp_f1((int)2e5+3);
vector<ll> dp_f2((int)2e5+3);

void precal(){
    dp_f1[0] = 1;
    dp_f2[1] = 1;

    for(int i = 2; i < dp_f1.size(); i++){
        dp_f1[i] = dp_f1[i-1] + dp_f1[i-2];
        dp_f2[i] = dp_f2[i-1] + dp_f2[i-2];
    }
}
void solution(){
    int n, k; cin >> n >> k;

    if(k >= 2*1e5+3){ //we can easily bound K (?)
        cout << 0;
        return;
    }

    //dp
    ll a = dp_f2[k-1];
    ll b = dp_f1[k-1];
    
    ll ans = 0;

    for(int i = 1; i <= n; i++){
        int left_over = n - (i*a);
        if(left_over < 0)
            break;
        if(b == 0){
            if(left_over == 0)
                ans++;
            else
                continue;
        }
        else if(left_over == 0 || (left_over%b == 0 && left_over/b <= i)){
            ans++;
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
    cin >> tc;
    precal();
    pv(dp_f1);
    pv(dp_f2);
    for(int i = 1; i <= tc; i++){
        solution();
        cout << endl;
    }
}
