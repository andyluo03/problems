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

struct portal {
    int id;
    int start;
    int end;
};

struct cmp {
    bool operator()(portal& a, portal& b){
        return a.start < b.start;
    }
};

void solution(){
    //Sweep line + Binary search ! (add repeats for ranges!)
    int n; cin >> n;
    vector<portal> p(n);
    forn(n){
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        p.push_back({i, l, b});
    }

    sort(p.begin(), p.end(), cmp());

    //sweep dat line :D
    vector<pi> merged;

    int start = p[0].start;
    int end = p[0].end;
    for(int i = 1; i < p.size(); i++){
        if(p[i].start > end){
            merged.push_back({start, end});
            start = p[i].start;
            end = p[i].end;
        }else{
            end = max(end, p[i].end);
        }
    }

    merged.push_back({start, end});


    int q; cin >> q;
    forn(q){
        int t; cin >> t;

        /**
        int l = 0;
        int h = merged.size()-1;

        while(l <= h){
            int m = l + (h-l)/2;

            if(merged[m].first <= t && t <= merged[m].second){
                cout << merged[m].second;
                return;
            }

            if(merged[m].second < t){
                l = m+1;
            }else{
                h = m-1;
            }
        }
        **/
        for(auto j : merged){
            if(j.first <= t && j.second >= t){
                cout << j.second << " ";
                break;
            }
        }

        cout << t;
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
