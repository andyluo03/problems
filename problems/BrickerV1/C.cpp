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
    int n; cin >> n;
    vector<pi> a(n);
    vector<pi> b(n);
    forn(n){cin >> a[i].first; a[i].second = i;}
    forn(n){cin >> b[i].first; b[i].second = i;}

    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());

    int odd_cnt = 0;
    set<int> valid;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]){
            valid.insert(a[i].second);
        }else{
            for(int j = 0; j < 2; j++){
                int t = j == 0 ? a[i].second : b[i].second;
                if(valid.find(t) != valid.end()){
                    odd_cnt--;
                }else{
                    odd_cnt++;
                }
                valid.insert(t);
            }
        }

        if(odd_cnt == 0)
            break;
    }

    forn(n){
        if(valid.find(i) != valid.end())
            cout << 1;
        else
            cout << 0;
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
