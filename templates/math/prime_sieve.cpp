#include <vector>
#include <bitset>
#include <iostream>
#include <chrono>

const int MAX_N = 2e5;
std::vector<bool> sieve(MAX_N);
std::vector<int> primes;
void compute_sieve_2 () {
  for(int i = 2; i < sieve.size(); i++){
    if(!sieve[i]) continue;
    for(int j = i*i; j < sieve.size(); j+=i){
      sieve[j] = false;
    }
    primes.emplace_back(i);
  }
}
