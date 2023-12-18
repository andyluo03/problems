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
    int n;
    cin >> n;
    vi a(n);
    map<int,int> mp;
    forn(n){
        cin >> a[i];
        mp[a[i]]++;
    }

    set<int> viable;
    for(auto i : mp){
        if(i.second >= 2)
            viable.insert(i.first);

        if(viable.size() >= 2)
            break;
    }

    if(viable.size() != 2){
        cout << "-1";
        return;
    }

    vi ans(n);
    for(int i = 0; i < a.size(); i++){
        ans[i] = 3;
    }

    int zz = 0;
    for(auto i : viable){
        bool seen = false;
        for(int t = 0; t < a.size(); t++){
            if(a[t] == i){
                if(!seen){
                    ans[t] = 1+zz;
                    seen = true;
                }else{
                    ans[t] = 2+zz;
                }
            }
        }
        zz++;
    }

    for(auto i : ans)
        cout << i << " ";
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
