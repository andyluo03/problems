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
    vector<int> a(n);
    int negs = 0;
    int poss = 0;
    int mn = INT_MAX;
    int mx = INT_MIN;
    int mni = -1;
    int mxi = -1;
    forn(n){
        cin >> a[i];
        if(a[i] < 0)
            negs++;
        if(a[i] > 0)
            poss++;
        if(a[i] > mx)
            mni = i;
        if(a[i] < mn)
            mxi = i;
        mx=max(mx, a[i]);
        mn=min(mn, a[i]);
    }

    if(negs == 0 && poss == 0){
        cout << 0; //it's all zeros!
        return;
    }

    int count = 50;
    cout << 50 << endl; //we only need this much

    if(negs > poss){
        while(a[mni] > -20){
            a[mni] *= 2;
            cout << mni+1 << " " << mni+1 << endl;
            count--;
        }

        for(int i = 0; i < a.size(); i++){
            if(a[i] > 0){
                a[i] += a[mni];
                cout << i+1 << " " << mni+1 << endl;
                count--;
            }
        }

        for(int i = a.size()-2; i >=0; i--){
            if(a[i] > a[i+1]){
                a[i] += a[i+1];
                cout << i+1 << " " << i+2;
                count--;
            }
        }
    }else{
        while(a[mxi] < 20){
            a[mxi]*=2;
            cout << mxi+1 << " " << mxi+1 << endl;
            count--;
        }

        for(int i = 0; i < a.size(); i++){
            if(a[i] < 0){
                a[i] += a[mxi];
                cout << i+1 << " " << mxi+1 << endl;
                count--;
            }
        }

        for(int i = 1; i < a.size(); i++){
            if(a[i] > a[i-1]){
                a[i] += a[i-1];
                cout << i+1 << " " << i << endl;
                count--;
            }
        }
    }


    //fill out rest !
    
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
