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

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

int score(vi a){
    set<int> seen;
    for(int i = 0; i < a.size()-1; i++){
        seen.insert(gcd(a[i], a[i+1]));
    }
    seen.insert(gcd(a[a.size()-1], a[0]));
    return seen.size();
}

void solution(){
    int n; cin >> n;

    set<int> ok;
    for(int i = 1; i <= n; i++)
        ok.insert(i);
    vector<int> ans;

    while(ok.size()){
        ans.push_back(*ok.begin());
        int t = 2 * (*ok.begin());
        ok.erase(ok.begin());
        while(ok.find(t) != ok.end()){
            ans.push_back(t);
            ok.erase(t);
            t*=2;
        }
    }

    for(auto i : ans)
        cout << i << " ";
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
