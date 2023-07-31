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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    forn(n){cin >> a[i];}

    int c1 = a[0];
    int c2 = a[n-1];

    int l  = n-1;
    int h  = 0;

    int c1_cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == c1){
            c1_cnt++;
        }

        if(c1_cnt == k){
            l = i;

            if(c1 == c2){
                cout << "Yes";
                return;
            }
            break;
        }
    }

    int c2_cnt = 0;
    for(int i = n-1; i >= 0; i--){
        if(a[i] == c2){
            c2_cnt++;
        }

        if(c2_cnt == k){
            h = i;
            break;
        }
    }

    if(l < h)
        cout << "Yes";
    else
        cout << "No";
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
