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
    int n; cin >> n;
    
    multiset<int> a;
    map<int, vector<int>> mp;
    forn(n){
        int t;
        cin >> t;
        mp[t].push_back(i);
        a.insert(t);
    }

    vi ans(n);
    int pos = 0;
    for(int i = n; i > 0; i--){
        const auto chooseNegative = a.find(pos); // There are pos above that force POS
        const auto choosePositive = a.find(i + pos);
        
        bool foundNegative = chooseNegative != a.end();
        bool foundPositive = choosePositive != a.end();

        if(foundNegative == foundPositive){
            cout << "NO";
            return;
        }

        if(foundNegative){
            ans[mp[pos][mp[pos].size()-1]] = -i;
            mp[pos].pop_back();
            a.erase(chooseNegative);
        }else if(foundPositive){
            ans[mp[pos+i][mp[pos+i].size()-1]] = i;
            mp[pos+i].pop_back();
            a.erase(choosePositive);
            pos++;
        }
    }

    cout << "YES" << endl;
    for(auto i : ans){
        cout << i << " ";
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
