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
    //# of edges !
    int n, m; cin >> n >> m;
    vector<int> edges(n+1);

    forn(m){
        int a, b; cin >> a >> b;
        edges[a-1]++;
        edges[b-1]++;
    }

    map<int, int> cnt;

    forn(n){
        if(edges[i] == 1) continue;
        cnt[edges[i]]++;
    }

    if(cnt.size() == 1){
        cout << cnt.begin()->first << " " << cnt.begin()->first-1;
    }else{
        int a;
        int b;
        for(auto i : cnt){
            if(i.second == 1){
                a = i.first;
            }else{
                b = i.first-1;
            }
        }

        cout << a << " " << b;
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
