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
    string n; cin >> n;
    //greedily round up !
    int digit = INT_MAX; //this is the digit we fs round up from [!]
    
    for(int i = n.size(); i > 0; i--){
        if(n[i] >= '5'){ //not sure if we really need to catch 9's
            digit = i;
            n[i] = '0';
            n[i-1] += 1;
        }
    }

    if(n[0] >= '5'){
        cout << 1;
        forn(n.size()){
            cout << 0;
        }
        return;
    }

    forn(n.size()){
        if(i >= digit)
            cout << '0';
        else
            cout << n[i];
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
