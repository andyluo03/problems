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
    int n; cin >> n; //size of initial array
    vector<ll> a(n-1);
    set<ll> unseen;
    forn(n-1){cin >> a[i];}

    if(n == 2){
        if(a[0] == 1 || a[0] == 2){
            cout << "Yes";
        }else{
            cout << "No";
        }

        return;
    }

    forn(n){unseen.insert(i+1);}

    ll bad_dif = -1;

    for(int i = 0; i < a.size(); i++){
        if(i != 0 && a[i] < a[i-1]){ 
            cout << "No";
            return;
        }

        if(i == 0){
            if(unseen.find(a[0]) != unseen.end()){
                unseen.erase(unseen.find(a[0]));
            }else{
                bad_dif = a[0];
            }
            continue;
        }

        if(i == a.size()-1){
            if(bad_dif != -1 && a[i] != tot(n)){
                cout << "No";
                return;
            }

            if(a[i] != tot(n)){
                bad_dif = tot(n) - a[i];

                if(a[i] > tot(n)){
                    cout << "No";
                    return;
                }
            }
        }

        int dif = a[i] - a[i-1];

        if(unseen.find(dif) != unseen.end()){
            unseen.erase(dif);
        }else{
            if(bad_dif != -1){
                cout << "No";
                return;
            }else{
                bad_dif = dif;
            }
        }
    }
    
    ll t_sum = 0;
    for (auto i : unseen) {
        t_sum += i;
    }

    if(t_sum == bad_dif){
        cout << "Yes";
    }else{
        cout << "No";
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
