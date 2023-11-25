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
    size_t n, q; cin >> n >> q;
    vector<long long> a(n);
    vector<int> x;

    forn(n){cin >> a[i];}
    forn(q){
        int t; cin >> t;
        if(x.size() == 0 || t < x[x.size()-1]){
            x.push_back(t);
        }
    }

    for(auto& i : a){
        for(auto j : x){
            if(i % (1<<j) == 0){
                i += (1<<(j-1));
            }
        }
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
