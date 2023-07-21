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

bool helper(int n, int target){
    if(n == target) return true;
    if(n%3 != 0){return false;}
    if(n== 0) {return false;}
    
    return helper(n/3, target) || helper((n/3)*2, target);
}

void solution(){
    int n, m; cin >> n >> m;
    if(n<m){
        cout << "NO";
        return;
    }

    if(n==m){
        cout << "YES";
        return;
    }

    if(helper(n, m)){
        cout << "YES";
        return;
    }
    cout << "NO";
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
