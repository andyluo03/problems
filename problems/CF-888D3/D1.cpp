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

ll tot (ll n) {
    return ((n+1) * n)/2;
}

void solution(){
    ll n; cin >> n;
    vector<ll> a(n-1);
    forn(n-1){cin >> a[i];}

    set<ll> mp;
    forn(n){mp.insert(i+1);}

    for(int i = 1; i < a.size(); i++){
        if(a[i] <= a[i-1]){
            cout << "No";
            return;
        }
    }

    //handle last
    if(a[a.size()-1] != tot(n)){
        for(int i = 0; i < a.size(); i++){
            if(i == 0){
                if(mp.find(a[i]) == mp.end()){
                    cout << "No";
                    return;
                }
                mp.erase(mp.find(a[i]));
            }else{
                if(mp.find(a[i] - a[i-1]) == mp.end()){
                    cout << "No";
                    return;
                }
                mp.erase(mp.find(a[i] - a[i-1]));
            }
        }

        ll t = 0;
        for(auto i : mp)
            t+=i;
        if(tot(n) - a[a.size()-1] == t){
            cout << "Yes";
        }else{
            cout << "No";
        }
        return;
    }

    //handle begin
    ll miss = 0;
    ll the_dif;
    for(int i = 0; i < a.size(); i++){
        int dif = a[i] - (i > 0 ? a[i-1] : 0);
        if(mp.find(dif) == mp.end()){
            miss++;
            the_dif = dif;
        }else{
            mp.erase(mp.find(dif));
        }
    }

    if(miss != 1){
        cout << "No";
        return;
    }

    long long t = 0;
    for(auto i : mp)
        t+=i;
    if(t == the_dif)
        cout << "Yes";
    else
        cout << "No";
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
