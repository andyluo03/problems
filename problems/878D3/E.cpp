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
    string a, b;
    cin >> a >> b;
    int t, q; cin >> t >> q;

    int diff = 0;

    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i])
            diff++;
    }

    vector<bool> blocked(a.size(), false);
    vector<set<int>> unblock(a.size());
    vector<int> r_ub(a.size(), -1);

    int c_time = 0;
    while(q--){
        int type; cin >> type;

        //unblocking task !
        for(auto i : unblock[c_time]){
            blocked[i] = false;
            if(a[i] != b[i])
                diff++;
            r_ub[i] = -1; //no more blockers
        }

        if(type == 1){
            //DONE
            int pos; cin >> pos;
            blocked[pos] = true; //NEED TO ENSURE FOR REPEATS !!
            if(c_time + t + 2 < unblock.size())
                unblock[c_time + t + 2].insert(pos);
            if(r_ub[pos] != -1){
                unblock[r_ub[pos]].erase(pos);
            }
            r_ub[pos] = c_time + t;
            if(a[pos] != b[pos])    
                diff--;
        }else if(type == 2){
            int s_one, pos_one, s_two, pos_two;
            cin >> s_one >> pos_one >> s_two >> pos_two;
            pos_one--;
            pos_two--;

            if(s_one == s_two && pos_one == pos_two)    
                continue;

            string& t_one = (s_one == 1) ? a : b;
            string& i_one = (s_one == 1) ? b : a;
            string& t_two = (s_two == 1) ? a : b;
            string& i_two = (s_two == 1) ? b : a;

            if(t_one[pos_one] == t_two[pos_two])
                continue;
            
            if(pos_one == pos_two){
                swap(t_one[pos_one], t_two[pos_two]);
                continue;
            }
        
            if(t_one[pos_one] != i_one[pos_one])
                diff--;

            if(t_two[pos_two] != i_two[pos_two])
                diff--;

            if(t_one[pos_one] != i_one[pos_two])
                diff++;
            if(t_two[pos_two] != i_two[pos_two])
                diff++;

            swap(t_one[pos_one], t_two[pos_two]);
        }else{
            //DONE
            cout << diff << " ";
            if(diff == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

        c_time++;
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
