//wecu's template -- works with c++17

#include <bits/stdc++.h>
#include <cstddef>

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
    int n; string s;
    cin >> n >> s;

    bool a_win = false;
    bool b_win = false;

    for(int x = 1; x <= n; x++){
        int a_count = 0;
        int b_count = 0;
        int tot = 0;
        int last = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'A')
                a_count++;
            else
                b_count++;
            
            if(a_count == x || b_count == x){
                if(a_count > b_count){
                    last = 1;
                    tot++;
                }else{
                    last = -1;
                    tot--;
                }

                a_count = 0;
                b_count = 0;
            }
        }

        if(a_count == 0 && b_count == 0) {
            if(tot > 0 && last == 1){
                a_win = true;
            }

            if(tot < 0 && last == -1){
                b_win = true;
            }
        }
    }

    if(a_win == b_win){
        cout << "?";
    }else if(a_win){
        cout << "A";
    }else{
        cout << "B";
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
