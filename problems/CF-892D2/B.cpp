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

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

void solution(){
    int n, m, d; cin >> n >> m >> d;
    //m does NOT exceed 10^5 (log n query for time + remove each one?)
    vi stands(m);
    forn(m){
        cin >> stands[i];
    }

    int cookies_no_removal = 1;
    int last = 1;

    for(int i = 0; i < stands.size(); i++){
        if(stands[i] == 1)
            continue;
        cookies_no_removal++; //eat at the stand!
        cookies_no_removal += (stands[i] - last - 1)/d; //eaten along the way
        last = stands[i];
    }

    cookies_no_removal += (n - last)/d;

    int cnt1 = 0;
    int cnt2 = 0;
    
    for(int i = 0; i < stands.size(); i++){
        int cur = stands[i];
        if(cur == 1){
            cnt1++;
            continue;
        }

        if(i == stands.size()-1){
            int removed = (n - stands[i-1])/d; //remove the -1 bcz 6 isn't a bench
            int kept = 1 + ((n-cur)/d) + (cur-stands[i-1]-1)/d;
            if(kept > removed){
                cnt2++;
            }else {
                cnt1++;
            }
            break;  
        }

        if(i == 0){
            int removed = (stands[i+1] - 1 - 1)/d;
            int kept = 1 + (cur - 1 - 1)/d + (stands[i+1]-cur-1)/d;
            if(kept > removed){
                cnt2++;
            }else {
                cnt1++;
            }
            continue;
        }


        int removed = (stands[i+1] - stands[i-1] - 1)/d;
        int kept = 1 + (cur - stands[i-1] - 1)/d + (stands[i+1] - cur - 1)/d;

        if(kept > removed){
            cnt2++;
        }else {
            cnt1++;
        }
    }

    if(cnt2){
        cout << cookies_no_removal-1 << " " << cnt2;
    }else{
        cout << cookies_no_removal << " " << cnt1;
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
