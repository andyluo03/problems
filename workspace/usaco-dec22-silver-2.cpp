//wecu's template -- works with c++17

#include <bits/stdc++.h>

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

const int MAX_N = 5e6 + 1;
std::vector<bool> sieve(MAX_N, true);
int best_p[] = {2,1,2,3};
int min_moves[MAX_N];
void compute_sieve_2 () {
  for(int i = 2; i < sieve.size(); i++){
    if(sieve[i]){
        for(int j = i*2; j < sieve.size(); j+=i){
            sieve[j] = false;
        }
        best_p[i%4] = i;
    }

    min_moves[i] = (i - best_p[i%4])/2 + 1;
  }
}

void solution(){
    int n; cin >> n;

    int mm = INT_MAX;

    forn(n){
        int t; cin >> t;
        
        if(min_moves[t] / 2 < mm / 2){
            mm = min_moves[t];
        }
    }

    //output answer
    if(mm%2 == 1){
        cout << "Farmer John";
    }else{
        cout << "Farmer Nhoj";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    compute_sieve_2();
    int tc = 1;
    cin >> tc;
    for(int i = 1; i <= tc; i++){
        solution();
        cout << endl;
    }
}
