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
#include <cstdlib>
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

bool is_permutation(string& s){
    if(s.size() != 10)
        return false;

    set<int> seen = {0,1,2,3,4,5,6,7,8,9};

    for(auto i : s){
        int z = i - '0';
        if(seen.find(z) == seen.end()){
            return false;
        }
        seen.erase(z);
    }

    return true;
}

void solution(){
    int x; cin >> x;
    for(int y = 0; y <= 100; y++){
        int a = (x+y) * (x+y);
        int b = (x+y) * a;
        string z = to_string(a) + to_string(b);

        if(is_permutation(z)){
            cout << y;
            return;
        }
    }
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
