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
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    forn(n){
        cin >> a[i];
        cin >> b[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(3, LLONG_MAX));

    dp[0][0] = 0;
    dp[0][1] = b[0];
    dp[0][2] = b[0]*2;

    for(int i = 1; i < dp.size(); i++){
        for(int add = 0; add <= 2; add++){
            int t_val = a[i] + add;

            if(t_val != a[i-1])
                dp[i][add] = min(dp[i][add], dp[i-1][0] + add * b[i]);
            if(t_val != a[i-1]+1)
                dp[i][add] = min(dp[i][add], dp[i-1][1] + add * b[i]);
            if(t_val != a[i-1]+2)
                dp[i][add] = min(dp[i][add], dp[i-1][2] + add * b[i]);
        }
    }

    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
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
