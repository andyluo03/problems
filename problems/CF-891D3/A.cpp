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
    int sum = 0;
    vi a(n);
    forn(n){
        cin >> a[i];
        sum += a[i];
    }

    if(sum % 2){
        cout << "NO";
        return;
    }

    cout << "YES";
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