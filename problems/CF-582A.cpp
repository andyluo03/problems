#include <bits/stdc++.h>
#define forn(n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
template<class T>
void pvec(vector<T> v){for(auto a : v) cout << a << " ";}

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

void solution(){
    
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