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
    int n; cin >> n;
    ll k; cin >> k;
    vector<ll> a(n);
    ll sum = 0;

    forn(n){
        cin>>a[i];
        sum+=a[i];
    }

    sort(a.begin(), a.end());
    vector<ll> psum(n);

    for(int i = 1; i < psum.size(); i++)
        psum[i] += psum[i-1] + a[i];

    ll ans = max(sum - k, 0ll);

    for(int i = 1; i <= n-1; i++){
        ll t_ans = i; //set a[n-1]...a[n-i] to a[0]-subtracts
        ll t_sum = sum;
        t_sum += i * a[0]; //do setting !
        t_sum -= psum[n-1] - psum[n-i-1];
        t_ans += max(0ll, (t_sum - k)/(i+1));
        t_ans += (t_sum-k)%(i+1) && (t_sum-k) > 0 ? 1 : 0;
        
        ans = min(t_ans, ans);
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
