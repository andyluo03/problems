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

void solution(){
    int n, m; cin >> n >> m;

    //do the permutation then figure out?
    vector<vector<int>> ans(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        //populate time!
        
        //excess!
        if(i+1 >= m){
            ans[i][0] = m-1;
            for(int j = 1; j < m; j++){
                ans[i][j] = j-1;
            }
            continue;
        }

        //not excess!
        for(int j = 0; j < m; j++){
            ans[i][(i+j+1)%m] = j;
        }
    }

    set<int> mx;

    for(int i = 0; i < ans[0].size(); i++){
        //iterate by column :o
        set<int> f; 
        for(int j = 0; j < ans.size(); j++){
            f.insert(ans[j][i]);
        }
        int mex = 0;
        while(f.find(mex) != f.end())
            mex++;
        mx.insert(mex);
    }

    int mex = 0;

    while(mx.find(mex) != mx.end()){
        mex++;
    }

    cout << mex << endl;
    
    for(auto i : ans){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
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
