//wecu's template -- works with c++20

#include <bits/stdc++.h>
#define forn(n) for(int i = 0; i < n; i++)
#define endl '\n'

typedef long long ll;
using namespace std;

void pc(auto& c){for_each(c.begin(), c.end(), [](auto u){cout << u << " ";});}

void solution(){
    int n; cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        
        ans += a;
        ans += a/10;
        
        if(a%10)
            ans+=1;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    cin >> tc;
    for(int i = 1; i <= tc; i++){
        cout << "Case #" << i << ": ";
        solution();
        cout << endl;
    }
}
