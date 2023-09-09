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
    vector<vector<bool>> grid(n, vector<bool>(n, false));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<bool>> flip(n, vector<bool>(n, 0));
    //check if above is flipped !
    //dp[i][j] = dp[i-1][j-1] ^ dp[i-1][j] ^ dp[i-1][j+1] :)
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < n; j++){
            grid[i][j] = s[j]-'0';
        }
    }

    //BUT WHAT IF N IS <= 3 !
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            //START DP
            if(i == 1){
                if(j != 0)
                    dp[i][j] += dp[i-1][j-1];
                if(j != n-1)
                    dp[i][j] += dp[i-1][j+1];
                dp[i][j] += dp[i-1][j];
            }else if(i >= 2){
                if(j == 0){
                    dp[i][j] += dp[i-1][j+1];
                    //repeats
                    dp[i][j] += (flip[i-1][j] ? 1 : 0);
                }else if(j == n-1){
                    dp[i][j] += dp[i-1][j-1];
                    //repeats
                    dp[i][j] += (flip[i-1][j] ? 1 : 0);
                }else{
                    dp[i][j] += dp[i-1][j-1];
                    dp[i][j] += dp[i-1][j+1];
                    dp[i][j] -= dp[i-2][j];
                    dp[i][j] += (flip[i-1][j] ? 1 : 0);
                }
            }

            //END DP

            if(dp[i][j] % 2)
                grid[i][j] = !grid[i][j];

            if(grid[i][j] == 1){
                ans++;
                flip[i][j] = true;
                grid[i][j] = 0;
                dp[i][j]++;
            }
        }
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
