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

void solution(){
    int n; cin >> n;
    vvi a(1);
    forn(n){
        int t; cin >> t;
        a[a.size()-1].push_back(t);
        if(t == 0 && i != n-1)
            a.push_back({});
    }

    reverse(a.begin(), a.end());

    if(a[0][a[0].size()-1] != 0){
        cout << "NO";
        return;
    }

    vi ans;

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[i].size()-1; j++){
            ans.push_back(0);
        }
        ans.push_back(a[i].size()-1);
    }

    cout << "YES" << endl;
    for(int i : ans)
        cout << i << ' ';
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
