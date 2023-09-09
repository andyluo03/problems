#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long ;

template <ull N>
bool is_prime(){
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q; cin >> q;

    while(q--){
        long long n; cin >> n;
        if(is_prime(n)){
            cout << "Yes";
        }else{
            cout << "No";
        }
        cout << "\n";
    }

    return 0;
}