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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int b_cnt = 0;

    forn(s.size()){
        if(s[i] == 'B')
            b_cnt++;
    }

    if(b_cnt == k){
        cout << 0;
        return;
    }

    int b_cc = 0;
    forn(s.size()){
         if(s[i] == 'B')
            b_cc++;
        
        //set all A's
        if(b_cnt - b_cc == k){
            cout << 1 << endl;
            cout << (i+1) << " A";
            return;
        }

        //set all B's
        if((i+1) - b_cc + b_cnt == k){
            cout << 1 << endl;
            cout << (i+1) << " B";
            return;
        }


    }

    cout << 2; //absolute worst case!
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
