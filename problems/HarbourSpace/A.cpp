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
    int x, y, n; cin >> x >> y >> n;

    vector<int> a(n);
    a[0] = y;
    int mn = 1;

    for(int i = 1; i < n-1; i++){
        a[i] = a[i-1] - mn;
        mn++;
    }

    a[n-1] = x;

    if(a[n-2] - a[n-1] < mn){
        cout << -1;
        return;
    }

    reverse(a.begin(), a.end());

    for(auto i : a){
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
