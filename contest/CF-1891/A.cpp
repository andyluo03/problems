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

bool check(vector<int>& a, int s){
    int e = s*2-1;
    for(int i = s+1; i <= min(e, static_cast<int>(a.size())-1); i++){
        if(a[i] < a[i-1]){
            return false;
        }   
    }
    return true;
}

void solution(){
    int n; cin >> n;
    vector<int> a(n);
    forn(n){cin >> a[i];}

    int p2 = 1;

    while(p2 < a.size()){
        if(!check(a, p2)){
            cout << "NO";
            return;
        }

        p2*=2;
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
