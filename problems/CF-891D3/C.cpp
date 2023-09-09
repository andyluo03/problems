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

int count (int cnt, int left) {
    //could bsearch tbh ...
    int ans = 0;
    int sum = 0;
    int add = left-1;

    while(sum < cnt){
        sum += add;
        add--;
        ans++;
    }

    return ans;
}

void solution(){
    int n; cin >> n;
    int t = (n * (n-1))/2;
    map<int, int> mp; //counter
    vi b(t); forn(t){
        cin >> b[i];
        mp[b[i]]++;
    }

    for(auto i : mp){
        int c = i.first;
        int occ = count(i.second, n);
        forn(occ){
            cout << c << " ";
        }
        n -= occ;
    }

    while(n > 0){
        cout << ((int) 1e9) << " "; //t should only leave behind one!
        n--;
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
