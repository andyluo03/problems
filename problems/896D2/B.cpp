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
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    //either closest to both major cities OR 
    pair<ll, ll> start;
    pair<ll, ll> end;
    vector<pair<ll, ll>> major;
    for(int i = 1; i <= n; i++){
        pair<ll, ll> tmp;
        cin >> tmp.first >> tmp.second;
        if(i <= k)
            major.push_back(tmp);
        if(i == a)
            start = tmp;
        if(i == b)
            end = tmp;
    }

    ll ans = abs(start.first - end.first) + abs(start.second - end.second);
    ll md_s = (ll) 4e9+10;
    ll md_e = (ll) 4e9+10;

    for(auto i : major){
        md_s = min(md_s, abs(i.first - start.first) + abs(i.second - start.second));
        md_e = min(md_e, abs(i.first - end.first) + abs(i.second - end.second));
    }

    ans = min(ans, md_s + md_e);
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
