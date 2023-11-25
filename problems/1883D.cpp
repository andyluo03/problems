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
    int q; cin >> q;
    
    multiset<int> highs;
    multiset<int, std::greater<int>> lows;
    bool valid = true;

    forn(q){
        char operation; cin >> operation;

        if(operation == '+'){
            int s, e; cin >> s >> e;
            highs.insert(e);
            lows.insert(s);
        }else{
            int s, e; cin >> s >> e;
            highs.erase(highs.find(e));
            lows.erase(lows.find(s));
        }
        
        if(*highs.begin() >= *lows.begin()){
            cout << "NO";
        }else{
            cout << "YES";
        }

        cout << endl;
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
