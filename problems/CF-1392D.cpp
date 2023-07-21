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
    int n;
    cin >> n;
    string a;
    cin >> a;

    vector<int> chunks = {1};
    for(int i = 1; i < a.size(); i++){
        if(a[i] != a[i-1]){
            chunks.push_back(1);
        }else {
            chunks[chunks.size()-1]++;
        }
    }

    if(a[0] == a[a.size()-1] && chunks.size() > 2){
        chunks[0] += chunks[chunks.size()-1];
        chunks.pop_back();
    }

    int ans = 0;

    if(chunks.size() == 1){
        ans++;
        chunks[0]--;
        chunks.push_back(1);
    }

    for(int i : chunks){
        i--;
        ans += i/3;
        if(i%3 == 2){
            ans++;
        }
    }

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
