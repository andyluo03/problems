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

const ll MOD = (ll) 1e9 + 7;
const ll INF = (ll) 1e12;

long long mod_pow (ll a, ll b) {
    long long ans = 1;
    long long prev = a%MOD;
    while (b) {
        if(b & 1){
            ans = ((long long) ans * prev) % MOD;
        }
        prev = (prev*prev)%MOD;
        b>>=1;
    }
    return ans;
}

int search_greater(vector<ll>& a, ll v){
    int l = 0; 
    int h = a.size();
    int ans = a.size()-1;

    while(l <= h){
        int m = l + (h-l)/2;

        if(a[m] >= v){ //defaults left !
            h = m-1;
            ans = min(ans, m);
        }else{
            l = m+1;
        }
    }

    return ans;
}

int search_lower(vector<ll>& a, ll v){
    int l = 0;
    int h = a.size();
    int ans = 0;

    while(l <= h){
        int m = l + (h-l)/2;

        if(a[m] < v){
            ans = max(ans, m);
            l = m+1;
        }else{
            h = m-1;
        }
    }

    return ans;
}

void solution(){
    int n; cin >> n;
    vector<ll> a;
    forn(n){ll t; cin >> t; a.push_back(t);}

    //boundaries to make bsearch easier!
    a.push_back(-INF);
    a.push_back(INF);
    sort(a.begin(), a.end());

    ll ans = 0;

    for(int i = 1; i < a.size()-1; i++){
        for(int j = i+1; j < a.size()-1; j++){
            //calculate how many subsets i,j is a critical point
            ll distance = a[j] - a[i];

            //binary search boundaries!
            ll upper = search_greater(a, a[j]+distance);
            ll lower = search_lower(a, a[i]-distance);

            ll total = (a.size() - upper - 1) + (lower);
            
            ans += mod_pow(2, total);
            ans%=MOD;
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
    //cin >> tc;
    for(int i = 1; i <= tc; i++){
        solution();
        cout << endl;
    }
}
