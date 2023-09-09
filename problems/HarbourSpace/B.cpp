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
    int n, k; cin >> n >> k;
    string s; cin >> s;


    //except for last bit!
    if(k % 2 == 0){
        //check if this works
        sort(s.begin(), s.end());
        cout << s;
        return;
    }else{
        string a = "";
        string b = "";
        for(int i = 0; i < s.size(); i++){
            if(i%2 == 0)
                a+=s[i];
            else
                b+=s[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                cout << a[i/2];
            }else{
                cout << b[i/2];
            }
        }
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
