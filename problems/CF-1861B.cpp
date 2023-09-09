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
    string a, b;
    cin >> a >> b;

    vector<bool> dp(a.size(), false);
    dp[0] = true;

    for(int i = 1; i < a.size(); i++){
        if(a[i] == b[i]){
            if(dp[i-1] == true || a[i] == '0'){
                dp[i] = true;
                continue;
            }

            for(int j = 1; j < i; j++){
                if(a[j] == b[j] && a[j] == a[i] && dp[j-1] == true){
                    dp[i] = true;
                }
            }
        }else{
            dp[i] = false; //this substring cannot be valid
        }
    }

    if(dp[a.size()-1])
        cout << "Yes";
    else
        cout << "No";
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
