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

typedef long long ll;
using namespace std;

//void pc(auto& c){for_each(c.begin(), c.end(), [](auto u){cout << u << " ";});cout<<endl;}

void solution(){
    int n; cin >> n;
    vector<int> a(n);
    forn(n) {cin >> a[i];}

    vector<int> p(n);
    vector<int> s(n);

    for(int i = 1; i < n; i++){
        int prev = p[i-1];
        if(a[i] > a[prev] - (i - prev))
            p[i] = i;
        else
            p[i] = p[i-1];
    }

    s[s.size()-1] = s.size()-1;
    for(int i = s.size()-2; i >= 0; i--){
        int prev = s[i+1];
        if(a[i] > a[prev] - (prev - i))
            s[i] = i;
        else
            s[i] = s[i+1];
    }

    int ans = 0;
    for(int i = 1; i < a.size()-1; i++){
        int l = p[i-1];
        int r = s[i+1];
        ans = max(ans, a[i] + a[l] + a[r] - (r-l));
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    cin >> tc;
    for(int i = 1; i <= tc; i++){
        solution();
        cout << endl;
    }
}
