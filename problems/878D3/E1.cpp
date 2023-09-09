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
    vector<string> s(2);
    cin >> s[0] >> s[1];

    int t, q; cin >> t >> q;

    int d = 0; //# of differences

    for(int i = 0; i < s[0].size(); i++){
        if(s[0][i] != s[1][i])
            d++;
    }

    map<int, set<int>> unblock; //unblock[time] = set of numbers to unblock
    vector<int>        i_unblock(q, -1); //i_unblock[pos] = time when pos will be unblocked!
    vector<bool>       blocked(q+1, false);

    int time = 0;

    while(q > 0){
        int type; cin >> type;

        //unblock task
        for(auto i : unblock[time]){
            if(s[0][i] != s[1][i])
                d++;
            blocked[i] = false;
        } 

        if(type == 1){
            int pos; cin >> pos; pos--;
            if(!blocked[pos] && s[0][pos] != s[1][pos]){
                d--;
            }

            if(i_unblock[pos] != -1)
                unblock[i_unblock[pos]].erase(pos);
            
            unblock[time+t].insert(pos);
            i_unblock[pos] = time + t;
        }else if(type == 2){
            
        }else{
            if(d == 0)  
                cout << "YES";
            else
                cout << "NO";
            cout << endl;
        }
        time++;
        q--;
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
