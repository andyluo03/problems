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
    int n, k, x; cin >> n >> k >> x;

    if(x != 1){
        cout << "YES" << endl;
        cout << n << endl;
        for(int i = 0; i < n; i++){
            cout << "1 ";
        }
        return;
    }

    if(k == 1 && x == 1){ 
        cout << "NO";
        return;
    }

    if(k == 2 && x == 1){
        if(n % 2){
            cout << "NO";
            return;
        }else{
            cout << "YES" << endl;
            cout << n/2 << endl;
            while (n > 0) {
                cout << 2 << " ";
                n-=2;
            }
            return;
        }
    }

    if(n % 2 == 0){
        cout << "YES" << endl;
        cout << n/2 << endl;
        while (n > 0) {
            cout << 2 << " ";
            n-=2;
        }
        return;
    }

    cout << "YES" << endl;
    cout << n/2 << endl;

    while(n > 3){
        cout << 2 << " ";
        n-=2;
    }

    cout << 3;
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
