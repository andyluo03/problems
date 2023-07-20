//wecu's template -- works with c++20

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

constexpr int MOD = 998244353;

int digits (int a) {
    int ans = 0;
    while (a) {
        a/=10;
        ans++;
    }
    return ans;
}

void first(int a, vector<int>& end, vector<int>& all, ll& ans){
    ll mul = 10;
    int itr = 0;
    while(a){
        ans = (ans + (( ((ll) all[itr]) * (a%10))%MOD * mul)%MOD)%MOD;
        ans = (ans + ((end[itr] * (a-(a%10))%MOD * mul)%MOD))%MOD;
        a/=10;
        itr++;
        mul=(mul*100)%MOD;
    }
}

void second(int a, vector<int>& end, vector<int>& all, ll& ans){
    ll mul = 1;
    int itr = -1;
    while(a){
        if(itr == -1)
            ans = (ans + (a%10) * all[0])%MOD;
        else {
            ans = (ans + ((((ll) all[itr]) * ((ll) a%10))%MOD * mul)%MOD)%MOD;
            ans = (ans + ((end[itr] * (a-(a%10)) * mul)%MOD))%MOD;
        }
        
        a/=10;
        itr++;
        mul=(mul*100)%MOD;
    }
}

void solution(){
    int n; cin >> n;
    vi a(n);
    int md = 0;
    forn(n){ cin >> a[i]; md = max(md, digits(a[i])); }
    vi end(md);
    vi all(md);

    forn(n){end[digits(a[i])-1] = (end[digits(a[i])-1]+1)%MOD;}
    all[md-1] = end[md-1];
    for(int i = md-2; i >= 0; i--){
        all[i] = (all[i+1] + end[i])%MOD;
    }

    ll ans = 0;

    pv(end);
    pv(all);

    for(int i : a){
        first(i, end, all, ans);
        second(i, end , all, ans);
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
