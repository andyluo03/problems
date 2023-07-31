#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

const int MOD = (int) 1e9 + 7;
const int max_n   = (int) 1e5;

vector<int> fact(max_n + 1);

void pc_fact () {
    fact[1] = 1;
    for(int i = 2; i < fact.size(); i++)
        fact[i] = ((long long) fact[i-1] * (long long) i) % MOD;
}

long long mod_pow (int a, int b) {
    long long ans = 1;
    long long prev = a%MOD;
    while (b) {
        if(b & 1){
            ans = ((long long) ans * prev) % MOD;
        }
        prev = (prev*prev)%MOD;
        b>>=1;
    }
    return ans;
}

int mod_inv (int n) {
    return mod_pow(n, MOD-2);
}

int ncr (int n, int r) {
    long long a = fact[n];
    long long b = mod_inv(fact[n-r]);
    long long c = mod_inv(fact[r]);
    return (((a * b)%MOD)*c)%MOD;
}

int main () {
    pc_fact();
    cout << ncr(1000, 32);
}