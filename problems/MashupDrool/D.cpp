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

    //only look at characters *lower* than first, others will get "caught"

    int highest = 'a';
    int left_over = 0;
    
    if(k >= 26){
        for(int i = 0; i < s.size(); i++)
            cout << 'a';
        return;
    }

    char lowest = 'a';
    char bad    = 'a';
    char add    = 'a';
    bool flag   = true;
    for(int i = 0; i < s.size(); i++){
        if(flag){
            if(s[i] <= lowest){
                cout << 'a';
            }else{
                if(s[i] - lowest > k){
                    bad = s[i];
                    add = bad-k;
                    flag = false;
                    cout << add;
                }else{
                    k -= (s[i]-lowest);
                    lowest = s[i];
                    cout << 'a';
                }
            }
        }else{
            if(s[i] <= lowest){
                cout << 'a';
            }else if (s[i] <= bad){
                cout << (char)min(add, s[i]);
            }else{
                cout << s[i];
            }
        }
    }

    cout << endl;
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
