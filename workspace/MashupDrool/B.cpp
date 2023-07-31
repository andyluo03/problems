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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> a(m);
    forn(m){cin >> a[i];}

    //fast calculate !
    vector<vector<int>> prefix(26, vector<int>(n, 0));

    for(int i = 0; i < s.size(); i++){
        for(int c = 0; c < 26; c++){
            if(s[i]-'a' == c)
                prefix[c][i]++;
            if(i != 0)
                prefix[c][i] += prefix[c][i-1];
        }
    }

    vector<int> ans(26);
    
    for(int i = 0; i < a.size(); i++){
        for(int c = 0; c < 26; c++){
            ans[c] += prefix[c][a[i]-1];
        }
    }

    //calc last pass
    for(int c = 0; c < 26; c++){
        ans[c] += prefix[c][n-1];
    }
    
    forn(ans.size()){
        cout << ans[i] << " ";
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
