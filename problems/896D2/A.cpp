//wecu's template -- works with c++17

#include <bits/stdc++.h>

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
    vi a(n);
    forn(n){cin >> a[i];}
    //each segment xor itself ? ELEMENT BOUNDED BY 100 !!!

    if(n % 2 == 0){
        cout << 2 << endl;
        cout << 1 << " " << n << endl;
        cout << 1 << " " << n;
        return;
    }

    cout << 4 << endl;
    cout << 1 << " " << n << endl; //all equal
    cout << 1 << " " << 2 << endl; //two zeros;
    cout << 2 << " " << 3 << endl;
    cout << 1 << " " << n;
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
