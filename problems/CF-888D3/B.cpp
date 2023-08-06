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

void solution(){
    int n; cin >> n;
    vector<int> a(n);
    forn(n){cin >> a[i];}

    vector<int> odds;
    vector<int> evens;

    forn(n){
        if(a[i] % 2){
            odds.emplace_back(a[i]);
        }else {
            evens.emplace_back(a[i]);
        }
    }

    sort(odds.begin(), odds.end(), greater<int>());
    sort(evens.begin(), evens.end(), greater<int>());

    forn(n){
        if(a[i]%2){
            a[i] = odds[odds.size()-1];
            odds.pop_back();
        }else{
            a[i] = evens[evens.size()-1];
            evens.pop_back();
        }
    }

    for(int i = 1; i < a.size(); i++){
        if(a[i] < a[i-1]){
            cout << "No";
            return;
        }
    }

    cout << "Yes";
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
