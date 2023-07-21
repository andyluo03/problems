//wecu's template -- works with c++17

#include <algorithm>
#include <bitset>
#include <climits>
#include <cstdint>
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
using ll  = uint64_t;
using pi  = pair<int, int>;
using vi  = vector<int>;
using vvi = vector<vector<int>>;

template <typename T>
void pv(vector<T> a) {
    #ifdef DEBUG 
    forn(a.size()){cout << a[i] << ", ";} cout << endl; 
    #endif
}

vector<ll> rows;
vector<vector<ll>> dp;

void generate_rows(){
    for(ll i = 1; i <= (ll) 2*1e3; i++)
        rows.push_back(((i*i)+i)/2);
}

int find_row(ll n){
    int l = 0;
    int h = (int) 2*1e3;
    int ans = 2*1e3;
    while(l <= h){
        int m = l + (h-l)/2;
        if(rows[m] >= n){
            h = m-1;
            ans = min(ans, m);
        }else{
            l = m+1;
        }
    }
    return ans;
}

void itr(){
    ll t = 1;
    for(int i = 0; i < 2*1e3; i++){
        dp.push_back({});
        for(int j = 0; j <= i; j++){
            dp[i].push_back(t*t);
            if(j != 0 && i != 0){
                dp[i][j] += dp[i-1][j-1];
            }
            if(j != i && i != 0){
                dp[i][j] += dp[i-1][j];
            }
            if(i > 1 && j != 0 && j != i){
                dp[i][j] -= dp[i-2][j-1];
            }
            t++;
        }
    }
}



void solution(){
    int n; 
    cin >> n;
    int row = find_row(n); //row+1 chars
    int pos = (int) row-(rows[row] - n);
    cout << dp[row][pos];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
    cin >> tc;
    generate_rows();
    itr();
    for(int i = 1; i <= tc; i++){
        solution();
        cout << endl;
    }
}
