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
    
int f(int x){
    if(x >= 1e8) return 9;
    else if(x >= 1e7) return 8;
    else if(x >= 1e6) return 7;
    else if(x >= 1e5) return 6;
    else if(x >= 1e4) return 5;
    else if(x >= 1e3) return 4;
    else if(x >= 1e2) return 3;
    else if(x >= 10) return 2;
    else return 1;
}
    
void solution(){
    int n; cin >> n;
    map<int, int> a; //counters !
    map<int, int> b;
    
    forn(n){
        int t; cin >> t;
        a[t]++;
    }
    
    forn(n){
        int t; cin >> t;
        if(a.find(t) != a.end()){
            a[t]--;

            if(a[t] == 0)
                a.erase(t);
        }else{
            b[t]++;
        }
    }
    
    vector<int> a_d(10);
    vector<int> b_d(10);
    int ans = 0;

    for(auto i : a){
        if(i.first >= 10){
            ans+=i.second;
            a_d[f(i.first)] += i.second;
        }else{
            a_d[i.first] += i.second;
        }
    }
    
    for(auto i : b){
        if(i.first >= 10){
            ans+=i.second;
            b_d[f(i.first)] += i.second;
        }else{
            b_d[i.first] += i.second;
        }
    }
    
    for(int i = 9; i > 1; i--){
        ans += abs(a_d[i] - b_d[i]);
        //a_d[1] += max(0, a_d[i]-b_d[i]);
        //b_d[1] += max(0, b_d[i]-a_d[i]);
    }

    pv(a_d);
    pv(b_d);
    
    
    cout << ans;
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