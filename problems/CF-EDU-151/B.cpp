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

bool negative(ll n){
    if(n < 0)
        return true;
    return false;
}

void solution(){
    ll Ax, Ay, Bx, By, Cx, Cy;
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;
    //ABC are distinct

    ll dxB = Ax - Bx;
    ll dyB = Ay - By;
    ll dxC = Ax - Cx;
    ll dyC = Ay - Cy;

    ll sameX = 0;
    ll sameY = 0;

    if(negative(dxB) == negative(dxC)){
        sameX = min(abs(dxB), abs(dxC));
    }

    if(negative(dyB) == negative(dyC)){
        sameY = min(abs(dyB), abs(dyC));
    }

    cout << (sameX + sameY + 1);    
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
