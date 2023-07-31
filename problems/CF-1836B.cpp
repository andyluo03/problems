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
        ll n, k, g; cin >> n >> k >> g;
     
        ll l = 0; 
        ll h = k; //how many assignments!
        ll ans = 0;
        ll target = n * (((g-1)/2)); //most possible!
     
        while(l <= h){
            ll m = l + (h-l)/2; //searching additions
            ll left_over = (k*g) - m*g;
     
            if(left_over <= target){
                h = m-1;
                ans = max(ans, left_over);
            }else{
                l = m+1;
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