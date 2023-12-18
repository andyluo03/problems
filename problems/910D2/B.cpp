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
    vi a(n);
    forn(n){cin>>a[i];}

    ll ans = 0;
    int msf = a[a.size()-1];
    for(int i = a.size()-2; i >= 0; i--){
        int ops = (a[i] + msf - 1) / msf;
        msf = a[i]/ops;

        //cout << i << " " << a[i] << " " << msf << endl; 
        ans += ops - 1;
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
