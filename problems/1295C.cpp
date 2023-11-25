//wecu's template -- works with c++17

#include <bits/stdc++.h>

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

const int INF = (int) 1e5 + 5;

void solution(){
    string s, t; cin >> s >> t;

    vector<vector<int>> next(s.size()+1, vector<int>(26, INF));
    for(int i = s.size()-1; i >= 0; i--){
        char cur = s[i];

        for(int c = 0; c < 26; c++){
            if(next[i+1][c] != INF){
                next[i][c] = next[i+1][c];
            }
        }

        next[i][cur-'a'] = i;
    }

    
    int ans = 1;
    int ptr = 0;
    for(int i = 0; i < t.size(); i++){
        if(ptr == INF || next[ptr][t[i]-'a'] == INF){
            ptr = 0;
            ans++;
        }
        
        ptr = next[ptr][t[i]-'a']+1;

        if(ptr == INF+1){
            cout << "-1";
            return;
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
