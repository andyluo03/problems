//wecu's template -- works with c++17

#include <algorithm>
#include <bitset>
#include <climits>
#include <cstddef>
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

void solution(){
    int n; cin >> n;
    vector<pi> a(n);
    forn(n){
        int t; cin >> t;
        a[i] = {t, i+1};
    }

    sort(a.begin(), a.end());
    map<int, int> dif;
    for(int i = 1; i < a.size(); i++)
        dif[a[i].first - a[i-1].first]++;

    for(int i = 0; i < a.size(); i++){
        if(i == 0){
            int d = a[i+1].first - a[i].first;
            dif[d]--;
            if(dif[d] == 0)
                dif.erase(dif.find(d));
            if(dif.size() == 0){
                cout << a[i].second;
                return;
            }
            dif[d]++;
        }

        if(i == a.size()){
            int d = a[i].first - a[i-1].first;
            dif[d]--;
            if(dif[d] == 0)
                dif.erase(dif.find(d));
            if(dif.size() == 0){
                cout << a[i].second;
                return;
            }
            dif[d]++;
        }

        int df = a[i].first - a[i-1].first;
        int db = a[i+1].first - a[i].first;
        int cb = a[i+1].first - a[i-1].first;
        dif[df]--;
        dif[db]--;
        if(dif[df] == 0)
            dif.erase(dif.find(df));
        if(dif[db] == 0)
            dif.erase(dif.find(db));
        dif[cb]++;
        if(dif.size() == 0){
            cout << a[i].second;
            return;
        }
        dif[df]++;
        dif[db]++;
        dif[cb]--;
        if(dif[cb] == 0)
            dif.erase(dif.find(cb));
    }

    cout << -1;
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
