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
    string db; cin >> db;
    int m; cin >> m;
    string l, r; cin >> l >> r;
    
    //next[index][character] --> next index of character
    vector<vector<int>> next(db.size() + 1, vector<int>(10, INT_MAX));

    for(int i = db.size()-1; i >= 0; i--){
        for(int n = 0; n <= 9; n++){
            next[i][n] = next[i+1][n];
            if(db[i] - '0' == n)
                next[i][n] = i+1;
        }
    }
    
    vector<int> dp(m, 0);

    for(int i = 0; i < dp.size(); i++){

        for(int ln = l[i] - '0'; ln <= r[i]-'0'; ln++){
            if(i == 0){
                dp[i] = max(dp[i], next[0][ln]);
                continue;
            }

            dp[i] = max(dp[i], next[dp[i-1]][ln]);
        }

        if(dp[i] == INT_MAX){
            cout << "YES";
            return;
        }
    }
    
    cout << "NO";
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
