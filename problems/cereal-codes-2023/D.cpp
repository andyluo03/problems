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

int dc(int n){
    int count = 0;
    while(n > 0){
         n/=2;
        count++;
    }
    return count-1;
}

void solution(){
    int n; cin >> n;
    vector<int> a(31);

    forn(n){
        int t; cin >> t;
        
        for(int i = 0; i < 31; i++){
            if(t%2){
                a[i]++;
            }
            t/=2;
        }
    }

    pv(a);
    
    for(int i = 30; i >= 0; i--){
        if(a[i] % 2){
            cout << (1 << i);
            return;
        }
    }
    
    cout << 0;
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
