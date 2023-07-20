//wecu's template -- works with c++20

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
#define vi vector<int>
#define pi pair<int, int>

typedef long long ll;
using namespace std;

//void pc(auto& c){for_each(c.begin(), c.end(), [](auto u){cout << u << " ";});}

struct cmp {
   bool operator()(const pi& a, const pi& b) const {
        return a.second < b.second;
    }
};

void solution(){
    int n, k; cin >> n >> k;
    vector<vector<pi>> ln((2*1e5)+1);
    forn(n){
        int a, b;
        cin >> a >> b;
        ln[a].push_back({i+1, b});
    }

    cmp comp;

    vector<int> ans;
    multiset<pi, cmp> ends; //<index, end
    for(int i = 1; i <= 2*1e5; i++){
        //insert into set
        for(pi j : ln[i])
            ends.insert(j);
        
        //Remove ended
        while(ends.size() > 0 && ends.begin()->second < i){
            ends.erase(ends.begin());
        }

        //Remove overlaps
        while(ends.size() > k){
            auto t = max_element(ends.begin(), ends.end(), comp);
            ans.push_back(t->first);
            ends.erase(t);
        }
    }
    
    cout << ans.size() << endl;
    for(int i : ans)
        cout << i << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    //cin >> tc;
    for(int i = 1; i <= tc; i++){
        solution();
        cout << endl;
    }
}
